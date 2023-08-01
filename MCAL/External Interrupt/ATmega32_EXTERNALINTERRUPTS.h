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
#define EXTI_PD2			EXTI_LINE0
#define EXTI_PD3			EXTI_LINE1
#define EXTI_PB2			EXTI_LINE2

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
/************* EXTERNAL INTERRUPT 0 ******************/
#define EXTI_LINE0			0

/************* EXTERNAL INTERRUPT 1 ******************/
#define EXTI_LINE1			1

/************* EXTERNAL INTERRUPT 2 ******************/
#define EXTI_LINE2			2


/******************************************
 *                                        *
 *  APIs Supported by "MCAL EXTI DRIVER"  *
 *  									  *
 ******************************************/
void MCAL_EXTI_Enable( EXTI_InterruptConfig_t* interruptConfiguration );
void MCAL_EXTI_Disable( uint8_t externalInterruptLineNumber);
void MCAL_EXTI_Update (EXTI_InterruptConfig_t* interruptConfiguration);


/******************************************
 *                                        *
 *		IRQ HANDLERS DECLRATION			  *
 *  									  *
 ******************************************/
void (*GPtr_EXTI_IRQCallBack[3])(void) = {NULL};
/******************************************
*       Interrupt Vectors in ATmega32     *
*******************************************/
#define 			EXTI0_IRQHandler 						__vector_1
#define 			EXTI1_IRQHandler 						__vector_2
#define 			EXTI2_IRQHandler 						__vector_3
#define 			ISR(INT_VECT)						void INT_VECT(void) __attribute__ ((signal,used));\
														void INT_VECT(void)
														
/********************************************************
* Define indexes for the global pointer to func for ISR *
*********************************************************/
	#define EXT_INT0_VECTOR_ID			0
	#define EXT_INT1_VECTOR_ID			1
	#define EXT_INT2_VECTOR_ID			2
	
#endif /* ATMEGA32_EXTERNALINTERRUPTS_H_ */
