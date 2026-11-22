/*
 * stm32f429xx.h
 *
 *  Created on: Oct 3, 2026
 *      Author: adham
 */

#ifndef INC_STM32F429XX_H_
#define INC_STM32F429XX_H_

#include <stdint.h>

#define __vo volatile

/*****************Processor Specific Details *****************/
/*
 * ARM Cortex Mx Processor NVIC ISERx Register Addresses
 */
#define NVIC_ISER0				((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1				((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2				((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3				((__vo uint32_t*)0xE000E10C)

/*
 * ARM Cortex Mx Processor NVIC ICERx Register Addresses
 */
#define NVIC_ICER0				((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1				((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2				((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3				((__vo uint32_t*)0XE000E18C)

/*
 * ARM Cortex Mx Processor NVIC ICERx Register Addresses
 */
#define NVIC_PR_BASEADDR		((__vo uint32_t*)0xE000E400)

/*
 * ARM Cortex Mx Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED  4

/*
 * Base addresses of FLASH and SRAM memories
 */
#define FLASH_BASEADDR 			0x08000000U
#define SRAM1_BASEADDR			0x20000000U
#define SRAM2_BASEADDR			0x2001C000U
#define ROM_BASEADDR            0x1FF00000U
#define SRAM 					SRAM1_BASEADDR

/*
 * AHBx and APBx Bus Peripheral Base Addresses
 */
#define PERIPH_BASEADDR			0x40000000U
#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR     0x40010000U
#define AHB1PERIPH_BASEADDR		0x40020000U
#define AHB2PERIPH_BASEADDR		0x50000000U
#define AHB3PERIPH_BASEADDR		0xA0000000U

/*
 * AHB1 Peripheral Base Addresses
 */
#define GPIOA_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR			(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR			(AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2000)
#define GPIOJ_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2400)
#define GPIOK_BASEADDR			(AHB1PERIPH_BASEADDR + 0x2800)
#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3800)

/*
 * APB1 Peripheral Base Addresses
 */
#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)
#define SPI2_BASEADDR			(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR			(APB1PERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR			(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR			(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR			(APB1PERIPH_BASEADDR + 0x5000)
#define UART7_BASEADDR			(APB1PERIPH_BASEADDR + 0x7800)
#define UART8_BASEADDR			(APB1PERIPH_BASEADDR + 0x7C00)

/*
 * APB2 Peripheral Base Addresses
 */
#define EXTI_BASEADDR			(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR			(APB2PERIPH_BASEADDR + 0x3800)
#define SPI1_BASEADDR			(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR			(APB2PERIPH_BASEADDR + 0x3400)
#define SPI5_BASEADDR			(APB2PERIPH_BASEADDR + 0x5000)
#define SPI6_BASEADDR			(APB2PERIPH_BASEADDR + 0x5400)
#define USART1_BASEADDR			(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR			(APB2PERIPH_BASEADDR + 0x1400)


/******************************************************************
 *			Peripheral register definition structures			  *
 *****************************************************************/

/*
 * Peripheral Register Definition Structure for GPIO
 */
typedef struct
{
    __vo uint32_t MODER;        /* GPIO port mode register,                         Address offset: 0x00    */
    __vo uint32_t OTYPER;       /* GPIO port output type register,                  Address offset: 0x04    */
    __vo uint32_t OSPEEDR;      /* GPIO port output speed register,                 Address offset: 0x08    */
    __vo uint32_t PUPDR;        /* GPIO port pull-up/down register,                 Address offset: 0x0C    */
    __vo uint32_t IDR;          /* GPIO port input data register,                   Address offset: 0x10    */
    __vo uint32_t ODR;          /* GPIO port output data register,                  Address offset: 0x14    */
    __vo uint32_t BSRR;         /* GPIO port bit set/reset register,                Address offset: 0x18    */
    __vo uint32_t LCKR;         /* GPIO port configuration lock register,           Address offset: 0x1C    */
    __vo uint32_t AFR[2];       /* AFR[0]: GPIO alternate function low register,
                                   AFR[1]: GPIO alternate function high register,   Address offset: 0x20-24 */
}GPIO_RegDef_t;


/*
 * Peripheral Register Definition Structure for RCC
 */
