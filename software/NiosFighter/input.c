#include "input.h"
#include "debug.h"
#include <system.h>


void initKeyboard(alt_up_ps2_dev ** ps2){
	*ps2 = alt_up_ps2_open_dev(PS2_0_NAME);
	alt_up_ps2_init(*ps2);
}
//reading from PS2 Keyboard
int readKeyboard(input * key, alt_up_ps2_dev * ps2){
	alt_u8 *buf;
	char *ascii;
	KB_CODE_TYPE *mode;
	int read;
	read = decode_scancode(ps2,mode,buf,ascii);
	if(read){
	printf("status is: %i \n",read);
	printf("key pressed is: %s \n", ascii);
	printf("buffer contains: %x \n",(unsigned)buf);
	key->press = 1;
	switch(*mode){
	case KB_ASCII_MAKE_CODE:
		if(ascii == "A")
			key->p1_left = 1;
		if(ascii == "S")
			key->p1_right = 1;
		if(ascii == "D")
			key->p1_punch = 1;
		if(ascii == "F")
			key->p1_block = 1;
		if(ascii == "H")
			key->p2_left = 1;
		if(ascii == "J")
			key->p2_right = 1;
		if(ascii == "K")
			key->p2_punch = 1;
		if(ascii == "L")
			key->p2_block = 1;
		break;
	case KB_BINARY_MAKE_CODE:
		//binary keys
		break;
	default:
		break;
	}
	return 1;
}
	return 0;
}
