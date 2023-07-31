/*
 * ATmega32_EXTERNALINTERRUPTS.h
 *
 * Created: 7/30/2023 3:55:48 AM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef ATMEGA32_EXTERNALINTERRUPTS_H_
#define ATMEGA32_EXTERNALINTERRUPTS_H_
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_REGISTERS.h"
#include "COMMONMACROS.h"
#include "PLATFORMTYPES.h"


/**********************************************
 *          	                              *
 *   PIN CONFIGURATION TYPEDEF USED BY USER   *
 *       	                                  *
 **********************************************/
typedef struct{
	// Specifies the External Interrupt GPIO mapping
	// This parameter must be set based on @ref EXTI_LineNumber define.
	uint16_t EXTI_LineNumber; 

	// Specifies Rising or Falling or both trigger.
	// This parameter must be set based on @ref EXTI_Trigger_define.
	uint8_t EXTI_TriggerCase;

	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBack)(void);

}EXTI_InterruptConfig_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/
/*******************************************
 *        @ref EXTI_LineNumber define      *
 * *****************************************/
#define EXTI_LINE0		0
#define EXTI_LINE1		1
#define EXTI_LINE2		2

/*******************************************
 *           @ref EXTI_Trigger_define        *
 * *****************************************/
#define EXTI_FALLING_EDGE	0
#define EXTI_RISING_EDGE	1
#define EXTI_LOW_LEVEL		2
#define EXTI_ON_CHANGE		3

/*****************************************************
 *                                                   *
 * EXTERNAL INTERRUPT INTERFACING MACROS DEFINITIONS *
 *                                                   *
 *****************************************************/
/********* EXTERNAL INTERRUPT 0 BITS **************/
#define GICR_INT0_BIT	6
#define MCUCR_ISC00_BIT	0
#define MCUCR_ISC01_BIT	1
#define GIFR_INTF0_BIT	6

/********* EXTERNAL INTERRUPT 1 BITS **************/
#define GICR_INT1_BIT	7
#define MCUCR_ISC10_BIT	2
#define MCUCR_ISC11_BIT	3
#define GIFR_INTF1_BIT	7

/********* EXTERNAL INTERRUPT 2 BITS **************/
#define GICR_INT2_BIT	5
#define MCUCSR_ISC2_BIT	2
#define GIFR_INTF2_BIT	5


/******************************************
 *                                        *
 *  APIs Supported by "MCAL EXTI DRIVER"  *
 *  									  *
 ******************************************/
void MCAL_EXTI_Enable( EXTI_InterruptConfig_t* interruptConfiguration );
void MCAL_EXTI_Disable( uint8_t externalInterruptLineNumber);
void MCAL_EXTI_Update (EXTI_InterruptConfig_t* EXTI_Config);


/******************************************
 *                                        *
 *		IRQ HANDLERS DECLRATION			  *
 *  									  *
 ******************************************/
void (*GPtr_IRQCallBack[3])(void) = {NULL};

#define 			EXTI0_IRQHandler 					__vector_1
#define 			EXTI1_IRQHandler 					__vector_2
#define 			EXTI2_IRQHandler 					__vector_3
#define 			ISR(INT_VECT)						void INT_VECT(void) __attribute__ ((signal,used));\
														void INT_VECT(void)

#endif /* ATMEGA32_EXTERNALINTERRUPTS_H_ */