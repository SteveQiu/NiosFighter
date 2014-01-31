#ifndef INPUT_H
#define INPUT_H
#define pushbutton (char *) 0x00004850

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
int isjumpkey();
void refkey(input *key);
#endif //INPUT_H
