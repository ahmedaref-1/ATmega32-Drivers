/*
 * ATmega32_TIMER1.h
 *
 * Created: 8/1/2023 6:25:21 AM
 *  Author: ahmed
 */ 


#ifndef ATMEGA32_TIMER1_H_
#define ATMEGA32_TIMER1_H_
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
void (*GPtr_TIMER1_IRQCallBack[4])(void) = {NULL};
/******************************************
*       Interrupt Vectors in ATmega32     *
*******************************************/
#define 			TIMER1_CAPT_IRQHandler 					__vector_6
#define 			TIMER1_CTCA_IRQHandler 					__vector_7
#define 			TIMER1_CTCB_IRQHandler 					__vector_8
#define 			TIMER1_OVF_IRQHandler 					__vector_9
#define 			ISR(INT_VECT)						void INT_VECT(void) __attribute__ ((signal,used));\
														void INT_VECT(void)
														
/********************************************************
* Define indexes for the global pointer to func for ISR *
*********************************************************/
	#define TIMER1_ICU_VECTOR_ID		0
	#define TIMER1_CTCA_VECTOR_ID		1
	#define TIMER1_CTCB_VECTOR_ID		2
	#define TIMER1_OVF_VECTOR_ID		3


#endif /* ATMEGA32_TIMER1_H_ */