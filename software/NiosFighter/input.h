#ifndef INPUT_H
#define INPUT_H

typedef enum {

} key_t;

typedef struct input {

} input;

void startNewFrame(input *inp);
int keyWasPressed(int key, input *inp);
int keyWasReleased(int key, input *inp);
int keyIsHeld(int key, input *inp);

#endif //INPUT_H
