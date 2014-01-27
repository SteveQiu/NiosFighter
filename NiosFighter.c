#include <altera_up_avalon_video_pixel_buffer_dma.h>
#include <altera_up_avalon_video_character_buffer_with_dma.h>
#include <system.h>
#include <assert.h>
#include <NiosFighter.h>

int main() {
	alt_up_pixel_buffer_dma_dev* pixel_buffer;
	// Use the name of your pixel buffer DMA core
	pixel_buffer
			= alt_up_pixel_buffer_dma_open_dev(VIDEO_PIXEL_BUFFER_DMA_NAME);
	// Set the background buffer address although we don't use the background,
	// they only provide a function to change the background buffer address, so
	// we must set that, and then swap it to the foreground.
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, SRAM_BASE);
	// Swap background and foreground buffers
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	// Wait for the swap to complete
	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer))
		;
	// Clear the screen
	alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
	// Draw a white lineto the foreground buffer
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 0, 0, 320, 240, 0xFFFF, 0);

	// Initialize
	alt_up_char_buffer_dev* char_buffer;
	char_buffer = alt_up_char_buffer_open_dev(
			"/dev/video_character_buffer_with_dma");
	assert(char_buffer);
	alt_up_char_buffer_init(char_buffer);
	// Write some text
	alt_up_char_buffer_string(char_buffer, "EECE 381", 40, 30);
}
