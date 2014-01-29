void DrawBackground(alt_up_pixel_buffer_dma_dev* pixel_buffer_cpy) {
	// Clear the screen
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer_cpy, 0);
	// Draw a white lineto the foreground buffer
	alt_up_pixel_buffer_dma_draw_hline(pixel_buffer_cpy, 0, 320, 170, 0x064F, 0);
	//Resolution:320x240
}

void DrawCharTest(alt_up_char_buffer_dev* char_buffer_cpy) {
	// Write some text
	alt_up_char_buffer_string(char_buffer_cpy, "NiosFighter",160,200);
}

void render(gameState state_cpy) {
	alt_up_pixel_buffer_dma_dev* pixel_buffer;
	pixel_buffer = alt_up_pixel_buffer_dma_open_dev(VIDEO_PIXEL_BUFFER_DMA_NAME);
	//Initialize the graphic buffer

	unsigned intpixel_buffer_addr1 = PIXEL_BUFFER_BASE;
	unsigned intpixel_buffer_addr2 = PIXEL_BUFFER_BASE + (320 * 240 * 2);

	// Set the 1st buffer address
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer,
	pixel_buffer_addr1);

	// Swap buffers –we have to swap because there is only an API function
	// to set the address of the background buffer.
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	while(alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));
	// Set the 2nd buffer address
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, pixel_buffer_addr2);
	// Clear both buffers (this makes all pixels black)
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);

	alt_up_char_buffer_dev* char_buffer;
	char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma");
	assert(char_buffer);
	//Initialize the character buffer
	alt_up_char_buffer_init(char_buffer_cpy);

	DrawBackground(pixel_buffer);
	//Invoke this function to draw background;

	DrawCharTest(char_buffer);
	//Invoke this function to write some text;
}
