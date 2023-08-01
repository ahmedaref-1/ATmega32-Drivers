/*
 * ATmega32_TIMER0.h
 *
 * Created: 8/1/2023 6:24:51 AM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef ATMEGA32_TIMER0_H_
#define ATMEGA32_TIMER0_H_
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
	// This parameter can be sit by the user with any value.
	uint8_t TIMER0_PreloadValue;
	// This parameter must be set based on @ref InterruptEnable define.
	uint8_t TIMER0_OverFlowInterrupt;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBack)(void);
}TIMER0_Timer0NormalModeConfig_t;

typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER0_ClearTimerOnCompareMatchValue;
	// This parameter must be set based on @ref ClearTimerOnCompareMatchPWMMode define.
	uint8_t TIMER0_ClearTimerOnCompareMatchPWMMode;
}TIMER0_Timer0PWMModeConfig_t;

typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER0_ClearTimerOnCompareMatchValue;
	// This parameter must be set based on @ref OutputCompareMatchMode define.
	uint8_t TIMER0_OutputCompareMatchMode;
	// This parameter must be set based on @ref InterruptEnable define.
	uint8_t TIMER0_ClearOnCompareMatchInterrupt;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBack)(void);
}TIMER0_Timer0CTCModeConfig_t;

typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER0_ClearTimerOnCompareMatchValue;
	// This parameter must be set based on @ref OutputCompareMatchMode define.
	uint8_t TIMER0_OutputCompareMatchMode;
}TIMER0_Timer0FastPWMModeConfig_t;

typedef struct{
	// This parameter must be set based on @ref WaveFormGenerationMode define.
	uint8_t TIMER0_WaveFormGenerationMode; 
	// This parameter must be set based on @ref Prescaler define.
	uint8_t TIMER0_Prescaler;
	// This parameter contains the normal mode configuration.
	TIMER0_Timer0NormalModeConfig_t timer0NormalModeConfiguration;
	// This parameter contains the PWM mode configuration.
	TIMER0_Timer0PWMModeConfig_t timer0PWMModeConfiguration;
	// This parameter contains the CTC mode configuration.
	TIMER0_Timer0CTCModeConfig_t timer0CTCModeConfiguration;
	// This parameter contains the Fast PWM mode configuration.
	TIMER0_Timer0FastPWMModeConfig_t timer0FastPWMModeConfiguration;
	
}TIMER0_Timer0Config_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/
/***** @ref WaveFormGenerationMode define ******/
#define TIMER0_NORMAL_MODE		0
#define TIMER0_PWM_MODE			1
#define TIMER0_CTC_MODE			2
#define TIMER0_FAST_PWM_MODE	3

/************ @ref Prescaler define ***********/
#define TIMER0_NO_CLOCK_SOURCE	 	                    0
#define TIMER0_NO_PRESCALER_FACTOR 	                    1
#define TIMER0_DIVISION_FACTOR_8	 	                2
#define TIMER0_DIVISION_FACTOR_64	                    3
#define TIMER0_DIVISION_FACTOR_256	                    4
#define TIMER0_DIVISION_FACTOR_1024	                    5
#define TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
#define TIMER0_EXTERNAL_CLOCK_SOURCE_RISING	        7

/************ @ref InterruptEnable define ***********/
#define DISABLE						                    0
#define ENABLE						                    1

/***** @ref ClearTimerOnCompareMatchPWMMode define ***/
#define TIMER0_OC_DISCONNECTED							0
#define TIMER0_CLR_ON_CTC_SET_ON_TOP				    1
#define TIMER0_SET_ON_CTC_CLR_ON_TOP				    2

/*********** @ref OutputCompareMatchMode *************/
#define TIMER0_OC_DISCONNECTED					        0
#define TIMER0_OC_TOGGEL							    1
#define TIMER0_OC_LOW							        2
#define TIMER0_OC_HIGH							        3

/********************************************
 *                                          *
 *  APIs Supported by "MCAL TIMER0 DRIVER"  *
 *  									    *
 ********************************************/
void MCAL_TIMER0_Init(TIMER0_Timer0Config_t* Timer0Configuration) ;
uint8_t MCAL_TIMER0_GetTimerCounterValue (void) ;

/******************************************
 *                                        *
 *		IRQ HANDLERS DECLRATION			  *
 *  									  *
 ******************************************/
void (*GPtr_TIMER0_IRQCallBack[2])(void) = {NULL};
/******************************************
*       Interrupt Vectors in ATmega32     *
*******************************************/
#define 			TIMER0_CTC_IRQHandler 					__vector_10
#define 			TIMER0_OVF_IRQHandler 					__vector_11
#define 			ISR(INT_VECT)						void INT_VECT(void) __attribute__ ((signal,used));\
														void INT_VECT(void)
														
/********************************************************
* Define indexes for the global pointer to func for ISR *
*********************************************************/
#define TIMER0_CTC_VECTOR_ID		0
#define TIMER0_OVF_VECTOR_ID		1



#endif /* ATMEGA32_TIMER0_H_ */