typedef struct
{
    __vo uint32_t CR;           /* RCC clock control register,                                  Address offset: 0x00    */
    __vo uint32_t PLLCFGR;      /* RCC PLL configuration register,                              Address offset: 0x04    */
    __vo uint32_t CFGR;         /* RCC clock configuration register,                            Address offset: 0x08    */
    __vo uint32_t CIR;          /* RCC clock interrupt register,                                Address offset: 0x0C    */
    __vo uint32_t AHB1RSTR;     /* RCC AHB1 peripheral reset register,                          Address offset: 0x10    */
    __vo uint32_t AHB2RSTR;     /* RCC AHB2 peripheral reset register,                          Address offset: 0x14    */
    __vo uint32_t AHB3RSTR;     /* RCC AHB3 peripheral reset register,                          Address offset: 0x18    */
    uint32_t      RESERVED0;    /* RCC reserved register,                                       Address offset: 0x1C    */
    __vo uint32_t APB1RSTR;     /* RCC APB1 peripheral reset register,                          Address offset: 0x20 	*/
    __vo uint32_t APB2RSTR;     /* RCC APB2 peripheral reset register,                          Address offset: 0x24    */
    uint32_t      RESERVED1[2]; /* RCC reserved register,                                       Address offset: 0x28-2C */
    __vo uint32_t AHB1ENR;      /* RCC AHB1 peripheral clock enable register,                   Address offset: 0x30    */
    __vo uint32_t AHB2ENR;      /* RCC AHB2 peripheral clock enable register,                   Address offset: 0x34    */
    __vo uint32_t AHB3ENR;      /* RCC AHB3 peripheral clock enable register,                   Address offset: 0x38    */
    uint32_t      RESERVED2;    /* RCC reserved register,                                       Address offset: 0x3C    */
    __vo uint32_t APB1ENR;      /* RCC APB1 peripheral clock enable register,                   Address offset: 0x40    */
    __vo uint32_t APB2ENR;      /* RCC APB2 peripheral clock enable register,                   Address offset: 0x44    */
    uint32_t      RESERVED3[2];	/* RCC reserved register,                                       Address offset: 0x48-4C */
    __vo uint32_t AHB1LPENR;    /* RCC AHB1 peripheral clock enable in low power mode register,	Address offset: 0x50    */
    __vo uint32_t AHB2LPENR;	/* RCC AHB2 peripheral clock enable in low power mode register,	Address offset: 0x54 	*/
    __vo uint32_t AHB3LPENR;	/* RCC AHB3 peripheral clock enable in low power mode register,	Address offset: 0x58 	*/
    uint32_t      RESERVED4;    /* RCC reserved register,                                       Address offset: 0x5C    */
    __vo uint32_t APB1LPENR;    /* RCC APB1 peripheral clock enable in low power mode register,	Address offset: 0x60    */
    __vo uint32_t APB2LPENR;    /* RCC APB2 peripheral clock enable in low power mode register,	Address offset: 0x64    */
    uint32_t      RESERVED5[2]; /* RCC reserved register,                                       Address offset: 0x68-6C */
    __vo uint32_t BDCR;         /* RCC back up domain control register,                         Address offset: 0x70    */
    __vo uint32_t CSR;          /* RCC clock control & status register,                         Address offset: 0x74    */
    uint32_t      RESERVED6[2]; /* RCC reserved register,                                       Address offset: 0x78-7C */
    __vo uint32_t SSCGR;        /* RCC spread spectrum clock generation register,               Address offset: 0x80    */
    __vo uint32_t PLLI2SCFGR;   /* RCC PLLI2S configuration register,                           Address offset: 0x84    */
    __vo uint32_t PLLSAICFGR;   /* RCC PLL configuration register,                              Address offset: 0x88    */
    __vo uint32_t DCKCFGR;      /* RCC dedicated clock configuration register,                  Address offset: 0x8C    */
    __vo uint32_t CKGATENR;     /* RCC clock gated enable register,                             Address offset: 0x90    */
    __vo uint32_t DCKCFGR2;     /* RCC dedicated clock configuration register 2,                Address offset: 0x94    */

}RCC_RegDef_t;

/*
 * Peripheral Register Definition Structure for EXTI
 */
