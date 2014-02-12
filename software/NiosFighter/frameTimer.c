#include "frameTimer.h"

int initFrameTimer(frameTimer *ftimer) {
	alt_timestamp_start();
	ftimer->totalTime = 0;
	ftimer->frameStartTime = 0;
	ftimer->frameEndTime = 0;
	ftimer->lastFrameLength = 0;
	return 0;
}

void startFrame(frameTimer* ftimer) {
	ftimer->lastFrameLength =
			ftimer->frameEndTime;
	//ftimer->frameStartTime = alt_timestamp();
	alt_timestamp_start();
}

void endFrame(frameTimer* ftimer) {
	ftimer->frameEndTime = alt_timestamp();
}

float frameLength(frameTimer *ftimer) {
	float val = (float)(ftimer->lastFrameLength)
					/(float)alt_timestamp_freq();
	DEBUGVAL("FRAMELENGTH: %f\n", val);
	return val;
}

int numTicksPerSecond() {
	return alt_timestamp_freq();
}



