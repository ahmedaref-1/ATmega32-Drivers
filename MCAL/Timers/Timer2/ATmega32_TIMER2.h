/*
 * ATmega32_TIMER2.h
 *
 * Created: 8/1/2023 6:26:44 AM
 *  Author: ahmed
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
typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER2_PreloadValue;
	// This parameter must be set based on @ref InterruptEnable define.
	uint8_t TIMER2_OverFlowInterrupt;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBack)(void);
}TIMER2_Timer2NormalModeConfig_t;

typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER2_ClearTimerOnCompareMatchValue;
	// This parameter must be set based on @ref ClearTimerOnCompareMatchPWMMode define.
	uint8_t TIMER2_ClearTimerOnCompareMatchPWMMode;
}TIMER2_Timer2PWMModeConfig_t;

typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER2_ClearTimerOnCompareMatchValue;
	// This parameter must be set based on @ref OutputCompareMatchMode define.
	uint8_t TIMER2_OutputCompareMatchMode;
	// This parameter must be set based on @ref InterruptEnable define.
	uint8_t TIMER2_ClearOnCompareMatchInterrupt;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBack)(void);
}TIMER2_Timer2CTCModeConfig_t;
typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER2_ClearTimerOnCompareMatchValue;
	// This parameter must be set based on @ref OutputCompareMatchMode define.
	uint8_t TIMER2_OutputCompareMatchMode;
}TIMER2_Timer2FastPWMModeConfig_t;

typedef struct{
	// This parameter must be set based on @ref WaveFormGenerationMode define.
	uint8_t TIMER2_WaveFormGenerationMode;
	// This parameter must be set based on @ref Prescaler define.
	uint8_t TIMER2_Prescaler;
	// This parameter contains the normal mode configuration.
	TIMER2_Timer2NormalModeConfig_t timer2NormalModeConfiguration;
	// This parameter contains the PWM mode configuration.
	TIMER2_Timer2PWMModeConfig_t timer2PWMModeConfiguration;
	// This parameter contains the CTC mode configuration.
	TIMER2_Timer2CTCModeConfig_t timer2CTCModeConfiguration;
	// This parameter contains the Fast PWM mode configuration.
	TIMER2_Timer2FastPWMModeConfig_t timer2FastPWMModeConfiguration;
	
}TIMER2_Timer2Config_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/
/***** @ref WaveFormGenerationMode define ******/
#define TIMER2_NORMAL_MODE		0
#define TIMER2_PWM_MODE			1
#define TIMER2_CTC_MODE			2
#define TIMER2_FAST_PWM_MODE	3

/************ @ref Prescaler define ***********/
#define TIMER2_NO_CLOCK_SOURCE	 	                    0
#define TIMER2_NO_PRESCALER_FACTOR 	                    1
#define TIMER2_DIVISION_FACTOR_8	 	                2
#define TIMER2_DIVISION_FACTOR_64	                    3
#define TIMER2_DIVISION_FACTOR_256	                    4
#define TIMER2_DIVISION_FACTOR_1024	                    5
#define TIMER2_EXTERNAL_CLOCK_SOURCE_FALLING	        6
#define TIMER2_EXTERNAL_CLOCK_SOURCE_RISING	        7

/************ @ref InterruptEnable define ***********/
#define DISABLE						                    0
#define ENABLE						                    1

/***** @ref ClearTimerOnCompareMatchPWMMode define ***/
#define TIMER2_OC_DISCONNECTED							0
#define TIMER2_CLR_ON_CTC_SET_ON_TOP				    1
#define TIMER2_SET_ON_CTC_CLR_ON_TOP				    2

/*********** @ref OutputCompareMatchMode *************/
#define TIMER2_OC_DISCONNECTED					        0
#define TIMER2_OC_TOGGEL							        1
#define TIMER2_OC_LOW							        2
#define TIMER2_OC_HIGH							        3

/********************************************
 *                                          *
 *  APIs Supported by "MCAL TIMER0 DRIVER"  *
 *  									    *
 ********************************************/
void MCAL_TIMER2_Init(TIMER2_Timer2Config_t* Timer2Configuration) ;
uint8_t MCAL_TIMER2_GetTimerCounterValue (void) ;


/******************************************
 *                                        *
 *		IRQ HANDLERS DECLRATION			  *
 *  									  *
 ******************************************/
void (*GPtr_TIMER2_IRQCallBack[2])(void) = {NULL};
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