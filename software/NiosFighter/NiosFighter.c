#include "NiosFighter.h"

void main() {
	while(1){
	gameState gstate;
	frameTimer ftimer;
	initGameState(&gstate);
	initFrameTimer(&ftimer);

	alt_up_pixel_buffer_dma_dev* pixel_buffer;
	InitPixBuff(&pixel_buffer);

	alt_up_char_buffer_dev* char_buffer;
	InitCharBuff(&char_buffer);


	//gameLoop
		while(!(gstate.gameOver)) {
		startFrame(&ftimer);
		processInput(&gstate);
		updateGame(&gstate, frameLength(&ftimer));
		render(&gstate,char_buffer,pixel_buffer);
		endFrame(&ftimer);
		}
}
}

void updateGame(gameState *gstate, float frameLength) {
	checkhp(gstate,&gstate->player1, &gstate->player2);
	character* p1 = &(gstate->player1);
	character* p2 = &(gstate->player2);
	updatePlayerPosition(p1, frameLength);
	updatePlayerPosition(p2, frameLength);
	updatePlayerPunch(p1, p2, frameLength);
	updatePlayerPunch(p2, p1, frameLength);
	updatePlayerStunned(p1, frameLength);
	updatePlayerStunned(p2, frameLength);
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
