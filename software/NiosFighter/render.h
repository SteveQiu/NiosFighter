#ifndef RENDER_H
#define RENDER_H
#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <altera_up_avalon_video_character_buffer_with_dma.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "gameState.h"
#include "materials.h"

void InttoChar(int time_remain,char**);
void InitPixBuff(alt_up_pixel_buffer_dma_dev **pixel_buffer_ptr);
void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr);
void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy);
void DrawBackground1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy);
void DrawTimer(alt_up_char_buffer_dev* char_buffer_cpy, int);
void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate);
void DrawCharTest(alt_up_char_buffer_dev* char_buffer_cpy);
void render(gameState *state,alt_up_char_buffer_dev* char_buffer,alt_up_pixel_buffer_dma_dev *pixel_buffer);
void DrawCharacter(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate);
void DrawF(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate);

#endif //RENDER_H
