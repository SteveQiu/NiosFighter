#include "altera_up_avalon_audio_and_video_config.h"
#include "altera_up_avalon_audio.h"

typedef struct sounddata{
	int len;
	int hlen;
	int loop;
} sounddata;

void av_config_setup();

void initaudio(alt_up_audio_dev **audio);

void initsounddata(sounddata *data,int len);

void loadsound(sounddata *data,int handle,alt_up_audio_dev *audio);
