#ifndef ALL_SCENES_H
#define ALL_SCENES_H

enum AllScenes {
  MENU,
  STORY,
  GENDER_SELECT,
  INVENTORY,

  //MAPAS
  MAP_21,
  MAP_22,
  MAP_23,
  
  MAP_30,
  MAP_31,
  MAP_32,
  MAP_33,

  MAP_00,
  MG_LEAVES,
  NONE
};

extern enum AllScenes current_scene;
extern enum AllScenes prev_scene;

#endif // ALL_SCENES_H
