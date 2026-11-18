
#include "stm32f429xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}

int main (void)
{
	GPIO_Handle_t Led;

	Led.pGPIOx = GPIOG;
	Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	Led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	Led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeriClockControl(GPIOG, ENABLE);
	GPIO_Init(&Led);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_14);
		delay();
	}

	return 0;
}

