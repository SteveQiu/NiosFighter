#ifndef INPUT_H
#define INPUT_H
#include "io.h"
#include "altera_up_avalon_ps2.h"
#include "altera_up_ps2_keyboard.h"
#define pushbutton (char *) KEY_BASE
#define ps2_key (char *) PS2_0_BASE
#define LEFTPLAYERMOVELEFTBUTTON 1

typedef struct input{
int press;
int A;
int D;
int H;
int J;
int K;
int LARR;
int UARR;
int DARR;
int RARR;
int NP1;
int NP2;
int NP3;
int ENT;
}input;
void initKeyboard(alt_up_ps2_dev ** ps2);
int readKeyboard(input * key, alt_up_ps2_dev * ps2);
void initKey(input *key);

int isleftkey();
int isrightkey();
int ispunchkey();
int isblockkey();
void refkey(input *key);

#endif
