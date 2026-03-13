#pragma bank 6
#include <gb/gb.h>

#include "mini_games.h"

#include "../../include/huge/include/hUGEDriver.h"
#include "../../assets/music/songs.h"

void Mg_PlayMain()
{
    hUGE_init(&mg_main_music);
}

void Mg_PlayEndMusic(uint8_t win, uint8_t loop)
{
    return;
}

void Mg_StopMusic()
{
    hUGE_init(0);
    hUGE_mute_channel(HT_CH1, HT_CH_MUTE);
    hUGE_mute_channel(HT_CH2, HT_CH_MUTE);
    hUGE_mute_channel(HT_CH3, HT_CH_MUTE);
    hUGE_mute_channel(HT_CH4, HT_CH_MUTE);
}