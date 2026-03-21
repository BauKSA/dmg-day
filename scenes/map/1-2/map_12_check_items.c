#pragma bank 2

#include "map_12.h"
#include "map_12_collision.h"

#include "../../../include/inventory.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/position.h"
#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/language.h"
#include "../../../include/music.h"

#include "../item_no_use.h"

#include <stdint.h>

const DialoguePerRelation dialogue_01_12_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"guau, guau!", ""}, {"guau, guau!", ""}, {"guau, guau!", ""}},
};

const DialoguePerRelation dialogue_01_12_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"woof, woof!", ""}, {"woof, woof!", ""}, {"woof, woof!", ""}},
};

void Map_12_CheckItems()
{
    if (active_item == 0)
        return;

    active_item = 0;

    if (CurrentMapData.event_active != 1)
    {
        ItemNoUseText();
        return;
    }

    uint8_t correct = 0;
    for (uint8_t i = 0; i < MAX_ITEMS; i++)
    {
        if (active_item_index == i && inventory[i].item == BRANCH)
        {
            correct = 1;
            inventory[i].item = ITM_NONE;
        }
    }

    if (correct == 0)
    {
        ItemNoUseText();
        return;
    }

    relation_stats[(uint8_t)NPC_FIRULAIS]++;

    if (language == ENGLISH)
        CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_12_en;
    else
        CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_12_es;

    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_FIRULAIS, 0, 0, NONE);

    set_animation(&animation[npc_1], 1);

    while (position.x[npc_1] > 20)
    {
        vsync();
        update_animation(&animation[npc_1]);
        position.x[npc_1]--;

        draw_actor(npc_1);
    }

    position.y[npc_1] = 0;

    set_animation(&animation[npc_1], 0);
    update_animation(&animation[npc_1]);

    draw_actor(npc_1);

    map_12_collision[7][10] = 0;
    map_12_collision[8][10] = 0;
    map_12_collision[9][10] = 0;

    dog_active = 0;
    Woof();
}