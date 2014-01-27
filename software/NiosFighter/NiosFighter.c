#include "NiosFighter.h"

void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy) {
	// Set the background buffer address although we don't use the background,
	// they only provide a function to change the background buffer address, so
	// we must set that, and then swap it to the foreground.
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer_cpy, SRAM_BASE);
	// Swap background and foreground buffers
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer_cpy);
	// Wait for the swap to complete
	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer_cpy))
		;
	// Clear the screen
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer_cpy, 0);
	// Draw a white lineto the foreground buffer
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer_cpy, 0, 0, 320, 240, 0xFFFF, 0);
}

void DrawCharTest(alt_up_char_buffer_dev* char_buffer_cpy) {
	alt_up_char_buffer_init(char_buffer_cpy);
	// Write some text
	alt_up_char_buffer_string(char_buffer_cpy, "NiosFighter", 40, 30);
}

int main() {
	alt_up_pixel_buffer_dma_dev* pixel_buffer;
	pixel_buffer = alt_up_pixel_buffer_dma_open_dev(VIDEO_PIXEL_BUFFER_DMA_NAME);
	//Initialize the graphic buffer

	alt_up_char_buffer_dev* char_buffer;
	char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma");
	assert(char_buffer);
	//Initialize the character buffer

	DrawBackground(pixel_buffer);
	//Invoke this function to draw background;

	DrawCharTest(char_buffer);
	//Invoke this function to write some text;

	return 0;
}
