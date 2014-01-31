#include "NiosFighter.h"

int main() {
	gameState gstate;
	frameTimer ftimer;
	initGameState(&gstate);
	initFrameTimer(&ftimer);


	//gameLoop
	while(!(gstate.gameOver)) {
		startFrame(&ftimer);
		processInput(&gstate);
		updateGame(&gstate, frameLength(&ftimer));
		render(&gstate);
		endFrame(&ftimer);


	}

	return 0;
}

void updateGame(gameState *gstate, int frameLength) {

}

void processInput(gameState *gstate) {
	input move;
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
