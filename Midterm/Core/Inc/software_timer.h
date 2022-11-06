#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

#define TICK 10
#define SECOND 1000

extern int timerFlag;

void setTimer(int);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
