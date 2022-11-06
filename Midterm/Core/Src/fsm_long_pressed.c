#include "fsm_long_pressed.h"

void fsm_long_pressed_run()
{
	// isButtonPressed(0): RESET, (1): INC, (2): DEC. Same rule applies to isButtonPressed3s()
	switch (status)
	{
	case COUNTER_INC_LONG:
		// keep pressing INC button, increase counter every 1 second
		if (isButtonPressed3s(1))
		{
			clear7SEGs();
			if (bufferValue() == 9)
				resetBuffer();
			else
				increaseBuffer(1);
			status = COUNTER_INC_LONG;
		}
		// release INC button, switch to INC
		if (isButtonPressed(1) == 0)
		{
			status = COUNTER_INC;
		}
		break;
	case COUNTER_DEC_LONG:
		// keep pressing DEC button, decrease counter every 1 second
		if (isButtonPressed3s(2))
		{
			clear7SEGs();
			if (bufferValue() == 0)
				updateBuffer(9);
			else
				decreaseBuffer(1);
			status = COUNTER_DEC_LONG;
		}
		// release DEC button, switch to DEC
		if (isButtonPressed(2) == 0)
		{
			status = COUNTER_DEC;
		}
		break;
	default:
		break;
	}
}
