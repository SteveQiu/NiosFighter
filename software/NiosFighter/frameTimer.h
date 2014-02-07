#ifndef FRAMETIMER_H
#define FRAMETIMER_H
#include <sys/alt_timestamp.h>
//In order to get this to compile with eclipse do the following
//1. Right click NiosFighter_bsp project
//2. Go to Nios II -> BSP Editor
//3. Go to Settings -> Common -> hal -> timestamp timer
//REMEMBER TO CHECK COMMON AFTER, AND MAKE SURE sys_clk_timer IS SET TO none!
//4. Set the value drowpdown to timer_0
//5. Click "Generate" on the bottom right!
//DONT FUCK WITH THE TIMER. alt_timestamp_start() SHOULD BE CALLED ONCE
//WHEN THE frameTimer OBJECT IS INITIALIZED! DONT FUCK WITH IT!

typedef struct frameTimer {
	int totalTime;
	int frameStartTime;
	int frameEndTime;
	int lastFrameLength;
} frameTimer;

int initFrameTimer(frameTimer *ftimer);
void startFrame(frameTimer *ftimer);
void endFrame(frameTimer *ftimer);
//This is the function whos value is passed to updateGame
//This function returns the time (in seconds) it took for the last
//frame to execute
float frameLength(frameTimer *ftimer);
int numTicksPerSecond();


#endif //FRAMETIMER_H

