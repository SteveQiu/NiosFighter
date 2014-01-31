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

void updatePlayerPunch(character *p1, character *p2, float time) {
	if (p1->status == STATE_PUNCHING) {
		if (p1->punchDuration == 0.0) {
		} else if (p1->punchDuration < p1->punchMaxDuration) {
			p1->punchDuration += time;
			p1->fistDistance =
					(p1->punchDuration/p1->punchMaxDuration)
					* p1->punchLength * p1->facingDirection;
		} else if (p1->punchDuration > p1->punchMaxDuration) {
			p1->punchDuration = 0.0;
			p1->state = hitDetection(p1,p2);
			p1->fistDistance = 0;
		}
	}
}

int hitDetection(p1, p2) {

}










