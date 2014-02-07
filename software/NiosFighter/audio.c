#include "audio.h"
#include <system.h>

void av_config_setup() {
	alt_up_av_config_dev * av_config = alt_up_av_config_open_dev(AUDIO_NAME);
	if(!av_config){
		printf("failed to open config file\n");
	}
	while (!alt_up_av_config_read_ready(av_config)) {}

}
