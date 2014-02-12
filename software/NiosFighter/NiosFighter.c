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
	alt_up_ps2_dev * ps2;

	//initiation
	initGameState(&gstate);
	initFrameTimer(&ftimer);
	initsdcard(&card,&device_reference);
	InitPixBuff(&pixel_buffer);
	InitCharBuff(&char_buffer);
	initKeyboard(&ps2);
	//gameLoop
		while(!(gstate.gameOver)) {
		startFrame(&ftimer);
		testsdcard(&card,device_reference);
		processInput(&gstate,&ps2);
		updateGame(&gstate,frameLength(&ftimer));
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
}

void processInput(gameState *gstate, alt_up_ps2_dev * ps2) {
	input move;
	int keyb=readKeyboard(&move,ps2);
	if(keyb==0)
		printf("keyboard did not read properly");

	//Reset all states
	gstate->player1.movingDirection = NOTMOVING;
	gstate->player1.wantsToPunch = 0;
	gstate->player1.wantsToBlock = 0;
	gstate->player2.movingDirection = NOTMOVING;
	gstate->player2.wantsToPunch = 0;
	gstate->player2.wantsToBlock = 0;
	//If move struct contains
	if(move.press){
		if(move.p1_left)
			gstate->player1.movingDirection = LEFT;
		if(move.p1_right)
			gstate->player1.movingDirection = RIGHT;
		if(move.p1_punch)
			gstate->player1.wantsToPunch = 1;
		if(move.p1_block)
			gstate->player1.wantsToBlock = 1;
		if(move.p2_left)
			gstate->player2.movingDirection = LEFT;
		if(move.p2_right)
			gstate->player2.movingDirection = RIGHT;
		if(move.p2_punch)
			gstate->player2.wantsToPunch = 1;
		if(move.p2_block)
			gstate->player2.wantsToBlock = 1;
	}

}
