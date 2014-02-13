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
#include "dirtyRendering.h"

#define ROW 240
#define COLUMN 320

void addDirty(dirtyManager *dm, int x, int y, int w, int h);
void InttoChar(int time_remain, char*);
int draw_pixel_fast(alt_up_pixel_buffer_dma_dev *pixel_buffer,
		unsigned int color, unsigned int x, unsigned int y);
void InitPixBuff(alt_up_pixel_buffer_dma_dev **pixel_buffer_ptr);
void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr);
void DrawSomething(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		int w, int h, int a);
void DrawTimer(alt_up_char_buffer_dev* char_buffer_cpy, int);
void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate,
		dirtyManager *dm);
void DrawCharTest(alt_up_char_buffer_dev* char_buffer_cpy);
void render(gameState *state, alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer, dirtyManager *dm);
void DrawCharacter(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy,
		gameState *gstate, dirtyManager *dm);

#endif //RENDER_H
