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

void updateGame(int frameLength) {
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
