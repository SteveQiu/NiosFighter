#include "input.h"
#include "debug.h"

void initkey(input *key) {
	key->p = 0;
	key->block = 0;
	key->punch = 0;
	key->left = 0;
	key->right = 0;
}

int isleftkey(){
	if(!(*pushbutton & 0x02))
		return 1;
	else
		return 0;
}
int isrightkey(){
	if(!(*pushbutton & 0x01))
		return 1;
	else
		return 0;
}

int ispunchkey(){
	if(!(*pushbutton & 0x04))
		return 1;
	else
		return 0;
}

int isblockkey(){
	if(!(*pushbutton & 0x08))
		return 1;
	else
		return 0;
}

void refkey(input *key){
	initkey(key);
	if(*pushbutton == 0x0f)
		initkey(key);
	else
	{
		//bug: tolerate multi key pressed
		if(isleftkey()){
			key->p =1;
			key->left =1;
			DEBUGMSG("Moving Left");
		}
		if(isrightkey())
		{	key->right =1;
			key->p =1;
			DEBUGMSG("Moving Right");
		}
		if(isblockkey())
		{	key->block = 1;
			key->p =1;
			DEBUGMSG("Blocking");
		}
		if(ispunchkey())
		{	key->punch = 1;
			key->p =1;
			DEBUGMSG("Hitting");
		}

	}
}
