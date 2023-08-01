/*
 * ATmega32_WATCHDOGTIMER.h
 *
 * Created: 8/1/2023 3:28:52 PM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef ATMEGA32_WATCHDOGTIMER_H_
#define ATMEGA32_WATCHDOGTIMER_H_
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_EXTERNALINTERRUPTS.h"
#include "ATmega32_REGISTERS.h"
#include "COMMONMACROS.h"
#include "PLATFORMTYPES.h"


/**********************************************
 *          	                              *
 * TIMER CONFIGURATION TYPEDEF USED BY USER   *
 *       	                                  *
 **********************************************/
typedef struct{

}TIMER0_TimerZeroConfig_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/



/********************************************
 *                                          *
 *  APIs Supported by "MCAL TIMER0 DRIVER"  *
 *  									    *
 ********************************************/


/******************************************
 *                                        *
 *		IRQ HANDLERS DECLRATION			  *
 *  									  *
 ******************************************/
void (*GPtr_TIMER0_IRQCallBack[2])(void) = {NULL};
/******************************************
*       Interrupt Vectors in ATmega32     *
*******************************************/
#define 			TIMER2_CTC_IRQHandler 					__vector_4
#define 			TIMER2_OVF_IRQHandler 					__vector_5
#define 			TIMER1_CAPT_IRQHandler 					__vector_6
#define 			TIMER1_CTCA_IRQHandler 					__vector_7
#define 			TIMER1_CTCB_IRQHandler 					__vector_8
#define 			TIMER1_OVF_IRQHandler 					__vector_9
#define 			TIMER0_CTC_IRQHandler 					__vector_10
#define 			TIMER0_OVF_IRQHandler 					__vector_11
#define 			ISR(INT_VECT)						void INT_VECT(void) __attribute__ ((signal,used));\
														void INT_VECT(void)
														
/********************************************************
* Define indexes for the global pointer to func for ISR *
*********************************************************/
	#define TIMER2_CTC_VECTOR_ID		4
	#define TIMER2_OVF_VECTOR_ID		5
	#define TIMER1_ICU_VECTOR_ID		6
	#define TIMER1_CTCA_VECTOR_ID		7
	#define TIMER1_CTCB_VECTOR_ID		8
	#define TIMER1_OVF_VECTOR_ID		9
	#define TIMER0_CTC_VECTOR_ID		0
	#define TIMER0_OVF_VECTOR_ID		1


#endif /* ATMEGA32_WATCHDOGTIMER_H_ */