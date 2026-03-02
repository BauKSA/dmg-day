#ifndef _TEXTFRAME_
#define _TEXTFRAME_
#include <stdint.h>

#define text_frame_tileset_size 22
#define TEXT_FRAME_TILESET_START 180

extern const unsigned char text_frame_tileset[];

extern const unsigned char text_frame_tilemap[];

void TextFrame_Init(uint8_t width, uint8_t height);

#endif // _TEXTFRAME_