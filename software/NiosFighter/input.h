#ifndef INPUT_H
#define INPUT_H
#define pushbutton (char *) 0x00004850

typedef struct input {
int p;
int left;
int right;
int jump;
int punch;
} input;


void initkey(input *key);

int isleftkey();
int isrightkey();
int ispunchkey();
int isjumpkey();

#endif //INPUT_H
