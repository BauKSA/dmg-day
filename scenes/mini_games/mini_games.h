#ifndef _MINIGAMES_
#define _MINIGAMES_

#define MAX_SIZE_MG_TITLE 12

#define MUSIC_BANK 7

void Mg_SetTitle(char title[MAX_SIZE_MG_TITLE]);
void Mg_PlayMain();
void Mg_PlayEndMusic(uint8_t win, uint8_t loop);
void Mg_StopMusic();

#endif //_MINIGAMES_