typedef struct
{
    __vo uint32_t IMR;      /* EXTI Interrupt mask register,            Address offset: 0x00 */
    __vo uint32_t EMR;      /* EXTI Event mask register,                Address offset: 0x04 */
    __vo uint32_t RTSR;     /* EXTI Risign trigger selection register,  Address offset: 0x08 */
    __vo uint32_t FTSR;     /* EXTI Falling trigger selection register, Address offset: 0x0C */
    __vo uint32_t SWIER;    /* EXTI Software interrupt event register,  Address offset: 0x10 */
    __vo uint32_t PR;       /* EXTI Pending register,                   Address offset: 0x14 */

}EXTI_RegDef_t;

/*
 * Peripheral Register Definition Structure for SYSCFG
 */
typedef struct
{
    __vo uint32_t MEMRMP;       /* SYSCFG Memory remap register,                        Address offset: 0x00    */
    __vo uint32_t PMC;          /* SYSCFG Peripheral mode configuration register,       Address offset: 0x04    */
    __vo uint32_t EXTICR[4];    /* SYSCFG External interrupt configuration register,    Address offset: 0x08-14 */
    uint32_t      RESERVED0[2]; /* SYSCFG Reserved register,                            Address offset: 0x18-1C */
    __vo uint32_t CMPCR;        /* SYSCFG Compensation cell control register,           Address offset: 0x20    */
    uint32_t      RESERVED1[2]; /* SYSCFG Reserved register,                            Address offset: 0x24-28 */
    __vo uint32_t CFGR;         /* SYSCFG Configuration register,                       Address offset: 0x2C    */

}SYSCFG_RegDef_t;

typedef struct
{
    __vo uint32_t SR;   /* USART status register,                   Address offset: 0x00 */
    __vo uint32_t DR;   /* USART data register,                     Address offset: 0x04 */
    __vo uint32_t BRR;  /* USART baud rate register,                Address offset: 0x08 */
    __vo uint32_t CR1;  /* USART control register 1,                Address offset: 0x0C */
    __vo uint32_t CR2;  /* USART control register 2,                Address offset: 0x10 */
    __vo uint32_t CR3;  /* USART control register 3,                Address offset: 0x14 */
    __vo uint32_t GTPR; /* USART guard time and prescaler register, Address offset: 0x18 */

}USART_RegDef_t;

/*
 * Peripheral Definitions Typecasted to RegDef
 */
#define GPIOA 					((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB 					((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC					((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD 					((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE 					((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF 					((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG 					((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH 					((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI 					((GPIO_RegDef_t*) GPIOI_BASEADDR)
#define GPIOJ 					((GPIO_RegDef_t*) GPIOJ_BASEADDR)
#define GPIOK 					((GPIO_RegDef_t*) GPIOK_BASEADDR)

#define RCC						((RCC_RegDef_t*) RCC_BASEADDR)
#define EXTI 					((EXTI_RegDef_t*) EXTI_BASEADDR)
#define SYSCFG 					((SYSCFG_RegDef_t*) SYSCFG_BASEADDR)

#define USART1					((USART_RegDef_t*) USART1_BASEADDR)
#define USART2					((USART_RegDef_t*) USART2_BASEADDR)
#define USART3					((USART_RegDef_t*) USART3_BASEADDR)
#define UART4					((USART_RegDef_t*) UART4_BASEADDR)
#define UART5					((USART_RegDef_t*) UART5_BASEADDR)
#define USART6					((USART_RegDef_t*) USART6_BASEADDR)
#define UART7					((USART_RegDef_t*) UART7_BASEADDR)
#define UART8					((USART_RegDef_t*) UART8_BASEADDR)

/*
 * Clock Enable Macros for GPIOx Peripherals
 */
#define GPIOA_PCLK_EN()			(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 8))
#define GPIOJ_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 9))
#define GPIOK_PCLK_EN() 		(RCC->AHB1ENR |= (1 << 10))

/*
 * Clock Enable Macros for I2Cx Peripherals
 */
#define I2C1_PCLK_EN()			(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()			(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()			(RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros for SPIx Peripherals
 */
