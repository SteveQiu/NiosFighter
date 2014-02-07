#ifndef INPUT_H
#define INPUT_H
#include "io.h"
#define pushbutton (char *) KEY_BASE
#define ps2_key (char *) PS2_0_BASE
#define LEFTPLAYERMOVELEFTBUTTON 1

typedef struct input {
int p;
int left;
int right;
int block;
int punch;
} input;


void initkey(input *key);

int isleftkey();
int isrightkey();
int ispunchkey();
int isblockkey();
void refkey(input *key);
#endif //INPUT_H
