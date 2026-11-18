
#include "stm32f429xx.h"

int main(void)
{
	GPIO_Handle_t Led, Button;
	//Led
	Led.pGPIOx = GPIOG;
	Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	Led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOG, ENABLE);
	GPIO_Init(&Led);
	//Button
	Button.pGPIOx = GPIOA;
	Button.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	Button.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_RT;
	Button.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&Button);
	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0, ENABLE);

	while(1);
}

void EXTI0_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_NO_0);
	GPIO_ToggleOutputPin(GPIOG, GPIO_PIN_NO_13);
}
