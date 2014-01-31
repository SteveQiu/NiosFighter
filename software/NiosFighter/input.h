#ifndef INPUT_H
#define INPUT_H

#define LEFTPLAYERMOVELEFTBUTTON 1

typedef struct input {

} input;

void startNewFrame(input *inp);
int keyWasPressed(int key, input *inp);
int keyWasReleased(int key, input *inp);
int keyIsHeld(int key, input *inp);

#endif //INPUT_H
