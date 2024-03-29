/*
 * ATmega32_TIMER2.h
 *
 * Created: 8/1/2023 6:24:51 AM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef ATMEGA32_TIMER2_H_
#define ATMEGA32_TIMER2_H_
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
typedef struct
{
	/*
		Specifies Timer Mode (Normal mode or CTC)
		This parameter must be set based on @ref TIMER0_MODE_DEFINE
	*/
	uint8_t Timer2Mode;			

	/*
		Specifies Timer Clock Source (External / Internal) and PreScaler with internal clock only
		This parameter must be set based on @ref TIMER0_CLOCK_SOURCE_DEFINE
	*/
	uint8_t Timer2ClockSource;	
	/*
		Enable or Disable IRQ
		This parameter must be set based on @ref TIMER0_IRQ_ENABLE_DEFINE
	*/
	uint8_t Timer2IRQEnable;				
	/*
		Set the C Function which will be called once IRQ Happens
	*/
	void (*P_IRQ_CallBack)(void);	
	
}TIMER2Configuration_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/
/*********** @ref TIMER0_MODE_DEFINE **************/
#define TIMER2_MODE_NORMAL								0
#define TIMER2_MODE_CTC									1
#define TIMER2_MODE_Fast_PWM_Inverting			     	2
#define TIMER2_MODE_Fast_PWM_Noninverting		   		3
#define TIMER2_MODE_Phase_Correct_PWM_Set_DC      	   	4
#define TIMER2_MODE_Phase_Correct_PWM_Set_UC      	   	5

/******** @ref TIMER0_CLOCK_SOURCE_DEFINE *********/
#define TIMER2_CLOCK_SOURCE_INTERNAL_NO_PRESCALER		0
#define TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_8		1
#define TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_64		2
#define TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_256		3
#define TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_1024		4

/********* @ref TIMER0_IRQ_ENABLE_DEFINE **********/
#define TIMER2_IRQ_ENABLE_NONE							0
#define TIMER2_IRQ_ENABLE_TOIE2							1
#define TIMER2_IRQ_ENABLE_OCIE2							2

/********************************************
 *                                          *
 *  APIs Supported by "MCAL TIMER0 DRIVER"  *
 *  									    *
 ********************************************/
void MCAL_TIMER2_Init(TIMER2Configuration_t* TIMER2_Config);
void MCAL_TIMER2_DeInit(void);
void MCAL_TIMER2_GetCounterValue(uint8_t* TicksNumber);
void MCAL_TIMER2_SetCounterValue(uint8_t u8_TicksNumber);
void MCAL_TIMER2_GetOverflowCount(uint16_t* TicksNumber);
void MCAL_TIMER2_SetOverflowCount(uint16_t u8_TicksNumber);
void MCAL_TIMER2_GetCompareValue(uint8_t* TicksNumber);
void MCAL_TIMER2_SetCompareValue(uint8_t  TicksNumber);
void MCAL_TIMER2_SetPWMDutyCycle(uint8_t Duty_Cycle);


/******************************************
 *                                        *
 *		IRQ HANDLERS DECLRATION			  *
 *  									  *
 ******************************************/
/******************************************
*       Interrupt Vectors in ATmega32     *
*******************************************/
#define 			TIMER2_CTC_IRQHandler 					__vector_4
#define 			TIMER2_OVF_IRQHandler 					__vector_5
#define 			ISR(INT_VECT)						void INT_VECT(void) __attribute__ ((signal,used));\
														void INT_VECT(void)
														
/********************************************************
* Define indexes for the global pointer to func for ISR *
*********************************************************/
#define TIMER2_CTC_VECTOR_ID		0
#define TIMER2_OVF_VECTOR_ID		1



#endif /* ATMEGA32_TIMER2_H_ */