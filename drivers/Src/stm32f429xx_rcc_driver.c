/*
 * stm32f429xx_rcc_driver.c
 *
 *  Created on: Nov 21, 2026
 *      Author: adham
 */

#include <stm32f429xx_rcc_driver.h>

uint16_t AHB_Prescaler[8] = {2,4,8,16,64,128,256,512};
uint8_t  APBx_Prescaler[4] = {2,4,8,16};

/*****************************************************************
 * @fn          - RCC_GetPCLK1Value
 *
 * @brief       - This function returns PClock 1 value
 *
 *
 * @return      - PClock 1 value
 *
 * @Note        - None
 *
 *****************************************************************/
uint32_t RCC_GetPCLK1Value(void)
{
	uint32_t SystemClk, pclk1;
	uint8_t temp, ahbp, apb1p, clksrc;

	/*Clock Source*/
	clksrc = ((RCC->CFGR >> 2) & 0x3);

	if(clksrc == 0)
	{
		SystemClk = ‎16000000;
	}
	else if(clksrc == 1)
	{
		SystemClk = 8000000;
	}
	else if(clksrc == 2)
	{
		//PLL
	}

	/*AHB*/
	temp = ((RCC->CFGR >> 4) & 0xF);

	if(temp < 8)
	{
		ahbp = 1;
	}
	else
	{
		ahbp = AHB_Prescale[temp - 8];
	}

	/*APB1*/
	temp = ((RCC->CFGR >> 10) & 0x7);

	if(temp < 4)
	{
		apb1p = 1;
	}
	else
	{
		apb1p = APBx_Prescale[temp - 4];
	}

	pclk1 = (SystemClk/ahbp) / apb1p;

	return pclk1;
}


/*****************************************************************
 * @fn          - RCC_GetPCLK2Value
 *
 * @brief       - This function returns PClock 2 value
 *
 *
 * @return      - PClock 2 value
 *
 * @Note        - None
 *
 *****************************************************************/
uint32_t RCC_GetPCLK2Value(void)
{
	uint32_t SystemClk, pclk2;
	uint8_t temp, ahbp, apb2p, clksrc;

	/*Clock Source*/
	clksrc = ((RCC->CFGR >> 2) & 0x3);

	if(clksrc == 0)
	{
		SystemClk = 16000000;
	}
	else if(clksrc == 1)
	{
		SystemClk = 8000000;
	}
	else if(clksrc == 2)
	{
		//PLL
	}

	/*AHB*/
	temp = ((RCC->CFGR >> 4) & 0xF);

	if(temp < 8)
	{
		ahbp = 1;
	}
	else
	{
		ahbp = AHB_Prescale[temp - 8];
	}

	/*APB1*/
	temp = ((RCC->CFGR >> 13) & 0x7);

	if(temp < 4)
	{
		apb2p = 1;
	}
	else
	{
		apb2p = APBx_Prescale[temp - 4];
	}

	pclk2 = (SystemClk/ahbp) / apb2p;

	return pclk2;
}
