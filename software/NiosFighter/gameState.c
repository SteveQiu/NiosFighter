#include "gameState.h"

int initGameState(gameState *gstate) {
	gstate->gameOver = 0;
	initCharacter(&gstate->player1);
	initCharacter(&gstate->player2);

	gstate->player1->xPosition = -50;
	gstate->player2->xposition = 50;
	gstate->player1->facingDirection = RIGHT;
	gstate->player2->facingDirection = LEFT;

	return 0;
}

void updatePlayerPosition(character *ch, float time) {
	if (ch->state == STATE_IDLE) {
		ch->xPosition +=
				time * ch->movingDirection * ch->walkingSpeed;
		if (ch->xPosition < ARENALEFTBORDER)
				ch->xPosition = ARENALEFTBORDER;
		if (ch->xPosition > ARENARIGHTBORDER)
				ch->xPosition = ARENARIGHTBORDER;
	}


}
