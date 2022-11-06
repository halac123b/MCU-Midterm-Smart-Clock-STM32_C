#include "display.h"

int led_buffer[NO_OF_7SEGS] = {0}; // buffer for LED 7SEG

// turn off LED 7SEG
void clear7SEGs()
{
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, GPIO_PIN_SET);
}

// disable EN pin
void clearEN()
{
	HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
}

// enable EN pin
void openEN()
{
	HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
}

// display counter value
void display7SEG(int counter)
{
	if (counter == 0)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 1)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 2)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin | SEG4_Pin | SEG6_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 3)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG6_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 4)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin | SEG5_Pin | SEG6_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 5)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 6)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 7)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 8)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, GPIO_PIN_RESET);
	}
	else if (counter == 9)
	{
		clear7SEGs();
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, GPIO_PIN_RESET);
	}
}

// reset buffer value to 0 then display
void resetBuffer()
{
	led_buffer[0] = 0;
	display7SEG(led_buffer[0]);
}

// increase buffer value by 1 unit then display
void increaseBuffer(int value)
{
	led_buffer[0] += value;
	display7SEG(led_buffer[0]);
}

// decrease buffer value by 1 unit then display
void decreaseBuffer(int value)
{
	led_buffer[0] -= value;
	display7SEG(led_buffer[0]);
}

// update buffer value with a specific number then display
void updateBuffer(int value)
{
	led_buffer[0] = value;
	display7SEG(led_buffer[0]);
}

// return current buffer value
int bufferValue()
{
	return led_buffer[0];
}
