#include <gb/gb.h>

#include "../draw.h"
#include "../input.h"
#include "../load.h"
#include "../player.h"
#include "../position.h"
#include "../scene.h"
#include "../scene_manager.h"

SceneManager scene_manager;
uint8_t is_transitioning = 0;

void SceneManager_CleanScreen()
{
  DISPLAY_OFF;
  HIDE_BKG;
  HIDE_SPRITES;

  vsync();

  position.y[player] = 0;
  draw_actor(player);

  for (uint8_t i = 0; i < 40; i++)
    move_sprite(i, 0, 0);

  vram_next_index = 0;
  vram_extra_start = 27;
}

void SceneManager_Create(Game *game)
{
  scene_manager.game = game;
  scene_manager.change_scene = SceneManager_ChangeScene;
}

void SceneManager_ChangeScene(enum AllScenes new_scene, Entity *player)
{
  if (is_transitioning == 1)
    return;

  if (!scene_manager.game)
    return;

  is_transitioning = 1;

  if (scene_manager.game->current_scene != NULL && new_scene != INVENTORY)
  {
    Scene *old_scene = scene_manager.game->current_scene;

    // Guardamos el banco actual para no perdernos
    uint8_t _prev_bank_destroy = _current_bank;

    // Cambiamos al banco de la escena que se va y destruimos
    SWITCH_ROM_MBC1(old_scene->bank);

    if (old_scene->destroy != NULL)
    { // <--- Verificación de seguridad
      old_scene->destroy(old_scene);
    }

    // Volvemos al banco previo (opcional si vas a cambiar de banco inmediatamente después)
    SWITCH_ROM_MBC1(_prev_bank_destroy);
  }

  SceneManager_CleanScreen();

  DISPLAY_ON;
  SHOW_BKG;
  SHOW_SPRITES;

  prev_scene = current_scene;
  current_scene = new_scene;

  Scene *scene = scene_manager_MapScene(new_scene);
  uint8_t _prev_bank = _current_bank;
  SWITCH_ROM_MBC1(scene->bank);
  scene->init(scene, *player);

  scene_manager.game->current_scene = scene;

  vsync();

  if (_prev_bank != _current_bank)
    SWITCH_ROM_MBC1(_prev_bank);

  keys = 0;
  prev_keys = 0;

  is_transitioning = 0;
}
