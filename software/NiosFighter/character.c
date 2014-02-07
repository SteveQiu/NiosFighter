#include "character.h"

int initCharacter(character *c) {
	c->health = 100;
	c->width = 20.0;
	c->punchDamage = 10;
	c->facingDirection = LEFT;
	c->movingDirection = NOTMOVING;
	c->xPosition = 0;
	c->walkingSpeed = 10.0;
	c->status = STATUS_IDLE;
	c->punchLength = 20;
	c->punchMaxDuration = 1.0;
	c->punchDuration = 0;
	c->fistDistance = 0;
	c->wantsToPunch = 0;
	c->wantsToBlock = 0;
	c->blockChangeTime = 0;
	c->blockChangeMaxTime = 0.75;
	return 0;
}

