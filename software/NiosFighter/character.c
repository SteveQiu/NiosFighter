#include "character.h"

int initCharacter(character *c) {
	c->health = 100;
	c->facingDirection = LEFT;
	c->movingDirection = NOTMOVING;
	c->xPosition = 0;
	c->walkingSpeed = 5.0;
	c->status = STATUS_IDLE;
	c->punchLength = 20;
	c->punchMaxDuration = 1.0;
	c->punchDuration = 0;
	c->fistDistance = 0;
	return 0;
}