#define SPI1_PCLK_EN()			(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()			(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()			(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()			(RCC->APB2ENR |= (1 << 13))
#define SPI5_PCLK_EN()			(RCC->APB2ENR |= (1 << 20))
#define SPI6_PCLK_EN()			(RCC->APB2ENR |= (1 << 21))

/*
 * Clock Enable Macros for USARTx Peripherals
 */
#define USART1_PCLK_EN()			(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()			(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()			(RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()				(RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()				(RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()			(RCC->APB2ENR |= (1 << 5))
#define UART7_PCLK_EN()				(RCC->APB1ENR |= (1 << 30))
#define UART8_PCLK_EN()				(RCC->APB1ENR |= (1 << 31))

/*
 * Clock Enable Macro for SYSCFG Peripheral
 */
#define SYSCFG_PCLK_EN()			(RCC->APB2ENR |= (1 << 14))

/*
 * Clock Disable Macro for GPIOx Peripherals
 */
#define GPIOA_PCLK_DI()			(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 8))
#define GPIOJ_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 9))
#define GPIOK_PCLK_DI() 		(RCC->AHB1ENR &= ~(1 << 10))

/*
 * Reset Macros for GPIOx Peripherals
 */
#define GPIOA_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));   }while(0)
#define GPIOB_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));   }while(0)
#define GPIOC_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));   }while(0)
#define GPIOD_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));   }while(0)
#define GPIOE_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));   }while(0)
#define GPIOF_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5));   }while(0)
#define GPIOG_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6));   }while(0)
#define GPIOH_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));   }while(0)
#define GPIOI_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8));   }while(0)
#define GPIOJ_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 9)); (RCC->AHB1RSTR &= ~(1 << 9));   }while(0)
#define GPIOK_REG_RESET()		do{ (RCC->AHB1RSTR |= (1 << 10)); (RCC->AHB1RSTR &= ~(1 << 10)); }while(0)

/*
 * Macros to reset USARTx peripherals
 */
#define USART1_REG_RESET()  do{ (RCC->APB2RSTR |= (1 << 4));  (RCC->APB2RSTR &= ~(1 << 4));  }while(0)
#define USART2_REG_RESET()  do{ (RCC->APB1RSTR |= (1 << 17)); (RCC->APB1RSTR &= ~(1 << 17)); }while(0)
#define USART3_REG_RESET()  do{ (RCC->APB1RSTR |= (1 << 18)); (RCC->APB1RSTR &= ~(1 << 18)); }while(0)
#define UART4_REG_RESET()   do{ (RCC->APB1RSTR |= (1 << 19)); (RCC->APB1RSTR &= ~(1 << 19)); }while(0)
#define UART5_REG_RESET()   do{ (RCC->APB1RSTR |= (1 << 20)); (RCC->APB1RSTR &= ~(1 << 20)); }while(0)
#define USART6_REG_RESET()  do{ (RCC->APB2RSTR |= (1 << 5));  (RCC->APB2RSTR &= ~(1 << 5));  }while(0)
#define UART7_REG_RESET()   do{ (RCC->APB1RSTR |= (1 << 30)); (RCC->APB1RSTR &= ~(1 << 30)); }while(0)
#define UART8_REG_RESET()   do{ (RCC->APB1RSTR |= (1 << 31)); (RCC->APB1RSTR &= ~(1 << 31)); }while(0)

/*
 * IRQ Numbers of MCU
 */
#define IRQ_NO_EXTIO			6
#define IRQ_NO_EXTI1			7
#define IRQ_NO_EXTI2			8
#define IRQ_NO_EXTI3			9
#define IRQ_NO_EXTI4			10
#define IRQ_NO_EXTI5_9			23
#define IRQ_NO_EXTI15_10		40

/*
 * Clock Disable Macros for I2Cx Peripherals
 */
#define I2C1_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macros for SPIx Peripherals
 */
#define SPI1_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 13))
#define SPI5_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 20))
#define SPI6_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 21))

/*
 * Clock Disable Macros for USARTx Peripherals
 */
#define USART1_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()			(RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 5))
#define UART7_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 30))
#define UART8_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 31))

/*
 * Clock Disable Macro for SYSCFG Peripheral
 */
#define SYSCFG_PCLK_DI()			(RCC->APB2ENR &= ~(1 << 14))

