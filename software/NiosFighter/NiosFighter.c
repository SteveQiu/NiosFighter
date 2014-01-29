#include "NiosFighter.h"

int main() {
	gameState gstate;
	frameTimer ftimer;
	initGameState(&gstate);
	initFrameTimer(&ftimer);

	//gameLoop
	while(!(gstate.gameOver)) {
		startFrame(&ftimer);
		//processInput();
		updateGame(frameLength(&ftimer));
		render(&gstate);
		endFrame(&ftimer);
	}

	return 0;
}

void updateGame(int frameLength) {
	return;
}
