#include "NiosFighter.h"
//Red Arm = 39px
//Shoulder to Shoulder 26px
//Blue Arm = 39px
//StS 26px

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
		//initaudio(&audio);
		initKeyboard(&ps2);
		initKey(&move);
		//initKey(&move);

		//alt_irq_register(AUDIO_0_IRQ,&audio,play_isr);
		//alt_irq_enable(AUDIO_0_IRQ);
		//alt_up_audio_enable_write_interrupt(audio);

		//Menu Loop
		//displayMenu();

		//Game Loop
		alt_up_char_buffer_clear(char_buffer);

		while (!(gstate.gameOver)) {
			startFrame(&ftimer);
			testsdcard(&card, device_reference);
			//playsound("MK.wav", audio);
			processInput(&gstate, ps2, &move);
			updateGame(&gstate, frameLength(&ftimer));
			swapdm(&dm, &dm2);
			render(&gstate, char_buffer, pixel_buffer, dm);
			//renderStartscreen(char_buffer, pixel_buffer, &dm);
			endFrame(&ftimer);
			//printf("FRAME TIME: %f\n", frameLength(&ftimer));

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
	readKeyboard(move, ps2);
	//refkey(move);
	//If move struct contains
	//player one movement
	if (move->A)
		gstate->player1.movingDirection = LEFT;
	else if (move->D)
		gstate->player1.movingDirection = RIGHT;
	else
		gstate->player1.movingDirection = NOTMOVING;
	//player one punch
	if (move->H)
		gstate->player1.wantsToPunch = 1;
	else
		gstate->player1.wantsToPunch = 0;
	//player one block
	if (move->J)
		gstate->player1.wantsToBlock = 1;
	else
		gstate->player1.wantsToBlock = 0;
	/*		if(move->K)
	 gstate->player1.wantsToFake = 1;
	 else
	 gstate->player1.wantsToFake = 0;
	 */

	//player two movement
	if (move->LARR)
		gstate->player2.movingDirection = LEFT;
	else if (move->RARR)
		gstate->player2.movingDirection = RIGHT;
	else
		gstate->player2.movingDirection = NOTMOVING;
	//player two punch
	if (move->NP1)
		gstate->player2.wantsToPunch = 1;
	else
		gstate->player2.wantsToPunch = 0;
	//player two block
	if (move->NP2)
		gstate->player2.wantsToBlock = 1;
	else
		gstate->player2.wantsToBlock = 0;
	/*		if(move->NP3)
	 gstate->player2.wantsToFake = 1;
	 else
	 gstate->player2.wantsToFake = 0;
	 */
}
