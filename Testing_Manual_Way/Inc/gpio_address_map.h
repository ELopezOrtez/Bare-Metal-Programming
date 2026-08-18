#ifndef GPIO_ADDRESS_MAP
#define GPIO_ADDRESS_MAP

#include <stdint.h>

// Got this value from the memory address section within the "DS_stm32f446re" manual
// Specifically, the block that reads "512-Mbyte Block 2 Peripherals"
#define PERIPHERALS_BASE    0x40000000UL

// Ports live within the AHB1 Address
#define AHB1_BASE           (PERIPHERALS_BASE + 0x00020000UL)

// Ports memory base addresses
#define GPIOA_BASE          (AHB1_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB1_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB1_BASE + 0x0800UL)
#define GPIOD_BASE			(AHB1_BASE + 0x0C00UL)
#define GPIOE_BASE			(AHB1_BASE + 0x1000UL)
#define GPIOF_BASE			(AHB1_BASE + 0x1400UL)
#define GPIOG_BASE			(AHB1_BASE + 0x1800UL)
#define GPIOH_BASE			(AHB1_BASE + 0x1C00UL)

// RCC Structure - Allows the GPIOx to have functionality.
// This is done by enabling clocks to their respective GPIOx (acts like a heartbeat (clock pulses), so we are giving GPIOx life)
// Overall, RCC manages clock (heartbeat) and power (saves energy through power management)
#define RCC_BASE            (AHB1_BASE + 0x3800UL)

typedef struct {
	// Register name
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED1;
	uint32_t RESERVED2;
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t RESERVED3;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED4;
	uint32_t RESERVED5;
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t RESERVED6;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED7;
	uint32_t RESERVED8;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED9;
	uint32_t RESERVED10;
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
	uint32_t PLLSAICFGR;
	uint32_t DCKCFGR;
	uint32_t CKGATENR;
	uint32_t DCKCFGR2;
} RCC_TypeDef;

#define RCC ((RCC_TypeDef *) RCC_BASE)

// GPIO Structure
typedef struct {
	// Register name
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDER;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;
} GPIO_TypeDef;

// Peripheral Pointers
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *) GPIOH_BASE)

// SysTick Structure (needed to create delay_ms and so forth using the M-Cortex chip)
#define SYSTICK_BASE        0xE000E010UL // base address can be found in "pm0214-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics"

typedef struct {
	uint32_t CTRL;
	uint32_t LOAD;
	uint32_t VAL;
	uint32_t CALIB;
} SYSTICK_TypeDef;

#define SYSTICK              ((SYSTICK_TypeDef *) SYSTICK_BASE)
#define SYSTICK_LOAD         ((32000000 / 1000) - 1) // 32MHz, but can be changed to 16MHz, 8MHz, ... for system clock

// Pins (Total: 15 - Base on the manual "um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics")
#define PIN_0                (0U)
#define PIN_1                (1U)
#define PIN_2                (2U)
#define PIN_3                (3U)
#define PIN_4                (4U)
#define PIN_5                (5U)
#define PIN_6                (6U)
#define PIN_7                (7U)
#define PIN_8                (8U)
#define PIN_9                (9U)
#define PIN_10               (10U)
#define PIN_11               (11U)
#define PIN_12               (12U)
#define PIN_13               (13U)
#define PIN_14               (14U)
#define PIN_15               (15U)

#endif
