/*
 * ATmega32_REGISTERS.h
 *
 * Created: 7/30/2023 3:57:46 AM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "COMMONMACROS.h"
#include "PLATFORMTYPES.h"


/******************************************
 *                                        *
 *        MEMORIES BASE ADDRESSES         *
 *                                        *
 ******************************************/
#define FLASH_MEMORY_BASE		0x00
#define SRAM_BASE				0x60


/******************************************
 *                                        *
 *     BUS PERIPHERALS BASE ADDRESSES     *
 *                                        *
 ******************************************/
/* The Constant Difference between Memory Mapped Register Address  and  IO Mapped Register Address */
#define IO_MAPPING_OFFSET	0x20

#define GPIOA_BASE			0x19	/* GPIO Port A base address */
#define GPIOB_BASE			0x16	/* GPIO Port B base address */
#define GPIOC_BASE			0x13	/* GPIO Port C base address */
#define GPIOD_BASE			0x10	/* GPIO Port D base address */


/*********************************************
 *                                           *
 *     PERIPHERALS REGISTERS BASE ADDRESSES  *
 *                                           *
 *********************************************/
/***********************************************
 *   GPIO PREIPHERAL REGISTERS BASE ADDRESSES  *
 ***********************************************/
/************ GPIO Registers' Bits ***********/
//TRM @ Section on page 49
typedef struct
{
	/* GPIO Input Pins Address */
	volatile union
	{
		vuint8_t PIN;
		struct
		{
			vuint8_t PIN0 :1;
			vuint8_t PIN1 :1;
			vuint8_t PIN2 :1;
			vuint8_t PIN3 :1;
			vuint8_t PIN4 :1;
			vuint8_t PIN5 :1;
			vuint8_t PIN6 :1;
			vuint8_t PIN7 :1;
		}bits;
	}PIN;

	/* GPIO Data Direction Register */
	volatile union
	{
		vuint8_t DDR;
		struct
		{
			vuint8_t DD0 :1;
			vuint8_t DD1 :1;
			vuint8_t DD2 :1;
			vuint8_t DD3 :1;
			vuint8_t DD4 :1;
			vuint8_t DD5 :1;
			vuint8_t DD6 :1;
			vuint8_t DD7 :1;
		}bits;
	}DDR;
	
	/* GPIO Port Register */
	volatile union
	{
		vuint8_t PORT;
		struct
		{
			vuint8_t PORT0 :1;
			vuint8_t PORT1 :1;
			vuint8_t PORT2 :1;
			vuint8_t PORT3 :1;
			vuint8_t PORT4 :1;
			vuint8_t PORT5 :1;
			vuint8_t PORT6 :1;
			vuint8_t PORT7 :1;
		}bits;
	}PORT;
	
}GPIO_Typedef_t;


/**********************************************************
 * EXTERNAL INTERRUPT PREIPHERAL REGISTERS BASE ADDRESSES *
 **********************************************************/
// EXTI MCU Control Register (EXTI_MCUCR)
typedef union{
	 vuint8_t MCUCR;
	struct{
		vuint8_t ISC00	:1;
		vuint8_t ISC01	:1;
		vuint8_t ISC10	:1;
		vuint8_t ISC11	:1;
		vuint8_t SM0	:1;
		vuint8_t SM1	:1;
		vuint8_t SM2	:1;
		vuint8_t SE		:1;
	};
}EXTI_MCUCR_t;

// EXTI MCU Control and Status Register (EXTI_MCUCSR) 
typedef union{
	vuint8_t MCUCSR;
	struct{
		vuint8_t PORF		:1;
		vuint8_t EXTRF		:1;
		vuint8_t BORF		:1;
		vuint8_t WDRF		:1;
		vuint8_t JTRF		:1;
		vuint8_t reserved	:1;
		vuint8_t ISC2		:1;
		vuint8_t JTD		:1;
	};
}EXTI_MCUCSR_t;

// EXTI General Interrupt Control Register (EXTI_GICR)
typedef union{
	vuint8_t GICR;
	struct{
		vuint8_t IVCE		:1;
		vuint8_t IVSEL		:1;
		vuint8_t reserved	:3;
		vuint8_t INT2		:1;
		vuint8_t INT0		:1;
		vuint8_t INT1		:1;
	};
}EXTI_GICR_t;

// EXTI General Interrupt Flag Register (EXTI_GIFR)
typedef union{
	vuint8_t GIFR;
	struct{
		vuint8_t reserved	:5;
		vuint8_t INTF2		:1;
		vuint8_t INTF0		:1;
		vuint8_t INTF1		:1;
	};
}EXTI_GIFR_t;


/*********************************************
 *                                           *
 *          PERIPHERALS INSTANCES            *
 *                                           *
 *********************************************/
/***********************************************
 *     GPIO PERIPHERAL INSTANCE DEFINITION     *
 ***********************************************/
#define GPIOA			((GPIO_Typedef_t*) (GPIOA_BASE + IO_MAPPING_OFFSET))
#define GPIOB			((GPIO_Typedef_t*) (GPIOB_BASE + IO_MAPPING_OFFSET))
#define GPIOC			((GPIO_Typedef_t*) (GPIOC_BASE + IO_MAPPING_OFFSET))
#define GPIOD			((GPIO_Typedef_t*) (GPIOD_BASE + IO_MAPPING_OFFSET))

/***********************************************
 *     EXTI PERIPHERAL INSTANCE DEFINITION     *
 ***********************************************/
#define MCUCR		((EXTI_MCUCR_t*)(IO_MAPPING_OFFSET + 0x35))
#define MCUCSR		((EXTI_MCUCSR_t*)(IO_MAPPING_OFFSET + 0x34))
#define GICR		((EXTI_GICR_t*)(IO_MAPPING_OFFSET + 0x3B))
#define GIFR		((EXTI_GIFR_t*)(IO_MAPPING_OFFSET + 0x3A))


/**********************************************
 *											  *
 *        GENERIC MACROS DEFINITION           *
 *         									  *
 * ********************************************/


#endif /* ATMEGA32_REGISTERS_H_ */
