#ifndef RENDER_H
#define RENDER_H
#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <altera_up_avalon_video_character_buffer_with_dma.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameState.h"
#include "materials.h"
#include "io.h"
#include "input.h"
#include "dirtyRendering.h"
#include "drawing.h"

void renderStartscreen(alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer, dirtyManager *dm, input * key, alt_up_ps2_dev * ps2);
void renderInstruction(gameState *state, alt_up_char_buffer_dev* char_buffer, alt_up_pixel_buffer_dma_dev *pixel_buffer);
void InttoChar(int time_remain, char*);
int draw_pixel_fast(alt_up_pixel_buffer_dma_dev *pixel_buffer, unsigned int color, unsigned int x, unsigned int y);
void InitPixBuff(alt_up_pixel_buffer_dma_dev **pixel_buffer_ptr);
void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr);
void render(gameState *state, alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer, dirtyManager *dm);

#endif //RENDER_H