/*
 * Returns Port Code for Given GPIOx Base Address
 */
#define GPIO_BASEADDR_TO_CODE(x)  ( (x == GPIOA)? 0 :\
									(x == GPIOB)? 1 :\
									(x == GPIOC)? 2 :\
									(x == GPIOD)? 3 :\
									(x == GPIOE)? 4 :\
									(x == GPIOF)? 5 :\
									(x == GPIOG)? 6 :\
									(x == GPIOH)? 7 :\
									(x == GPIOI)? 8 :\
									(x == GPIOJ)? 9 :\
									(x == GPIOK)? 10: 0 )
/*
 * IRQ Numbers of MCU
 */
#define IRQ_NO_EXTI0                6
#define IRQ_NO_EXTI1                7
#define IRQ_NO_EXTI2                8
#define IRQ_NO_EXTI3                9
#define IRQ_NO_EXTI4                10
#define IRQ_NO_EXIT5_9              23
#define IRQ_NO_EXIT15_10			40

/*
 * Macros for all possible priority levels
 */
#define NVIC_IRQ_PRI0       0
#define NVIC_IRQ_PRI1       1
#define NVIC_IRQ_PRI2       2
#define NVIC_IRQ_PRI3       3
#define NVIC_IRQ_PRI4       4
#define NVIC_IRQ_PRI5       5
#define NVIC_IRQ_PRI6       6
#define NVIC_IRQ_PRI7       7
#define NVIC_IRQ_PRI8       8
#define NVIC_IRQ_PRI9       9
#define NVIC_IRQ_PRI10      10
#define NVIC_IRQ_PRI11      11
#define NVIC_IRQ_PRI12      12
#define NVIC_IRQ_PRI13      13
#define NVIC_IRQ_PRI14      14
#define NVIC_IRQ_PRI15      15

/*
 * Generic Macros
 */
#define HIGH				1
#define LOW					0
#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET

/******************************************************************************************
 *						Bit position definitions of U(S)ART peripheral					  *
 ******************************************************************************************/
/*
 * Bit position definitions USART_SR
 */
#define USART_SR_PE         0
#define USART_SR_FE         1
#define USART_SR_NF         2
#define USART_SR_ORE        3
#define USART_SR_IDLE       4
#define USART_SR_RXNE       5
#define USART_SR_TC         6
#define USART_SR_TXE        7
#define USART_SR_LBD        8
#define USART_SR_CTS        9


/*
 * Bit position definitions USART_CR1
 */
#define USART_CR1_SBK       0
#define USART_CR1_RWU       1
#define USART_CR1_RE        2
#define USART_CR1_TE        3
#define USART_CR1_IDLEIE    4
#define USART_CR1_RXNEIE    5
#define USART_CR1_TCIE      6
#define USART_CR1_TXEIE     7
#define USART_CR1_PEIE      8
#define USART_CR1_PS        9
#define USART_CR1_PCE       10
#define USART_CR1_WAKE      11
#define USART_CR1_M         12
#define USART_CR1_UE        13
#define USART_CR1_OVER8     15


/*
 * Bit position definitions USART_CR2
 */
#define USART_CR2_ADD       0
#define USART_CR2_LBDL      5
#define USART_CR2_LBDIE     6
#define USART_CR2_LBCL      8
#define USART_CR2_CPHA      9
#define USART_CR2_CPOL      10
#define USART_CR2_CLKEN     11
#define USART_CR2_STOP      12
#define USART_CR2_LINEN     14


/*
 * Bit position definitions USART_CR3
 */
#define USART_CR3_EIE       0
#define USART_CR3_IREN      1
#define USART_CR3_IRLP      2
#define USART_CR3_HDSEL     3
#define USART_CR3_NACK      4
#define USART_CR3_SCEN      5
#define USART_CR3_DMAR      6
#define USART_CR3_DMAT      7
#define USART_CR3_RTSE      8
#define USART_CR3_CTSE      9
#define USART_CR3_CTSIE     10
#define USART_CR3_ONEBIT    11


#include "stm32f429xx_gpio_driver.h"
#include "stm32f429xx_usart_driver.h"
#include "stm32f429xx_rcc_driver.h"

#endif /* INC_STM32F429XX_H_ */
