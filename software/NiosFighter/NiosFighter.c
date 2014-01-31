#include "NiosFighter.h"

int main() {
	gameState gstate;
	frameTimer ftimer;
	initGameState(&gstate);
	initFrameTimer(&ftimer);
	printf("test");
	render(&gstate);
	printf("test11");


	//gameLoop
	while(!(gstate.gameOver)) {
		startFrame(&ftimer);
		processInput(&gstate);
		updateGame(&gstate, frameLength(&ftimer));
		render(&gstate);
		printf("test");
		endFrame(&ftimer);


	}

	return 0;
}
void updateGame(gameState *gstate, float frameLength) {

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
	if(move.p){
				if(move.left)
					printf("Moving left\n");
				if(move.right)
					printf("Moving right\n");
				if(move.punch)
					printf("Punching\n");
				if(move.block)
					printf("Jumping\n");
			}
			else
				printf("Nothing\n");
			usleep(100000);
}
