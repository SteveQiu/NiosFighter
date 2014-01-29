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

#endif //GAMESTATE_H
