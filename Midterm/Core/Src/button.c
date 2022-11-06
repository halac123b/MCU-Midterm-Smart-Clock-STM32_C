#include "button.h"

// filtered button states
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

// button filter
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];

// time out value for long pressed case
int timeOut[NO_OF_BUTTONS];

// flag is on when button is pressed and released immediately
int buttonFlag[NO_OF_BUTTONS];

// flag is on when button is pressed and hold for 3s
int buttonFlag3s[NO_OF_BUTTONS];

// flag used for increment counter by 1 unit
int flagLongPressed[NO_OF_BUTTONS] = {0, 0, 0};

// button arrays
GPIO_TypeDef *port[NO_OF_BUTTONS] = {RESET_GPIO_Port, INC_GPIO_Port, DEC_GPIO_Port};
uint16_t pin[NO_OF_BUTTONS] = {RESET_Pin, INC_Pin, DEC_Pin};

void button_reading()
{
	for (int i = 0; i < NO_OF_BUTTONS; i++)
	{
		// filtering
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(port[i], pin[i]);
		if (debounceButtonBuffer3[i] == debounceButtonBuffer2[i] && debounceButtonBuffer2[i] == debounceButtonBuffer1[i])
		{
			if (buttonBuffer[i] != debounceButtonBuffer1[i])
			{ // a change in state occured
				buttonBuffer[i] = debounceButtonBuffer1[i];
				if (buttonBuffer[i] == BUTTON_IS_PRESSED)
				{ // short pressed
					if (flagLongPressed[i] == 0)
					{
						buttonFlag[i] = 1;
						timeOut[i] = LONG_PRESSED_TIME;
					}
					else
						timeOut[i] = 30;
				}
				else
					flagLongPressed[i] = 0;
			}
			else
			{
				timeOut[i]--;
				if (timeOut[i] <= 0 && debounceButtonBuffer1[i] == BUTTON_IS_PRESSED)
				{ // long pressed
					timeOut[i] = 0;
					buttonFlag3s[i] = 1;
					buttonBuffer[i] = BUTTON_IS_RELEASED;
					flagLongPressed[i] = 1;
				}
				else if (timeOut[i] <= 0)
					timeOut[i] = 0;
			}
		}
	}
}

// if button is pressed, return 1, else return 0
int isButtonPressed(int index)
{
	if (index >= NO_OF_BUTTONS)
		return 0;
	if (buttonFlag[index] == 1)
	{
		buttonFlag[index] = 0;
		return 1;
	}
	return 0;
}

// if button is pressed for 3 seconds, return 1, else return 0
int isButtonPressed3s(int index)
{
	if (index >= NO_OF_BUTTONS)
		return 0;
	if (buttonFlag3s[index] == 1)
	{
		buttonFlag3s[index] = 0;
		return 1;
	}
	return 0;
}
