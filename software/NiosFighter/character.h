#define LEFT 1
#define RIGHT 2

typedef struct character character;
struct character {
	int direction;
	int health;
	int xPosition;
};

int initCharacter(character *target);


