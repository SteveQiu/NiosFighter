#include "render.h"

void InitPixBuff(alt_up_pixel_buffer_dma_dev **pixel_buffer_ptr) {
	*pixel_buffer_ptr = alt_up_pixel_buffer_dma_open_dev(
			VIDEO_PIXEL_BUFFER_DMA_NAME);
	//Initialise the graphic buffer

	unsigned int pixel_buffer_addr1 = VIDEO_PIXEL_BUFFER_DMA_BASE;
	unsigned int pixel_buffer_addr2 = VIDEO_PIXEL_BUFFER_DMA_BASE + (320 * 240 * 2);

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
}

void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr) {
	*char_buffer_ptr = alt_up_char_buffer_open_dev(
			"/dev/video_character_buffer_with_dma");
	assert(*char_buffer_ptr);
	//Initialize the character buffer
	alt_up_char_buffer_init(*char_buffer_ptr);
}

void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy) {
	// Clear the screen, this makes it black
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer_cpy, 0);
	// Draw a white lineto the foreground buffer
	alt_up_pixel_buffer_dma_draw_hline(pixel_buffer_cpy, 0, 320, 200, 0x064F, 0);
	//Resolution:320x240
	DrawHP(pixel_buffer_cpy);
}

void DrawHP(alt_up_pixel_buffer_dma_dev* HP_buffer_cpy){

	alt_up_char_buffer_init(HP_buffer_cpy);

	alt_up_pixel_buffer_dma_draw_box(HP_buffer_cpy, 15, 20 , 150, 40, 0x064F, 0);
}

void DrawTimerSpace(alt_up_char_buffer_dev* char_buffer_cpy) {
	// Write some text
	alt_up_char_buffer_string(char_buffer_cpy, "NiosFighter",160,200);
	//Resolution:320x240
	alt_up_char_buffer_string(char_buffer_cpy, "    ", 38, 0);
	//80*60 array across 320*280 resolution screen
}

void render(gameState* state) {
	alt_up_pixel_buffer_dma_dev* pixel_buffer;
	InitPixBuff(&pixel_buffer);

	alt_up_char_buffer_dev* char_buffer;
	InitCharBuff(&char_buffer);

	DrawBackground(pixel_buffer);
	//Invoke this function to draw background;

	//DrawCharTest(char_buffer);
	//Invoke this function to write some text;
}
