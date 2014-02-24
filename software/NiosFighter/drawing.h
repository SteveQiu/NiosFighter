#ifndef DRAWING_H_
#define DRAWING_H_
#include "render.h"
#include "audio.h"

void DrawStartScreen(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy,
		alt_up_char_buffer_dev* char_buffer_cpy, int x, int y, int w, int h);
void DrawInstruction(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy,
		alt_up_char_buffer_dev* char_buffer_cpy);
void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, int w, int h);
void DrawHealthBar(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y);
void DrawBlockBar(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y);
void DrawBlock1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm);
void DrawBlock2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm);
void DrawHit1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm);
void DrawHit2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		dirtyManager *dm);
void DrawStanding1p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding1p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding1p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding1p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding1p5(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding1p6(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding1p7(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding2p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding2p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding2p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding2p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding2p5(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding2p6(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawStanding2p7(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching1p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching1p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching1p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching1p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching2p1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching2p2(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching2p3(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawPunching2p4(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x,
		int y, dirtyManager *dm);
void DrawSomething(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		int w, int h, int a);
void DrawTimer(alt_up_char_buffer_dev* char_buffer_cpy, int);
void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate,
		dirtyManager *dm);
void DrawStanding1(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm);
void DrawStanding2(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm);
void DrawPunching1(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm);
void DrawPunching2(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm);

void DrawCharacter(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy,
		gameState *gstate, dirtyManager *dm);

#endif /* DRAWING_H_ */
