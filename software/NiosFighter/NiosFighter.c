#include "NiosFighter.h"

int main() {



	while (1) {
		//create variables
		gameState gstate;
		frameTimer ftimer;
		sdcard card;
		input move;
		alt_up_sd_card_dev *device_reference = NULL;
		alt_up_char_buffer_dev* char_buffer;
		alt_up_pixel_buffer_dma_dev* pixel_buffer;
		dirtyManager dm;
		dirtyManager dm2;
		alt_up_audio_dev *audio;
		alt_up_ps2_dev * ps2;
		//initiation
		initGameState(&gstate);
		initFrameTimer(&ftimer);
		initsdcard(&card, &device_reference);
		InitPixBuff(&pixel_buffer);
		InitCharBuff(&char_buffer);
		initDirtyManager(&dm);
		initDirtyManager(&dm2);
		initaudio(&audio);
		initKeyboard(&ps2);
		initKey(&move);

/*
		alt_up_audio_enable_write_interrupt(audio);
		alt_irq_register(AUDIO_0_IRQ,&audio,play_isr);
		alt_irq_enable(AUDIO_0_IRQ);
*/


/*
		alt_up_audio_enable_write_interrupt(audio);
		alt_avalon_timer_sc_init ((void *)BG_TIMER_BASE, BG_TIMER_IRQ_INTERRUPT_CONTROLLER_ID, BG_TIMER_IRQ, BG_TIMER_FREQ);
		alt_irq_register(BG_TIMER_IRQ,&audio,play_isr);
		alt_irq_enable(BG_TIMER_IRQ);
*/

/*
		IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_1_BASE,(1<<3)|(1<<1)|(1<<0));
		IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_1_BASE,0);//clear to bit reaching 0
		alt_irq_register(TIMER_1_BASE,&audio,play_isr);
		IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_1_BASE,(1<<2)|(1<<1)|(1<<0));//start timer, IRQ enble
*/

		//Display Menu();
		//if(input1){
		//gameLoop
		while (!(gstate.gameOver)) {
			startFrame(&ftimer);
			testsdcard(&card, device_reference);
			//playsound("MK.wav", audio);
			processInput(&gstate,ps2,&move);
			updateGame(&gstate, frameLength(&ftimer));
			swapdm(&dm, &dm2);
			render(&gstate, char_buffer, pixel_buffer, &dm);
			endFrame(&ftimer);

		}


		//}
		//else if(input2){
		//displayinstruction();
		//}
	}

	return 0;
}

void updateGame(gameState *gstate, float frameLength) {
	checkhp(gstate, &gstate->player1, &gstate->player2);
	character* p1 = &(gstate->player1);
	character* p2 = &(gstate->player2);
	checkPlayerCollisions(gstate);
	updatePlayerPosition(p1, frameLength);
	updatePlayerPosition(p2, frameLength);
	updatePlayerPunch(p1, p2, frameLength);
	updatePlayerPunch(p2, p1, frameLength);
	updatePlayerStunned(p1, frameLength);
	updatePlayerStunned(p2, frameLength);
	updatePlayerBlocking(p1, frameLength);
	updatePlayerBlocking(p2, frameLength);
	updateTime(gstate, frameLength);
}

void processInput(gameState *gstate, alt_up_ps2_dev * ps2, input *move) {


	readKeyboard(move,ps2);
	refkey(move);

	//Reset all states
	gstate->player1.movingDirection = NOTMOVING;
	gstate->player1.wantsToPunch = 0;
	gstate->player1.wantsToBlock = 0;

	gstate->player2.movingDirection = NOTMOVING;
	gstate->player2.wantsToPunch = 0;
	gstate->player2.wantsToBlock = 0;
	//If move struct contains

		if (move->p1_left)
			gstate->player1.movingDirection = LEFT;
		if (move->p1_right)
			gstate->player1.movingDirection = RIGHT;
		if (move->p1_punch)
			gstate->player1.wantsToPunch = 1;
		if (move->p1_block)
			gstate->player1.wantsToBlock = 1;
		if(move->p2_left)
			gstate->player2.movingDirection = LEFT;
		if(move->p2_right)
			gstate->player2.movingDirection = RIGHT;
		if(move->p2_punch)
			gstate->player2.wantsToPunch = 1;
		if(move->p2_block)
			gstate->player2.wantsToBlock = 1;


}
