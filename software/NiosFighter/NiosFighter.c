#include "NiosFighter.h"

int main() {
	gameState gstate;
	frameTimer ftimer;
	initGameState(&gstate);
	initFrameTimer(&ftimer);
	input move;

	//gameLoop
	while(!(gstate.gameOver)) {
//		startFrame(&ftimer);
//		processInput(&gstate);
//		updateGame(&gstate, frameLength(&ftimer));
//		render(&gstate);
//		endFrame(&ftimer);
		refkey(&move);
		if(move.p){
			if(move.left)
				printf("Moving left\n");
			if(move.right)
				printf("Moving right\n");
			if(move.punch)
				printf("Punching\n");
			if(move.jump)
				printf("Jumping\n");

		}
		else
			printf("Nothing\n");
		usleep(100000);
	}

	return 0;
}

void updateGame(gameState *gstate, int frameLength) {
	return;
}

void processInput(gameState *gstate) {
	//How to fill in this function
	//Say the player presses a button that makes a character move left
	//if(moveLeftButtonIsPressed()) {
	//	gstate->player1->ismovingLeft = 1;
	//}
	//etc
}
