#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "character.h"

typedef struct gameState {
	character player1;
	character player2;
	int gameOver;
} gameState;

//Returns 0 on successful completion
int initGameState(gameState *state);
void updatePlayerPosition(character* ch, float time);
void updatePlayerPunch(character* c1, character *c2, float time);
int hitDetection(character *c1, character *c2);
int performPunch(character *c1, character *c2);
void checkhp(gameState *state,character *c1, character *c2);

#endif //GAMESTATE_H
