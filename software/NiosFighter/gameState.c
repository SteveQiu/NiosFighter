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
		} if (p1->punchDuration > p1->punchMaxDuration) {
			p1->state = hitDetection(p1,p2);
			p1->punchDuration = 0.0;
			p1->fistDistance = 0;
		}
	}
}

int hitDetection(character *c1, character *c2) {
	if (c1->facingDirection == RIGHT) {
		if (c1->xPosition+c1->punchLength >
			c2->xPosition - c2->width) {
			return performPunch(c1, c2);
		}
	}
	if (c1->facingDirection == LEFT) {
		if (c1->xPosition-c1->punchLength <
			c2->xPosition + c2->width) {
			return performPunch(c1, c2);
		}
	}
	return STATE_IDLE;
}

int performPunch(character *c1, character *c2) {
	if(c2->state == STATE_BLOCKING) {
		return STATE_STUNNED;
	}
	else {
		c2->health -= c1->punchDamage;
		return STATE_IDLE;
	}
}

void updatePlayerStunned(character *c, float time) {
	if (c->status == STATE_STUNNED) {
		c->stunDuration += time;
		if (c->stunDuration > c->stunMaxDuration) {
			c->status = STATE_IDLE;
			c->stunDuration = 0;
		}
	}
}









