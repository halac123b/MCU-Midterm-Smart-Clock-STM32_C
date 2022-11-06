#include "fsm_automatic.h"

void fsm_automatic_run()
{
	switch (status)
	{
	// isButtonPressed(0): RESET, (1): INC, (2): DEC. Same rule applies to isButtonPressed3s()
	case COUNTER_DEC_AUTO:
		// decrease counter every 1 second
		if (timerFlag == 1)
		{
			clear7SEGs();
			if (bufferValue() == 0)
			{
				resetBuffer();
			}
			else
			{
				decreaseBuffer(1);
			}
			status = COUNTER_DEC_AUTO;
			setTimer(1000);
		}
		// switch to RESET when buffer value = 0
		if (bufferValue() == 0)
		{
			status = COUNTER_RESET;
			setTimer(10000);
		}
		// pressed RESET, reset counter then switch to RESET
		if (isButtonPressed(0))
		{
			clear7SEGs();
			resetBuffer();
			status = COUNTER_RESET;
			setTimer(10000);
		}
		// pressed INC, increase counter then switch to INC
		if (isButtonPressed(1))
		{
			clear7SEGs();
			if (bufferValue() == 9)
				resetBuffer();
			else
				increaseBuffer(1);
			status = COUNTER_INC;
			setTimer(10000);
		}
		// pressed DEC, decrease counter then switch to DEC
		if (isButtonPressed(2))
		{
			clear7SEGs();
			if (bufferValue() == 0)
				updateBuffer(9);
			else
				decreaseBuffer(1);
			status = COUNTER_DEC;
			setTimer(10000);
		}
		break;
	default:
		break;
	}
}
