#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "fsm_automatic.h"
#include "fsm_long_pressed.h"
#include "fsm_short_pressed.h"
#include "button.h"
#include "display.h"
#include "software_timer.h"
#include "main.h"

extern int status;

#define INIT 0
#define COUNTER_RESET 1
#define COUNTER_INC 2
#define COUNTER_DEC 3

#define COUNTER_INC_LONG 12
#define COUNTER_DEC_LONG 13

#define COUNTER_DEC_AUTO 23

#endif /* INC_GLOBAL_H_ */
