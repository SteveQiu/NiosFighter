#ifndef CHARACTER_H
#define CHARACTER_H
#define NOTMOVING 0
#define LEFT 1
#define RIGHT 2

typedef struct character {
	int facingDirection;
	int health;
	int xPosition;
	int movingDirection;
	float walkingSpeed;

} character;

int initCharacter(character *target);

#endif //CHARACTER_H


