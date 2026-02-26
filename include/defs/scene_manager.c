#include <gb/gb.h>
#include <stddef.h>
#include <stdlib.h>

#include "../draw.h"
#include "../input.h"
#include "../npcs.h"
#include "../player.h"
#include "../position.h"
#include "../scene.h"
#include "../scene_manager.h"

SceneManager *scene_manager;

void SceneManager_CleanScreen() {
  DISPLAY_OFF;
  HIDE_BKG;
  HIDE_SPRITES;

  for (uint8_t i = 0; i < 40; i++)
    move_sprite(i, 0, 0);
}

void SceneManager_Create(Game *game) {
  scene_manager = (SceneManager *)malloc(sizeof(SceneManager));

  scene_manager->game = game;
  scene_manager->change_scene = SceneManager_ChangeScene;
}

void SceneManager_ChangeScene(enum AllScenes new_scene, Entity *player) {
  if (!scene_manager->game)
    return;

  if (scene_manager->game->current_scene &&
      scene_manager->game->current_scene->destroy)
    scene_manager->game->current_scene->destroy(
        scene_manager->game->current_scene);

  SceneManager_CleanScreen();

  DISPLAY_ON;
  SHOW_BKG;
  SHOW_SPRITES;

  scene_manager->game->current_scene = scene_manager_MapScene(new_scene);

  uint8_t previous_bank = _current_bank;
  if (scene_manager->game->current_scene->bank != _current_bank)
    SWITCH_ROM_MBC1(scene_manager->game->current_scene->bank);

  scene_manager->game->current_scene->init(scene_manager->game->current_scene,
                                           player);

  if (previous_bank != _current_bank)
    SWITCH_ROM_MBC1(previous_bank);

  keys = 0;
  prev_keys = 0;
}
