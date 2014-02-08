#include "audio.h"
#include <system.h>

void av_config_setup() {
	alt_up_av_config_dev * av_config = alt_up_av_config_open_dev(AUDIO_NAME);
	if(!av_config){
		printf("failed to open config file\n");
	}
	while (!alt_up_av_config_read_ready(av_config)) {}

}

void initaudio(alt_up_audio_dev **audio){

	av_config_setup();

	*audio = alt_up_audio_open_dev(AUDIO_0_NAME);
}

void initsounddata(sounddata *data,int len){
	data->len= len;
	data->hlen= len/2;
	data->loop= len/2*5;
}

void loadsound(sounddata *data,int handle ,alt_up_audio_dev *audio){

	unsigned int buffer[data->hlen];
	unsigned int buf [data->len];
	int i;

	printf("Starting to play\n");
	while(1){
		printf("Reading\n");
		for( i=0;i<data->len;i++){
				buf[i]=alt_up_sd_card_read(handle);
			}
			printf("Downloading\n");
			int j=0;
			for(i = 0; i<data->len; i+=2){
					buffer[j] = (buf[i+1] << 8) | buf[i];
					j++;
					}
			printf("converting\n");
			if(audio == NULL)
				printf("Audio is null\n");

		int index=0;
		int bytes_left;
		int bytes_right;
		int index_left=22;
		int index_right=22;
		while(index< data->loop){
			bytes_left = alt_up_audio_write_fifo(audio, &buffer[index_left], data->hlen, ALT_UP_AUDIO_LEFT);
			bytes_right = alt_up_audio_write_fifo(audio, &buffer[index_right], data->hlen, ALT_UP_AUDIO_RIGHT);
			index_left += bytes_left;
			index_right += bytes_right;
			index++;
		}
		printf("Reset\n");
}
}
