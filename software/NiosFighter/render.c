#include "render.h"

void renderStartscreen(alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer, dirtyManager *dm) {
	DrawStartScreen(pixel_buffer, char_buffer, 0, 0, 320, 240);
}

void renderInstrction(gameState *state, alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer) {
	DrawInstruction(pixel_buffer, char_buffer);
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
	DrawBackground(*pixel_buffer_ptr, 0, 0, 320, 240);
	DrawHealthBar(*pixel_buffer_ptr, 14, 10);
	DrawHealthBar(*pixel_buffer_ptr, 180, 10);

	// Swap buffers –we have to swap because there is only an API function
	// to set the address of the background buffer.
	alt_up_pixel_buffer_dma_swap_buffers(*pixel_buffer_ptr);
	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(*pixel_buffer_ptr))
		;

	// Set the 2nd buffer address
	alt_up_pixel_buffer_dma_change_back_buffer_address(*pixel_buffer_ptr,
			pixel_buffer_addr2);
	DrawBackground(*pixel_buffer_ptr, 0, 0, 320, 240);
	DrawHealthBar(*pixel_buffer_ptr, 14, 10);
	DrawHealthBar(*pixel_buffer_ptr, 180, 10);
}

//This function initializes the buffer needed for char printing
void InitCharBuff(alt_up_char_buffer_dev** char_buffer_ptr) {
	*char_buffer_ptr = alt_up_char_buffer_open_dev(
			"/dev/video_character_buffer_with_dma");
	assert(*char_buffer_ptr);
	//Initialize the character buffer
	alt_up_char_buffer_init(*char_buffer_ptr);
}
/*void LED_health(gameState *gstate)
 {
 int h1= gstate->player1.health;
 int h2= gstate->player2.health;
 if(h1<13)
 LED_BASE = 0xFF;

 }*/
void render(gameState *state, alt_up_char_buffer_dev* char_buffer,
		alt_up_pixel_buffer_dma_dev *pixel_buffer, dirtyManager *dm) {

	//Redraw all the dirty sections
	while (dm->head != NULL) {

		DrawBackground(pixel_buffer, dm->head->x, dm->head->y, dm->head->w,
				dm->head->h);

		popDirtySection(dm);
	}

	DrawHP(pixel_buffer, state, dm);

	DrawTimer(char_buffer, getTimeRemaining(state));

	DrawCharacter(pixel_buffer, state, dm);

	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer))
		;

}

/*
 displayMenu(){
 int a=0;
 while(!a){
 readKeyboard();
 if(key->ENT) a=1;
 }
 }
 //select current item

 */
