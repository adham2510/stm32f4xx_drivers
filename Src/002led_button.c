

#include "stm32f429xx.h"

int main(void)
{

	GPIO_Handle_t Button, Led;

	Button.pGPIOx = GPIOA;
	Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	Button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	Led.pGPIOx = GPIOG;
	Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_PeriClockControl(GPIOG, ENABLE);

	GPIO_Init(&Button);
	GPIO_Init(&Led);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == ENABLE)
		{
			GPIO_WriteToOutputPin(GPIOG, GPIO_PIN_NO_14, ENABLE);
		}
		else
		{
			GPIO_WriteToOutputPin(GPIOG, GPIO_PIN_NO_14, DISABLE);
		}
	}

	return 0;

}
