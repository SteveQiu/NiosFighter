#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <altera_up_avalon_audio.h>
#include "character.h"
#include "debug.h"

typedef struct gameState {
	character player1;
	character player2;
	int gameOver;
	float roundTime;
	alt_up_audio_dev *audio;
} gameState;

//Returns 0 on successful completion
int initGameState(gameState *state);
void checkPlayerCollisions(gameState *state);
void updatePlayerPosition(character* ch, float time);
void updatePlayerPunch(character* c1, character *c2, float time);
void updatePlayerStunned(character *c, float time);
int hitDetection(character *c1, character *c2);
int performPunch(character *c1, character *c2);
void updatePlayerStunned(character *c, float time);
void checkhp(gameState *state,character *c1, character *c2);
void updateTime(gameState *gstate, float time);
int getTimeRemaining(gameState *gstate);
void updatePlayerBlocking(character *c, float time);
#endif //GAMESTATE_H
