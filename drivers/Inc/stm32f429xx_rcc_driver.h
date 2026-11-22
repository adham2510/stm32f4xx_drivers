/*
 * stm32f429xx_rcc_driver.h
 *
 *  Created on: Nov 21, 2026
 *      Author: adham
 */

#ifndef INC_STM32F429XX_RCC_DRIVER_H_
#define INC_STM32F429XX_RCC_DRIVER_H_

#include <stm32f429xx.h>

/*Returns APB1 clock value*/
uint32_t RCC_GetPCLK1Value(void);

/*Returns APB2 clock value*/
uint32_t RCC_GetPCLK2Value(void);

#endif /* INC_STM32F429XX_RCC_DRIVER_H_ */
