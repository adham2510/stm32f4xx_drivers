
#include "stm32f429xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}

//Led PD7		Button PE2

int main (void)
{
	GPIO_Handle_t Led, Button;

	Led.pGPIOx = GPIOD;
	Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_7;
	Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	Button.pGPIOx = GPIOE;
	Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_2;
	Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOE, ENABLE);
	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Init(&Led);
	GPIO_Init(&Button);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOE, GPIO_PIN_NO_2) == HIGH)
		{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_7, HIGH);
		}
		else
		{
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_7, LOW);
		}
	}
	return 0;
}

