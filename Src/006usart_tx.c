/*
 * 006usart_tx.c
 *
 *  Created on: Nov 23, 2026
 *      Author: adham
 */

#include <stdio.h>
#include <string.h>
#include "stm32f429xx.h"

char msg[32] = "UART Tx testing..\n";

USART_Handle_t UART7Handle;

void USART2_Init(void)
{
	UART7Handle.pUSARTx = UART7;

	UART7Handle.USART_Config.USART_Baud = USART_STD_BAUD_9600;
	UART7Handle.USART_Config.USART_HWFlowControl = USART_HW_FLOW_CTRL_NONE;
	UART7Handle.USART_Config.USART_Mode = USART_MODE_ONLY_TX;
	UART7Handle.USART_Config.USART_NoOfStopBits = USART_STOPBITS_1;
	UART7Handle.USART_Config.USART_ParityControl = USART_PARITY_DISABLE;
	UART7Handle.USART_Config.USART_WordLength = USART_WORDLEN_8BITS;

	USART_Init(&UART7Handle);
}

/*
 * PA2->TX
 */
void USART2_GPIOInit(void)
{
	GPIO_Handle_t GPIO2Pin;

	GPIO2Pin.pGPIOx = GPIOE;

	GPIO2Pin.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFN;
	GPIO2Pin.GPIO_PinConfig.GPIO_PinAltFunMode = 7;
	GPIO2Pin.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO2Pin.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIO2Pin.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO2Pin.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;

	GPIO_Init(&GPIO2Pin);
}


void GPIO_ButtonInit(void)
{
    GPIO_Handle_t GPIOBtn;

    GPIOBtn.pGPIOx = GPIOA;

    GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
    GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_Init(&GPIOBtn);
}

void delay(void)
{
    for(uint32_t i = 0 ; i < 500000/2 ; i ++);
}


int main(void)
{
	GPIO_ButtonInit();

	USART2_GPIOInit();

	USART2_Init();

	USART_PeripheralControl(UART7, ENABLE);

	while(1)
	{
		while(! GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0));

		delay();

		USART_SendData(&UART7Handle, (uint8_t*)msg, strlen(msg));

	}

	return 0;
}
