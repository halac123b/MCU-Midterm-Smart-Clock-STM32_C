#include "software_timer.h"

// flag is on after a specific duration
int timerFlag = 0;

// counter to determine if flag is on or not
int counter = 0;

// set counter and reset flag
void setTimer(int duration)
{
	counter = duration / TICK; // TICK = 10
	timerFlag = 0;
}

// decrease counter and check if flag is on or not
void timerRun()
{
	if (counter > 0)
	{
		counter--;
		if (counter <= 0)
		{
			timerFlag = 1;
		}
	}
}

int counter_led = 50; // counter for DEBUG_LED

// timer callback
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
	{
		timerRun();
		button_reading();
		counter_led--;
		// toggle DEBUG_LED
		if (counter_led <= 0)
		{
			counter_led = 50;
			HAL_GPIO_TogglePin(GPIOA, DEBUG_LED_Pin);
		}
	}
}
