#ifndef RENDER_H
#define RENDER_H
#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <altera_up_avalon_video_character_buffer_with_dma.h>
#include <assert.h>
#include "gameState.h"

char InttoChar(int time_remain);
void InitPixBuff(alt_up_pixel_buffer_dma_dev **pixel_buffer_ptr);
void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr);
void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy);
void DrawTimer(alt_up_char_buffer_dev* char_buffer_cpy, int);
void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy);
void DrawCharTest(alt_up_char_buffer_dev* char_buffer_cpy);
void render(gameState *state);


#endif //RENDER_H
