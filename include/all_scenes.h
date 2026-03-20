#ifndef ALL_SCENES_H
#define ALL_SCENES_H

enum AllScenes
{
  MENU,
  STORY,
  GENDER_SELECT,
  INVENTORY,
  LANG_SELECT,

  // MAPAS
  MAP_00,
  MAP_01,
  MAP_02,
  MAP_03,

  MAP_10,
  MAP_11,
  MAP_12,
  MAP_13,

  MAP_20,
  MAP_21,
  MAP_22,
  MAP_23,

  MAP_30,
  MAP_31,
  MAP_32,
  MAP_33,

  MG_LEAVES,
  MG_HOMEWORK,
  MG_FINAL,

  NONE
};

extern enum AllScenes current_scene;
extern enum AllScenes prev_scene;

#endif // ALL_SCENES_H
