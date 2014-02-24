#ifndef NIOSFIGHTER_H
#define NIOSFIGHTER_H
#include "system.h"
#include <assert.h>
#include <unistd.h>
#include "sdcard.h"
#include "gameState.h"
#include "render.h"
#include "frameTimer.h"
#include "debug.h"
#include "input.h"
#include "audio.h"
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_timer_regs.h>
#include <altera_avalon_timer.h>
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>

void updateGame(gameState* state, float frameLength);
void processInput(gameState* gstate, alt_up_ps2_dev * ps2, input *move);

#endif //NIOSFIGHTER_H
