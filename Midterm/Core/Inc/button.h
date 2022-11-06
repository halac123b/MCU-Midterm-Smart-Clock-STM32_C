#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NO_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

#define DOUBLE_PRESSED_TIME 30
#define LONG_PRESSED_TIME 300

void button_reading();
int isButtonPressed(int);
int isButtonPressed3s(int);

#endif /* INC_BUTTON_H_ */
