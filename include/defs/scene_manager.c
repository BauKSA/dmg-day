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

void SceneManager_CleanScreen() {
  DISPLAY_OFF;
  HIDE_BKG;
  HIDE_SPRITES;

  vsync();

  position.y[player] = 0;
  draw_actor(player);

  for (uint8_t i = 0; i < 40; i++)
    move_sprite(i, 0, 0);

  vram_next_index = 0;
  vram_next_index = 27;
}

void SceneManager_Create(Game *game) {
  scene_manager.game = game;
  scene_manager.change_scene = SceneManager_ChangeScene;
}

void SceneManager_ChangeScene(enum AllScenes new_scene, Entity *player) {
  if (is_transitioning == 1)
    return;

  if (!scene_manager.game)
    return;

  is_transitioning = 1;

  SceneManager_CleanScreen();

  DISPLAY_ON;
  SHOW_BKG;
  SHOW_SPRITES;

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
