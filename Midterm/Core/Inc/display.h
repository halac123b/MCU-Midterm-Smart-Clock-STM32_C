#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "global.h"

#define NO_OF_7SEGS 1
#define TIMER_7SEG 10

void clear7SEGs();
void clearEN();

void openEN();

void display7SEG(int);

int bufferValue();
void updateBuffer(int);
void resetBuffer();
void increaseBuffer(int);
void decreaseBuffer(int);

#endif /* INC_DISPLAY_H_ */
