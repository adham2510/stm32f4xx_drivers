
#include "stm32f429xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000/2; i++);
}

int main(void)
{
	GPIO_Handle_t Led, Button;

	Led.pGPIOx = GPIOG;
	Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	Button.pGPIOx = GPIOA;
	Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Button.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOG, ENABLE);
	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&Led);
	GPIO_Init(&Button);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == HIGH)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_14);
		}
	}

	return 0;
}
