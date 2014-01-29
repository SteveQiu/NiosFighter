#ifndef FRAMETIMER_H
#define FRAMETIMER_H
#include <sys/alt_timestamp.h>
//In order to get this to compile with eclipse do the following
//1. Right click NiosFighter_bsp project
//2. Go to Nios II -> BSP Editor
//3. Go to Settings -> Common -> hal -> timestamp timer
//4. Set the value drowpdown to timer_0
//5. Click "Generate" on the bottom right!

typedef struct frameTimer {
	int totalTime;
	int frameStartTime;
	int frameEndTime;
	int lastFrameLength;
} frameTimer;

int initFrameTimer(frameTimer *ftimer);
void startFrame(frameTimer *ftimer);
void endFrame(frameTimer *ftimer);
float frameLength(frameTimer *ftimer);


#endif //FRAMETIMER_H

