#include "render.h"

//This function convert int into char array
void InttoChar(int time_remain, char* array) {
	if (time_remain > 99)
		exit(1);
	int n = time_remain;
	sprintf(array, "%02d", n);
}

//This function initializes the buffer needed for drawing to work.
void InitPixBuff(alt_up_pixel_buffer_dma_dev **pixel_buffer_ptr) {

	*pixel_buffer_ptr = alt_up_pixel_buffer_dma_open_dev(
			VIDEO_PIXEL_BUFFER_DMA_NAME);
	//Initialise the graphic buffer

	unsigned int pixel_buffer_addr1 = SRAM_BASE;
	unsigned int pixel_buffer_addr2 = SRAM_BASE + (320 * 240 * 2);

	// Set the 1st buffer address
	alt_up_pixel_buffer_dma_change_back_buffer_address(*pixel_buffer_ptr,
			pixel_buffer_addr1);

	// Swap buffers –we have to swap because there is only an API function
	// to set the address of the background buffer.
	alt_up_pixel_buffer_dma_swap_buffers(*pixel_buffer_ptr);

	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(*pixel_buffer_ptr))
		;
	// Set the 2nd buffer address
	alt_up_pixel_buffer_dma_change_back_buffer_address(*pixel_buffer_ptr,
			pixel_buffer_addr2);

	// Clear both buffers (this makes all pixels black)
	alt_up_pixel_buffer_dma_clear_screen(*pixel_buffer_ptr, 0);
	alt_up_pixel_buffer_dma_clear_screen(*pixel_buffer_ptr, 1);
	//0 front, 1 back

}

//This function initializes the buffer needed for char printing
void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr) {
	*char_buffer_ptr = alt_up_char_buffer_open_dev(
			"/dev/video_character_buffer_with_dma");
	assert(*char_buffer_ptr);
	//Initialize the character buffer
	alt_up_char_buffer_init(*char_buffer_ptr);
}

//This function draws the background of the game
void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy) {
	// Draw a line to the background buffer
	alt_up_pixel_buffer_dma_draw_hline(pixel_buffer_cpy, 0, 320, 200, 0x064F, 1);
	//Resolution:320x240

}

void DrawBackground1(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy) {

	int row;
	int column;

	for (row = 0; row < (ROW - 1); row++) {
		for (column = 0; column < (COLUMN - 1); column++) {
			alt_up_pixel_buffer_dma_draw_box(pixel_buffer_cpy, column, row,
					column, row, bg1[row][column], 1);
		}
	}
}

void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy, gameState *gstate) {

	alt_up_pixel_buffer_dma_draw_box(HP_buffer_cpy, 15, 20,
			(gstate->player1.health * 1.4), 30, 0xF800, 1);

	alt_up_pixel_buffer_dma_draw_box(HP_buffer_cpy, (320
			- gstate->player2.health * 1.4), 20, 310, 30, 0xF800, 1);
}

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

//TODO: Split Character Function
void DrawCharacter(alt_up_pixel_buffer_dma_dev* buffer_cpy, gameState *gstate) {
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

	alt_up_pixel_buffer_dma_draw_box(buffer_cpy, (gstate->player2.xPosition
			+ 160 - gstate->player2.width), 120, (gstate->player2.xPosition
			+ 160 + gstate->player2.width), 200, 0x03FF, 1);
}

void render(gameState *state, alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer) {
	//clear screen
	//draw
	//swap buffer
	//check and wait for swap buffer
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);

	DrawBackground(pixel_buffer);
	//DrawBackground1(pixel_buffer);
	//Invoke this function to draw background;

	DrawHP(pixel_buffer, state);

	DrawTimer(char_buffer, getTimeRemaining(state));

	DrawCharacter(pixel_buffer, state);

	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer))
		;
}
