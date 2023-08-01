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


/**********************************************************
 *      TIMERS PREIPHERAL REGISTERS BASE ADDRESSES        *
 **********************************************************/
//Timer/Counter Interrupt Mask Register (TIMSK)
typedef union{
	vuint8_t TIMSK;
	struct{
		vuint8_t TOIE0		:1;
		vuint8_t OCIE0		:1;
		vuint8_t TOIE1		:1;
		vuint8_t OCIE1B		:1;
		vuint8_t OCIE1A		:1;
		vuint8_t TICIE1		:1;
		vuint8_t TOIE2		:1;
		vuint8_t OCIE2		:1;
	};
}TIMERS_TIMSK_t;

//Timer/Counter Interrupt Flag Register (TIFR)
typedef union{
	vuint8_t TIFR;
	struct{
		vuint8_t TOV0		:1;
		vuint8_t OCF0		:1;
		vuint8_t TOV1		:1;
		vuint8_t OCF1B		:1;
		vuint8_t OCF1A		:1;
		vuint8_t ICF1		:1;
		vuint8_t TOV2		:1;
		vuint8_t OCF2		:1;
	};
}TIMERS_TIFR_t;

/********** TIMER 0 REGISTERS ***************/
//Timer/Counter0 Control Register (TCCR0)
typedef union{
	vuint8_t TCCR0;
	struct{
		vuint8_t CS00		:1;
		vuint8_t CS01		:1;
		vuint8_t CS02		:1;
		vuint8_t WGM01		:1;
		vuint8_t COM00		:1;
		vuint8_t COM01		:1;
		vuint8_t WGM00		:1;
		vuint8_t FOC0		:1;
	};
}TIMER0_TCCR0_t;

#define TCNT0			(*((vuint8_t*)	(0X52)))
#define OCR0			(*((vuint8_t*)	(0X5C)))

/********** TIMER 1 REGISTERS ***************/
//Timer/Counter1 Control Register A (TCCR1A)
typedef union{
	vuint8_t TCCR1A;
	struct{
		vuint8_t WGM10		:1;
		vuint8_t WGM11		:1;
		vuint8_t FOC1B		:1;
		vuint8_t FOC1A		:1;
		vuint8_t COM1B0		:1;
		vuint8_t COM1B1		:1;
		vuint8_t COM1A0		:1;
		vuint8_t COM1A1		:1;
	};
}TIMER1_TCCR1A_t;

//Timer/Counter1 Control Register B (TCCR1B)
typedef union{
	vuint8_t TCCR1B;
	struct{
		vuint8_t CS10			:1;
		vuint8_t CS11			:1;
		vuint8_t CS12			:1;
		vuint8_t WGM12			:1;
		vuint8_t WGM13			:1;
		vuint8_t reserved		:1;
		vuint8_t ICES1			:1;
		vuint8_t ICNC1			:1;
	};
}TIMER1_TCCR1B_t;

#define TCNT1L          (*((vuint8_t*)	(0x4C)))
#define TCNT1H          (*((vuint8_t*)	(0x4D)))
#define TCNT1			(*((vuint16_t*)	(0X4C)))    
#define OCR1AL          (*((vuint8_t *)	(0x4A)))
#define OCR1AH          (*((vuint8_t*)	(0x4B)))
#define OCR1A			(*((vuint16_t*)	(0X4A)))
#define OCR1BL          (*((vuint8_t*)	(0x48)))
#define OCR1BH          (*((vuint8_t*)	(0x49)))
#define OCR1B			(*((vuint16_t*)	(0X48)))
#define ICR1L           (*((vuint8_t*)	(0x46)))
#define ICR1H           (*((vuint8_t*)	(0x47)))
#define ICR1			(*((vuint16_t*)	(0X46)))

/********** TIMER 2 REGISTERS ***************/
//Timer/Counter2 Control Register (TCCR2)
typedef union{
	vuint8_t TCCR2;
	struct{
		vuint8_t CS20		:1;
		vuint8_t CS21		:1;
		vuint8_t CS22		:1;
		vuint8_t WGM21		:1;
		vuint8_t COM20		:1;
		vuint8_t COM21		:1;
		vuint8_t WGM20		:1;
		vuint8_t FOC2		:1;
	};
}TIMER2_TCCR2_t;

#define TCNT2			(*((vuint8_t*)	(0X44)))
#define OCR2			(*((vuint8_t*)	(0X43)))

/********* WATCHDOG TIMER REGISTER ***************/
//Watchdog Timer Control Register (WDTCR) 
typedef union{
	vuint8_t WDTCR;
	struct{
		vuint8_t WDP0			:1;
		vuint8_t WDP1			:1;
		vuint8_t WDP2			:1;
		vuint8_t WDE			:1;
		vuint8_t WDTOE			:1;
		vuint8_t reserved		:3;
	};
}TIMERS_WDTCR_t;


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
#define MCUCR		((EXTI_MCUCR_t*)	(IO_MAPPING_OFFSET + 0x35))
#define MCUCSR		((EXTI_MCUCSR_t*)	(IO_MAPPING_OFFSET + 0x34))
#define GICR		((EXTI_GICR_t*)		(IO_MAPPING_OFFSET + 0x3B))
#define GIFR		((EXTI_GIFR_t*)		(IO_MAPPING_OFFSET + 0x3A))

/***********************************************
 *    TIMERS PERIPHERAL INSTANCE DEFINITION    *
 ***********************************************/
#define TIMSK		((TIMERS_TIMSK_t*)	(IO_MAPPING_OFFSET + 0x39))
#define TIFR		((TIMERS_TIFR_t *)	(IO_MAPPING_OFFSET + 0x38))
#define TCCR0		((TIMER0_TCCR0_t*)	(IO_MAPPING_OFFSET + 0x33))
#define TCCR1A		((TIMER1_TCCR1A_t*)	(IO_MAPPING_OFFSET + 0x2F))
#define TCCR1B		((TIMER1_TCCR1B_t*)	(IO_MAPPING_OFFSET + 0x2E))
#define TCCR2		((TIMER2_TCCR2_t*)	(IO_MAPPING_OFFSET + 0x25))
#define WDTCR		((TIMERS_WDTCR_t*)	(IO_MAPPING_OFFSET + 0x21))


/**********************************************
 *											  *
 *        GENERIC MACROS DEFINITION           *
 *         									  *
 * ********************************************/
/************************************************
 *              Interrupt MACROS                *
 ************************************************/
#define SREG_BASE		0x3F
#define SREG			(*(vuint8_t*)(SREG_BASE + IO_MAPPING_OFFSET))
#define I_Bit			7

#define Enable_GlobalInterrupt()	SREG |= (1 << I_Bit)
#define Disable_GlobalInterrupt()	SREG &= ~(1 << I_Bit)
#endif /* ATMEGA32_REGISTERS_H_ */
