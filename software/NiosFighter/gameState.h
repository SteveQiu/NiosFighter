#include "character.h"

typedef struct gameState gameState;
struct gameState {
	character player1;
	character player2;
};

//Returns 0 on successful completion
int initGameState(gameState state);
