#include "render.h"

void addDirty(dirtyManager *dm, int x, int y, int w, int h) {
	dirtySection *newSection = malloc(sizeof(dirtySection));
	initDirtySection(newSection);
	newSection->x = x;
	newSection->y = y;
	newSection->w = w;
	newSection->h = h;
	addDirtySection(dm, newSection);
}

//This function convert int into char array
void InttoChar(int time_remain, char* array) {
	if (time_remain > 99)
		exit(1);
	int n = time_remain;
	sprintf(array, "%02d", n);
}

int draw_pixel_fast(alt_up_pixel_buffer_dma_dev *pixel_buffer,
		unsigned int color, unsigned int x, unsigned int y) {
	unsigned int addr;

	addr = ((x & pixel_buffer->x_coord_mask) << 1);
	addr += (((y & pixel_buffer->y_coord_mask) * 320) << 1);

	IOWR_16DIRECT(pixel_buffer->back_buffer_start_address, addr, color);

	return 0;
}

//This function initializes the buffer needed for drawing to work.
void InitPixBuff(alt_up_pixel_buffer_dma_dev **pixel_buffer_ptr) {

	*pixel_buffer_ptr = alt_up_pixel_buffer_dma_open_dev(
			VIDEO_PIXEL_BUFFER_DMA_NAME);
	//Initialise the graphic buffer

	unsigned int pixel_buffer_addr1 = SRAM_BASE;
	unsigned int pixel_buffer_addr2 = SRAM_BASE + (512 * 240 * 2);

	// Set the 1st buffer address
	alt_up_pixel_buffer_dma_change_back_buffer_address(*pixel_buffer_ptr,
			pixel_buffer_addr1);
	//Set background for this buffer address
	alt_up_pixel_buffer_dma_clear_screen(*pixel_buffer_ptr, 1);
	DrawSomething(*pixel_buffer_ptr, 0, 0, COLUMN, ROW, 1);
	DrawSomething(*pixel_buffer_ptr, 14, 10, 126, 6, 2);
	DrawSomething(*pixel_buffer_ptr, 180, 10, 126, 6, 2);

	// Swap buffers –we have to swap because there is only an API function
	// to set the address of the background buffer.
	alt_up_pixel_buffer_dma_swap_buffers(*pixel_buffer_ptr);
	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(*pixel_buffer_ptr))
		;

	// Set the 2nd buffer address
	alt_up_pixel_buffer_dma_change_back_buffer_address(*pixel_buffer_ptr,
			pixel_buffer_addr2);
	DrawSomething(*pixel_buffer_ptr, 0, 0, COLUMN, ROW, 1);
	DrawSomething(*pixel_buffer_ptr, 14, 10, 126, 6, 2);
	DrawSomething(*pixel_buffer_ptr, 180, 10, 126, 6, 2);
}

//This function initializes the buffer needed for char printing
void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr) {
	*char_buffer_ptr = alt_up_char_buffer_open_dev(
			"/dev/video_character_buffer_with_dma");
	assert(*char_buffer_ptr);
	//Initialize the character buffer
	alt_up_char_buffer_init(*char_buffer_ptr);
}

void DrawSomething(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy, int x, int y,
		int w, int h, int a) {

	int row;
	int column;
	int realw = x + w;
	int realh = y + h;

	for (row = y; row < realh; row++) {
		for (column = x; column < realw; column++) {
			if (a == 1)
				draw_pixel_fast(pixel_buffer_cpy, bg1[row][column], column, row);
			else if (a == 2)
				draw_pixel_fast(pixel_buffer_cpy, hb[row - y][column - x],
						column, row);
		}
	}
}

void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate,
		dirtyManager *dm) {

	alt_up_pixel_buffer_dma_draw_box(HP_buffer_cpy, 15, 20,
			(gstate->player1.health * 1.4), 30, 0xF800, 1);
	int x_1 = 140 - (gstate->player1.health * 1.4);
	int y_1 = 20;
	int w_1 = 140 - x_1;
	int h_1 = 10;

	alt_up_pixel_buffer_dma_draw_box(HP_buffer_cpy, (320
			- gstate->player2.health * 1.4), 20, 310, 30, 0xF800, 1);

	int x_2 = 320 - 140;
	int y_2 = 20;
	int w_2 = 320 - gstate->player2.health * 1.4 - x_2;
	int h_2 = 10;

	addDirty(dm, x_1, y_1, w_1, h_1);
	addDirty(dm, x_2, y_2, w_2, h_2);
}

