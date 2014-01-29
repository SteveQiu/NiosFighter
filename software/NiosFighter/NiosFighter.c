#include "NiosFighter.h"

int main() {
	gameState gstate;
	initGameState(&gstate);

	//gameLoop
	while(!(gstate.gameOver)) {
		//processInput();
		//updateGame(int timePassed);
		render(&gstate);
	}

	return 0;
}
