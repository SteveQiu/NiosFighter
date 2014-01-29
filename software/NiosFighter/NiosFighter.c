#include "NiosFighter.h"
#include "gameState.h"
#include "render.h"

int main() {

	gameState gstate;

	//gameLoop
	while(!gameOver) {
		//processInput();
		//updateGame(int timePassed);
		render(gstate);
	}

	return 0;
}
