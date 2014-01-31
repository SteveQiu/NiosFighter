#ifndef CHARACTER_H
#define CHARACTER_H
#define NOTMOVING 0
#define LEFT -1
#define RIGHT 1
#define ARENALEFTBORDER -100
#define ARENARIGHTBORDER 100
#define STATUS_IDLE     0x00000001
#define STATUS_STUNNED  0x00000010
#define STATUS_BLOCKING 0x00000100
#define STATUS_PUNCHING 0x00001000

typedef struct character {
	int facingDirection;
	int health;
	float width;
	float xPosition;
	int movingDirection;
	float walkingSpeed;
	int status;
	float punchMaxDuration;
	float punchLength;
	float punchDuration;
	int punchDamage;
	float fistDistance;
	float stunDuration;
	float stunMaxDuration;
	int wantsToPunch;
	int wantsToBlock;
	float blockChangeTime;
	float blockChangeMaxTime;
} character;

int initCharacter(character *target);

#endif //CHARACTER_H


