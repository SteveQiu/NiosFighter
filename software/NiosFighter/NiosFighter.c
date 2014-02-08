#include "NiosFighter.h"

int main() {

//	while(1){
	//create variables
	gameState gstate;
	frameTimer ftimer;
	sdcard card;
	alt_up_sd_card_dev *device_reference = NULL;
	alt_up_char_buffer_dev* char_buffer;
	alt_up_pixel_buffer_dma_dev* pixel_buffer;
	alt_up_audio_dev *audio;

	//initiation
	initGameState(&gstate);
	initFrameTimer(&ftimer);
	initsdcard(&card,&device_reference);
	InitPixBuff(&pixel_buffer);
	InitCharBuff(&char_buffer);
/*
	//gameLoop
		while(!(gstate.gameOver)) {
		startFrame(&ftimer);
		testsdcard(&card,device_reference);
		processInput(&gstate);
		updateGame(&gstate, frameLength(&ftimer));
		render(&gstate,char_buffer,pixel_buffer);
		endFrame(&ftimer);
		}
}
	 */
	/*
	 startFrame(&ftimer);
	testsdcard(&card,device_reference);
	int handle;
	handle = alt_up_sd_card_fopen("MK.wav", 0);
	if(handle)printf("file open failed");

	//setup
	av_config_setup();
	//open audio device
	alt_up_audio_dev *audio = alt_up_audio_open_dev(AUDIO_0_NAME);

	const int length=1200000;
	const int hlength=600000;
	unsigned int buffer[length/2];
	unsigned int buf [length];
	int i;



	printf("Starting to play\n");
	while(1){
		printf("Reading\n");
		for( i=0;i<length;i++){
				buf[i]=alt_up_sd_card_read(handle);
			}
			printf("Downloading\n");
			int j=0;
			for(i = 0; i<length; i+=2){
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
		while(index< 3000000){
			bytes_left = alt_up_audio_write_fifo(audio, &buffer[index_left], hlength, ALT_UP_AUDIO_LEFT);
			bytes_right = alt_up_audio_write_fifo(audio, &buffer[index_right], hlength, ALT_UP_AUDIO_RIGHT);
			index_left += bytes_left;
			index_right += bytes_right;
			index++;
		}
		printf("Reset\n");
	}



	endFrame(&ftimer);
	 */
	startFrame(&ftimer);

	testsdcard(&card,device_reference);

	int handle;
	handle = alt_up_sd_card_fopen("MK.wav", 0);
	if(handle)printf("file open failed");

	initaudio(&audio);

	sounddata data;

	initsounddata(&data,1200000);

	loadsound(&data,handle,audio);


	endFrame(&ftimer);


	/*	//creating waveform for testing
		int i;
		for(i =0; i<length; i++){
			if(i<length/2)
				buf[i]=0x4fff;
			else
				buf[i]=0x0000;}*/
	return 0;
}

void updateGame(gameState *gstate, float frameLength) {
	checkhp(gstate,&gstate->player1, &gstate->player2);
	character* p1 = &(gstate->player1);
	character* p2 = &(gstate->player2);
	checkPlayerCollisions(gstate);
	updatePlayerPosition(p1, frameLength);
	updatePlayerPosition(p2, frameLength);
	updatePlayerPunch(p1, p2, frameLength);
	updatePlayerPunch(p2, p1, frameLength);
	updatePlayerStunned(p1, frameLength);
	updatePlayerStunned(p2, frameLength);
	updateTime(gstate, frameLength);
}

void processInput(gameState *gstate) {
	input move;
	refkey(&move);
	gstate->player1.movingDirection = NOTMOVING;
	gstate->player1.wantsToPunch = 0;
	gstate->player1.wantsToBlock = 0;
	if(move.p){
		if(move.left)
			gstate->player1.movingDirection = LEFT;
		if(move.right)
			gstate->player1.movingDirection = RIGHT;
		if(move.punch)
			gstate->player1.wantsToPunch = 1;
		if(move.block)
			gstate->player1.wantsToBlock = 1;
	}

}
