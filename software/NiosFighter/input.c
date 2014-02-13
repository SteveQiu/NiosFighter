#include "input.h"
#include "debug.h"
#include <system.h>


void initKeyboard(alt_up_ps2_dev ** ps2){
	*ps2 = alt_up_ps2_open_dev(PS2_0_NAME);
	alt_up_ps2_init(*ps2);
	alt_up_ps2_clear_fifo(*ps2);
}
//reading from PS2 Keyboard
int readKeyboard(input * key, alt_up_ps2_dev * ps2){
	alt_u8 buf = 0;
	char ascii;
	KB_CODE_TYPE mode;
	//printf("Pre decode\n");
	decode_scancode(ps2,&mode,&buf,&ascii);
	//printf("mode: %d, buf: %d, ascii: %c\n",mode,buf,ascii);
	//initKey(key);
	while(mode<=5){
			//printf("mode: %d, buf: %d, ascii: %c\n",mode,buf,ascii);
			key->press = 1;
			switch(mode){
			case KB_ASCII_MAKE_CODE:
				if(ascii == 'A')
					key->p1_left = 1;
				if(ascii == 'S')
					key->p1_right = 1;
				if(ascii == 'D')
					key->p1_punch = 1;
				if(ascii == 'F')
					key->p1_block = 1;
				break;
			case KB_BINARY_MAKE_CODE:
				//binary keys
				break;
			case KB_BREAK_CODE:
				//if (ascii == 'A')
					key->p1_left=0;
				//if (ascii == 'S')
					key->p1_right=0;
				//if (ascii == 'D')
					key->p1_punch=0;
				//if (ascii == 'F')
					key->p1_block=0;
				break;
			default:
				break;
				}
			decode_scancode(ps2,&mode,&buf,&ascii);

	}

	return 0;
}
void initKey(input * key){
	key->p1_block=0;
	key->p1_left=0;
	key->p1_punch=0;
	key->p1_right=0;
}

void initDE2Key(input *key) {
	key->p2_block=0;
	key->p2_left=0;
	key->p2_punch=0;
	key->p2_right=0;
}

int isleftkey(){
	if(!(IORD_8DIRECT(KEY_BASE, 0) & 0x02))
		return 1;
	else
		return 0;
}
int isrightkey(){
	if(!(IORD_8DIRECT(KEY_BASE, 0) & 0x01))
		return 1;
	else
		return 0;
}

int ispunchkey(){
	if(!(IORD_8DIRECT(KEY_BASE, 0) & 0x04))
		return 1;
	else
		return 0;
}

int isblockkey(){
	if(!(IORD_8DIRECT(KEY_BASE, 0) & 0x08))
		return 1;
	else
		return 0;
}

void refkey(input *key){
	initDE2Key(key);
	if(IORD_8DIRECT(KEY_BASE, 0) == 0x0f)
		initDE2Key(key);
	else
	{
		//bug: tolerate multi key pressed
		if(isleftkey()){
			key->press =1;
			key->p2_left =1;
		}
		if(isrightkey())
		{	key->p2_right =1;
			key->press =1;
		}
		if(isblockkey())
		{	key->p2_block = 1;
			key->press =1;
		}
		if(ispunchkey())
		{	key->p2_punch = 1;
			key->press =1;
		}

	}
}
