#include "NiosFighter.h"

int main() {

	while(1){
	//create variables
	gameState gstate;
	frameTimer ftimer;
	sdcard card;
	alt_up_sd_card_dev *device_reference = NULL;
	alt_up_char_buffer_dev* char_buffer;
	alt_up_pixel_buffer_dma_dev* pixel_buffer;
	alt_up_audio_dev *audio;

	//initiation
	initGameState(&gstate);
	initFrameTimer(&ftimer);
	initsdcard(&card,&device_reference);
	InitPixBuff(&pixel_buffer);
	InitCharBuff(&char_buffer);
	initaudio(&audio);


	//gameLoop
		while(!(gstate.gameOver)) {
		startFrame(&ftimer);
		testsdcard(&card,device_reference);
		//playsound("FILE NAME",sec * 100000, audio);
		playsound("MK.wav", audio);
		processInput(&gstate);
		updateGame(&gstate, frameLength(&ftimer));
		render(&gstate,char_buffer,pixel_buffer);
		endFrame(&ftimer);
		}
}

	return 0;
}

void updateGame(gameState *gstate, float frameLength) {
	checkhp(gstate,&gstate->player1, &gstate->player2);
	character* p1 = &(gstate->player1);
	character* p2 = &(gstate->player2);
	checkPlayerCollisions(gstate);
	updatePlayerPosition(p1, frameLength);
	updatePlayerPosition(p2, frameLength);
	updatePlayerPunch(p1, p2, frameLength);
	updatePlayerPunch(p2, p1, frameLength);
	updatePlayerStunned(p1, frameLength);
	updatePlayerStunned(p2, frameLength);
	updateTime(gstate, frameLength);
}

void processInput(gameState *gstate) {
	input move;
	refkey(&move);
	gstate->player1.movingDirection = NOTMOVING;
	gstate->player1.wantsToPunch = 0;
	gstate->player1.wantsToBlock = 0;
	if(move.p){
		if(move.left)
			gstate->player1.movingDirection = LEFT;
		if(move.right)
			gstate->player1.movingDirection = RIGHT;
		if(move.punch)
			gstate->player1.wantsToPunch = 1;
		if(move.block)
			gstate->player1.wantsToBlock = 1;
	}

}
