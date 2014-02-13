#include "gameState.h"

int initGameState(gameState *gstate) {
	gstate->gameOver = 0;
	gstate->roundTime = 0;
	initCharacter(&(gstate->player1));
	initCharacter(&(gstate->player2));

	gstate->player1.xPosition = -50;
	gstate->player2.xPosition = 50;
	gstate->player1.facingDirection = RIGHT;
	gstate->player2.facingDirection = LEFT;
	gstate->player1.punchLength = 30;
	gstate->player1.punchDamage = 20;
	gstate->player2.punchLength = 30;
	gstate->player2.punchDamage = 20;
	gstate->player1.width = 10;
	gstate->player2.width = 10;

	return 0;
}

void updatePlayerPosition(character *ch, float time) {
	// (ch->status == STATUS_IDLE) {
		ch->xPosition += time * ch->movingDirection * ch->walkingSpeed * 2;
		if (ch->xPosition < ARENALEFTBORDER)
			ch->xPosition = ARENALEFTBORDER;
		if (ch->xPosition > ARENARIGHTBORDER)
			ch->xPosition = ARENARIGHTBORDER;
	//}
}

void checkPlayerCollisions(gameState *state) {
	character *p1 = &(state->player1);
	character *p2 = &(state->player2);
	if (p1->xPosition > (p2->xPosition + (p1->width + p2->width) / 2)) {
		p1->xPosition = p2->xPosition - (p1->width - p2->width) / 2;
		p1->movingDirection = NOTMOVING;
	}
	if (p2->xPosition < (p1->xPosition + (p1->width + p2->width) / 2)) {
		p2->xPosition = p1->xPosition + (p1->width + p2->width) / 2;
		p2->movingDirection = NOTMOVING;
	}
}

void updatePlayerPunch(character *p1, character *p2, float time) {
	//if (p1->wantsToPunch == 1 && p1->status == STATUS_IDLE) {
	if (p1->wantsToPunch == 1 && p1->status != STATUS_PUNCHING) {
		p1->status = STATUS_PUNCHING;
		p1->punchDuration = 0.0;
	} else if (p1->status == STATUS_PUNCHING) {
		if (p1->punchDuration < p1->punchMaxDuration) {
			p1->punchDuration += time;
			p1->fistDistance = (p1->punchDuration / p1->punchMaxDuration)
					* p1->punchLength * p1->facingDirection;
		//} else if (p1->punchDuration > p1->punchMaxDuration) {
		} else if (p1->punchDuration) {
			p1->status = hitDetection(p1, p2);
			p1->punchDuration = 0.0;
			p1->fistDistance = 0;
		}
	}
}

int hitDetection(character *c1, character *c2) {
	if (c1->facingDirection == RIGHT) {
		if (c1->xPosition + c1->punchLength > c2->xPosition - c2->width) {
			return performPunch(c1, c2);
		}
	}
	if (c1->facingDirection == LEFT) {
		if (c1->xPosition - c1->punchLength < c2->xPosition + c2->width) {
			return performPunch(c1, c2);
		}
	}
	return STATUS_IDLE;
}

int performPunch(character *c1, character *c2) {
	if (c2->status == STATUS_BLOCKING) {
		return STATUS_STUNNED;
	} else {
		c2->health -= c1->punchDamage;
		return STATUS_IDLE;
	}
}

void updatePlayerStunned(character *c, float time) {
	if (c->status == STATUS_STUNNED) {
		DEBUGMSG("PlayerIsStunned\n");
		c->punchDuration = 0.0;
		c->blockChangeTime = 0.0;
		c->stunDuration += time;
		DEBUGVAL("Stun Duration:%f\n", c->stunDuration);
		if (c->stunDuration > c->stunMaxDuration) {
			c->status = STATUS_IDLE;
			c->stunDuration = 0;
		}
	}
}

void updatePlayerBlocking(character *c, float time) {
	if (c->wantsToBlock == 1) {
		if (c->status == STATUS_IDLE) {
			if (c->blockChangeTime < c->blockChangeMaxTime) {
				c->blockChangeTime += time;
			} else if (c->blockChangeTime > c->blockChangeMaxTime) {
				c->status = STATUS_BLOCKING;
				c->blockChangeTime = 0.0;
			}
		}
	}
	if (c->wantsToBlock == 0) {
		if (c->status == STATUS_BLOCKING) {
			if (c->blockChangeTime < c->blockChangeMaxTime) {
				c->blockChangeTime += time;
			} else if (c->blockChangeTime > c->blockChangeMaxTime) {
				c->status = STATUS_IDLE;
				c->blockChangeTime = 0.0;
			}
		}
	}
}

void checkhp(gameState *state, character *c1, character *c2) {
	if (c1->health <= 0)
		state->gameOver = 1;
	else if (c2 -> health <= 0)
		state->gameOver = 1;
}

void updateTime(gameState *gstate, float time) {
	gstate->roundTime += time;
	if (gstate->roundTime > 99) {
		gstate->gameOver = 1;
	}
}

int getTimeRemaining(gameState *gstate) {
	float timeleft = 99 - gstate->roundTime;
	return (int) timeleft;
}