/*void DrawHP1(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate,
 dirtyManager *dm) {

 DrawSomething(pixel_buffer, dm->head->x, dm->head->y, dm->head->w,
 dm->head->h, 1);
 alt_up_pixel_buffer_dma_draw_box(HP_buffer_cpy, 15, 20,
 (gstate->player1.health * 1.4), 30, 0xF800, 1);
 int x_1 = 140 - (gstate->player1.health * 1.4);
 int y_1 = 20;
 int w_1 = 140 - x_1;
 int h_1 = 10;

 alt_up_pixel_buffer_dma_draw_box(HP_buffer_cpy, (320
 - gstate->player2.health * 1.4), 20, 310, 30, 0xF800, 1);

 int x_2 = 320 - 140;
 int y_2 = 20;
 int w_2 = 320 - gstate->player2.health * 1.4 - x_2;
 int h_2 = 10;

 addDirty(dm, x_1, y_1, w_1, h_1);
 addDirty(dm, x_2, y_2, w_2, h_2);
 }*/

//Draw the timer by giving a time in int, using inttochar to convert int
void DrawTimer(alt_up_char_buffer_dev* char_buffer_cpy, int time_remain) {
	// Write some text
	char time_char[3];
	InttoChar(time_remain, time_char);

	alt_up_char_buffer_string(char_buffer_cpy, " ", 38, 0);
	alt_up_char_buffer_string(char_buffer_cpy, time_char, 39, 0);
	alt_up_char_buffer_string(char_buffer_cpy, " ", 41, 0);
	//80*60 array across 320*280 resolution screen
}

void DrawCharacter(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate,
		dirtyManager *dm) {
	int playerColour = 0xF80F;
	if (gstate->player1.status == STATUS_STUNNED) {
		playerColour = 0x03FF;
	}

	alt_up_pixel_buffer_dma_draw_box(buffer_cpy, (gstate->player1.xPosition
			+ 160 - gstate->player1.width), 120, (gstate->player1.xPosition
			+ 160 + gstate->player1.width), 200, playerColour, 1);
	alt_up_pixel_buffer_dma_draw_box(buffer_cpy, (gstate->player1.xPosition
			+ 160), 140, (gstate->player1.xPosition + 160
			+ gstate->player1.fistDistance), 150, playerColour, 1);

	int x_1 = gstate->player1.xPosition + 160 - gstate->player1.width;
	int y_1 = 120;
	int w_1 = 2 * gstate->player1.width + gstate->player1.fistDistance + 1;
	int h_1 = 81;

	alt_up_pixel_buffer_dma_draw_box(buffer_cpy, (gstate->player2.xPosition
			+ 160 - gstate->player2.width), 120, (gstate->player2.xPosition
			+ 160 + gstate->player2.width), 200, 0x03FF, 1);

	//int x_2 = 310 - (320 - gstate->player2.health * 1.4);
	//int y_2 = 10;
	//int w_2 = gstate->player1.width;
	//int h_2 = 80;

	addDirty(dm, x_1, y_1, w_1, h_1);
	//addDirty(dm, x_2, y_2, w_2, h_2);
}

void render(gameState *state, alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer, dirtyManager *dm) {
	//clear screen
	//draw
	//swap buffer
	//check and wait for swap buffer
	//alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);
	//DrawBackground(pixel_buffer);
	//Invoke this function to draw background;
	while (dm->head != NULL) {
		DrawSomething(pixel_buffer, dm->head->x, dm->head->y, dm->head->w,
				dm->head->h, 1);
		//printf("%d,%d,%d,%d\n", dm->head->x, dm->head->y, dm->head->w,
		//dm->head->h);
		popDirtySection(dm);
	}

	//DrawHP(pixel_buffer, state, dm);
	//DrawHP1(pixel_buffer, state, dm);

	DrawTimer(char_buffer, getTimeRemaining(state));

	DrawCharacter(pixel_buffer, state, dm);

	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer))
		;
}
