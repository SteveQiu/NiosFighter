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
	int counter=0;
	alt_u8 buf = 0;
	char ascii;
	KB_CODE_TYPE mode;
	//printf("Pre decode\n");
	decode_scancode(ps2,&mode,&buf,&ascii);
	//printf("mode: %d, buf: %d, ascii: %c\n",mode,buf,ascii);
	//initKey(key);
	while(mode < 6 && counter <10){
			printf("mode: %d, buf: %d, ascii: %c\n",mode,buf,ascii);
			switch(mode){
			case KB_ASCII_MAKE_CODE:
				if(buf == 0x1C)
					key->A = 1;
				if(buf == 0x23)
					key->D = 1;
				if(buf == 0x33)
					key->H = 1;
				if(buf == 0x3B)
					key->J = 1;
				if(buf == 0x42)
					key->K = 1;
				if(buf == 0x69)
					key->NP1 = 1;
				if(buf == 0x72)
					key->NP2 = 1;
				if(buf == 0x7A)
					key->NP3 = 1;
				if(buf == 0x5A)
					key->ENT = 1;
				break;
			case KB_LONG_BINARY_MAKE_CODE:
				if(buf == 0x6B)
					key->LARR = 1;
				if(buf == 0x74)
					key->RARR = 1;
				if(buf == 0x75)
					key->UARR = 1;
				if(buf == 0x72)
					key->DARR = 1;
				break;
			case KB_BINARY_MAKE_CODE:
				//binary keys
				break;
			case KB_BREAK_CODE:
				if(buf == 0x1C)
					key->A = 0;
				if(buf == 0x23)
					key->D = 0;
				if(buf == 0x33)
					key->H = 0;
				if(buf == 0x3B)
					key->J = 0;
				if(buf == 0x42)
					key->K = 0;
				if(buf == 0x69)
					key->NP1 = 0;
				if(buf == 0x72)
					key->NP2 = 0;
				if(buf == 0x7A)
					key->NP3 = 0;
				if(buf == 0x5A)
					key->ENT = 0;
				break;
			case KB_LONG_BREAK_CODE:
				if(buf == 0x6B)
					key->LARR = 0;
				if(buf == 0x74)
					key->RARR = 0;
				if(buf == 0x75)
					key->UARR = 0;
				if(buf == 0x72)
					key->DARR = 0;
				break;
			default:
				break;
				}
			decode_scancode(ps2,&mode,&buf,&ascii);
			counter++;
	}

	return 0;
}
void initKey(input * key){
	key->A=0;
	key->D=0;
	key->H=0;
	key->J=0;
	key->K=0;
	key->LARR=0;
	key->RARR=0;
	key->UARR=0;
	key->DARR=0;
	key->NP1=0;
	key->NP2=0;
	key->NP3=0;
	key->ENT=0;
}

void initDE2Key(input *key) {
	key->LARR=0;
	key->RARR=0;
	key->NP1=0;
	key->NP2=0;
	key->NP3=0;
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
			key->LARR =1;
		}
		if(isrightkey())
		{
			key->RARR =1;
		}
		if(isblockkey())
		{
			key->NP2 = 1;

		}
		if(ispunchkey())
		{
			key->NP1 = 1;

		}

	}
}
