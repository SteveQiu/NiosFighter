#ifndef NIOSFIGHTER_H
#define NIOSFIGHTER_H
#include <system.h>
#include <assert.h>
#include <unistd.h>
#include "sdcard.h"
#include "gameState.h"
#include "render.h"
#include "frameTimer.h"
#include "debug.h"
#include "input.h"


void updateGame(gameState* state, float frameLength);
void processInput(gameState* gstate,alt_up_ps2_dev * ps2);

#endif //NIOSFIGHTER_H

