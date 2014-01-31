#ifndef NIOSFIGHTER_H
#define NIOSFIGHTER_H
#include <system.h>
#include <assert.h>
#include <unistd.h>
#include "gameState.h"
#include "render.h"
#include "frameTimer.h"
#include "debug.h"
#include "input.h"

void updateGame(gameState* state, int frameLength);
void processInput(gameState* gstate);

#endif //NIOSFIGHTER_H

