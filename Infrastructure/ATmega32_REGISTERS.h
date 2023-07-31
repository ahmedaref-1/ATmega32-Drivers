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
#define TIMER0_BASE			0x23	/* TIMER0 base address */
#define TIFR_BASE			0x36	/* Timer/Counter Interrupt Flag Register base address */
#define TIMSK_BASE			0x37	/* Timer/Counter Interrupt Mask Register base address */


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
#define MCUCR   *((vuint8_t*)(IO_MAPPING_OFFSET + 0x35))
#define MCUCSR  *((vuint8_t*)(IO_MAPPING_OFFSET + 0x34))
#define GICR    *((vuint8_t*)(IO_MAPPING_OFFSET + 0x3B))
#define GIFR    *((vuint8_t*)(IO_MAPPING_OFFSET + 0x3A))


/************************************************
 *  TIMER0 PREIPHERAL REGISTERS BASE ADDRESSES  *
 ************************************************/
typedef struct
{
	/*  Output Compare Register, Address Offset: 0x23  */
	vuint8_t OCR0_;		
	
	/* Timer/Counter Register, Address Offset: 0x24  */
	vuint8_t TCNT0_;		
	
	volatile union
	{
		/*  Timer/Counter Control Register, Address Offset: 0x25  */
		vuint8_t TCCR0_;		
		struct
		{
			vuint8_t CS0n_	    :3;		/* Clock Select [n = 2:0] */
			vuint8_t WGM01_		:1;		/* Waveform Generation Mode [n=0:1] */
			vuint8_t COM0n_		:2;		/* Compare Match Output Mode [n = 1:0] */
			vuint8_t WGM00_		:1;		/* Waveform Generation Mode */
			vuint8_t FOC0_		:1;		/* Force Output Compare */
		}bits;
	}TCCR0_;
	
}TIMER0_Typedef_t;

/*
 * Timer/Counter Interrupt Mask Register , Address Offset: 0x37
 */
#define TIMSK			(*(vuint8_t*)(TIMSK_BASE + IO_MAPPING_OFFSET))

#define TOIE0			0	/* Timer/CounterTimer/Counter0 Overflow Interrupt Enable */
#define OCIE0			1	/* Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable */

/*
 * Timer/Counter Interrupt Flag Register , Address Offset: 0x36
 */
#define TIFR			(*(vuint8_t*)(TIFR_BASE + IO_MAPPING_OFFSET))

#define TOV0			0	/* Timer/Counter0 Overflow Flag */
#define OCF0			1	/* Output Compare Flag 0 */


/*********************************************
 *                                           *
 *          PERIPHERALS INSTANCES            *
 *                                           *
 *********************************************/
#define GPIOA			((GPIO_Typedef_t*) (GPIOA_BASE + IO_MAPPING_OFFSET))
#define GPIOB			((GPIO_Typedef_t*) (GPIOB_BASE + IO_MAPPING_OFFSET))
#define GPIOC			((GPIO_Typedef_t*) (GPIOC_BASE + IO_MAPPING_OFFSET))
#define GPIOD			((GPIO_Typedef_t*) (GPIOD_BASE + IO_MAPPING_OFFSET))
#define TIMER0			((TIMER0_Typedef_t*) (TIMER0_BASE + IO_MAPPING_OFFSET))


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