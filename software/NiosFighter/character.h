#ifndef CHARACTER_H
#define CHARACTER_H
#define LEFT 1
#define RIGHT 2

typedef struct character {
	int direction;
	int health;
	int xPosition;
} character;

int initCharacter(character *target);

#endif //CHARACTER_H


