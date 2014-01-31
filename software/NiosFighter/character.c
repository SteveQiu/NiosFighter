#include "character.h"

int initCharacter(character *c) {
	c->health = 100;
	c->facingDirection = LEFT;
	c->movingDirection = NOTMOVING;
	c->xPosition = 0;
	return 0;
}

