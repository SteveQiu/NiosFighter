#ifndef NIOSFIGHTER_H
#define NIOSFIGHTER_H
#include <system.h>
#include <assert.h>
#include "gameState.h"
#include "render.h"
#include "frameTimer.h"
#include "debug.h"

void updateGame(gameState* state, float frameLength);
void processInput(gameState* gstate);

#endif //NIOSFIGHTER_H

