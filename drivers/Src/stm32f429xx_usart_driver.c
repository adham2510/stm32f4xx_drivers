/*
 * stm32f429xx_usart_driver.c
 *
 *  Created on: Nov 14, 2026
 *      Author: adham
 */

#include "stm32f429xx.h"

/*
 * Peripheral Clock setup
 */
/*****************************************************************
 * @fn          - USART_PeriClockControl
 *
 * @brief       - This function enables or disables peripheral
 *                clock for the given U(S)ART port
 *
 * @param[in]   - Base address of the U(S)ART peripheral
 * @param[in]   - Macros: Enable or Disable
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pUSARTx == USART1)
		{
			USART1_PCLK_EN();
		}
		else if(pUSARTx == USART2)
		{
			USART2_PCLK_EN();
		}
		else if(pUSARTx == USART3)
		{
			USART3_PCLK_EN();
		}
		else if(pUSARTx == UART4)
		{
			UART4_PCLK_EN();
		}
		else if(pUSARTx == UART5)
		{
			UART5_PCLK_EN();
		}
		else if(pUSARTx == USART6)
		{
			USART6_PCLK_EN();
		}
		else if(pUSARTx == UART7)
		{
			UART7_PCLK_EN();
		}
		else if(pUSARTx == UART8)
		{
			UART8_PCLK_EN();
		}
	}
	else
	{
		if(pUSARTx == USART1)
		{
			USART1_PCLK_DI();
		}
		else if(pUSARTx == USART2)
		{
			USART2_PCLK_DI();
		}
		else if(pUSARTx == USART3)
		{
			USART3_PCLK_DI();
		}
		else if(pUSARTx == UART4)
		{
			UART4_PCLK_DI();
		}
		else if(pUSARTx == UART5)
		{
			UART5_PCLK_DI();
		}
		else if(pUSARTx == USART6)
		{
			USART6_PCLK_DI();
		}
		else if(pUSARTx == UART7)
		{
			UART7_PCLK_DI();
		}
		else if(pUSARTx == UART8)
		{
			UART8_PCLK_DI();
		}
	}
}

/*****************************************************************
 * @fn          - USART_PeripheralControl
 *
 * @brief       - This function sets U(S)ART peripheral control
 *
 * @param[in]   - Base address of the U(S)ART peripheral
 * @param[in]   - Enable or Disable command
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDi)
{
	if(EnOrDi == ENABLE)
	{
		pUSARTx->CR1 |= (1 << 13);
	}
	else
	{
		pUSARTx->CR1 &= ~(1 << 13);
	}
}

/*
 * Init and De-Init
 */
/*****************************************************************
 * @fn          - USART_Init
 *
 * @brief       - This function initialize USART peripherals
 *
 * @param[in]   - Pointer to USART Handle structure
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void USART_Init(USART_Handle_t *pUSARTHandle)
{
	uint32_t tempreg = 0;

    /* CR1 Configuration */
    /* Enabling clock for U(S)ART peripheral */
    USART_PeriClockControl(pUSARTHandle->pUSARTx, ENABLE);

	/*USART Mode Configuration*/
	if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_TX)
	{
		/*Enabling Transmitter bit field*/
		tempreg |= (1 << USART_CR1_TE);
	}
	else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_ONLY_RX)
	{
		/*Enabling Receiver bit field*/
		tempreg |= (1 << USART_CR1_RE);
	}
	else if(pUSARTHandle->USART_Config.USART_Mode == USART_MODE_TXRX)
	{
		/*Enabling Both Transmitter and Receiver bit field*/
		tempreg |= (1 << USART_CR1_TE);
		tempreg |= (1 << USART_CR1_RE);
	}

	/*Configuring Word Length*/
	tempreg |= (pUSARTHandle->USART_Config.USART_WordLength << USART_CR1_M);

	/*Parity Control Bit Fields*/
	if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_EVEN)
	{
		 /*Enabling Parity Control, Even Parity SlectED by Default */
		tempreg |= (1 << USART_CR1_PCE);
	}
	else if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_EN_ODD)
	{
		/*Enabling Parity Control*/
		tempreg |= (1 << USART_CR1_PCE);
		/*Enabling Odd parity */
		tempreg |= (1 << USART_CR1_PS);
	}

	/*Programming CR1 Register*/
	pUSARTHandle->pUSARTx->CR1 = tempreg;

	/*CR2 Configuration*/
	tempreg = 0;

	/*Configuring Stop Bits*/
	tempreg |= (pUSARTHandle->USART_Config.USART_NoOfStopBits << USART_CR2_STOP);

	/*Programming CR2 Register*/
	pUSARTHandle->pUSARTx->CR2 = tempreg;

	/*CR3 Configuration*/
	tempreg = 0;

	/*USART Hardware Flow control Configuration*/
	if(pUSARTHandle->USART_Config.USART_NoOfStopBits == USART_HW_FLOW_CTRL_CTS)
	{
		/*Enabling CTS Flow Control*/
		tempreg |= (1 << USART_CR3_CTSE);
	}
	else if(pUSARTHandle->USART_Config.USART_NoOfStopBits == USART_HW_FLOW_CTRL_RTS)
	{
		/*Enabling RTS Flow Control*/
		tempreg |= (1 << USART_CR3_RTSE);
	}
	else if(pUSARTHandle->USART_Config.USART_NoOfStopBits == USART_HW_FLOW_CTRL_CTS_RTS)
	{
		/*Enabling both CTS and RTS Flow Control*/
		tempreg |= (1 << USART_CR3_CTSE);
		tempreg |= (1 << USART_CR3_RTSE);
	}

	/*Programming CR3 Register*/
    pUSARTHandle->pUSARTx->CR3 = tempreg;

    /*Configuring Baud Rate*/
    USART_SetBaudRate(pUSARTHandle->pUSARTx, pUSARTHandle->USART_Config.USART_Baud);
}

/*****************************************************************
 * @fn          - USART_DeInit
 *
 * @brief       - This function de-initializeS U(S)ART peripherals
 *
 * @param[in]   - Base address of the U(S)ART peripheral
 *
 * @return      - None
 *
 * @Note        - None
 *
 *****************************************************************/
void USART_DeInit(USART_RegDef_t *pUSARTx)
{
    if(pUSARTx == USART1)
    {
        USART1_REG_RESET();
    }
    else if(pUSARTx == USART2)
    {
        USART2_REG_RESET();
    }
    else if(pUSARTx == USART3)
    {
        USART3_REG_RESET();
    }
    else if(pUSARTx == UART4)
    {
        UART4_REG_RESET();
    }
    else if(pUSARTx == UART5)
    {
        UART5_REG_RESET();
    }
    else if(pUSARTx == USART6)
    {
        USART6_REG_RESET();
    }
    else if(pUSARTx == UART7)
    {
        UART7_REG_RESET();
    }
    else if(pUSARTx == UART8)
    {
        UART8_REG_RESET();
    }
}

















