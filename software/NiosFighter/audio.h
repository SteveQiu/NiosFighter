#include <altera_up_avalon_audio_and_video_config.h>
#include <altera_up_avalon_audio.h>
#include <altera_up_sd_card_avalon_interface.h>
#include <stdio.h>
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_timer_regs.h>
#include <altera_avalon_timer.h>
#include <sys/alt_alarm.h>
#include <sys/alt_irq.h>

typedef struct sounddata{
	int len;
	int hlen;
	unsigned int buffer[300000];
	int index;
	alt_up_audio_dev *audio;
	int bytes_left;
	int bytes_right;
	int index_left;
	int index_right;
	int play;
} sounddata;

void av_config_setup();

void initaudio(alt_up_audio_dev **audio);
//void initaudio();

void initsounddata(sounddata *data);

void loadsound(sounddata *data,int handle,alt_up_audio_dev *audio);

void playsound(char* name,alt_up_audio_dev *audio);

void play_isr(void *context,alt_u32 id);

void playbg_isr(void *context,alt_u32 id);
