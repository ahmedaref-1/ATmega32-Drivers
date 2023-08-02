/*
 * ATmega32_TIMER1.h
 *
 * Created: 8/1/2023 6:25:21 AM
 *  Author: Ahmed Aref Omaira
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
	// This parameter can be sit by the user with any value.
	uint8_t TIMER1_PreloadValue;
	// This parameter must be set based on @ref InterruptEnable define.
	uint8_t TIMER1_OverFlowInterrupt;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBack)(void);
}TIMER1_Timer1NormalModeConfig_t;

typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER1_ClearTimerOnCompareMatchValueA;
	uint8_t TIMER1_ClearTimerOnCompareMatchValueB;
	// This parameter can be sit by the user with any value.
	uint8_t TIMER1_InputCaptureValue;
	// This parameter must be set based on @ref inputCaptureEdge define.
	uint8_t TIMER1_InputCaptureEdge;
	// Those parameters must be set based on @ref OutputCompareMatchMode define.
	uint8_t TIMER1_OutputCompareMatchModeA;
	uint8_t TIMER1_OutputCompareMatchModeB;
	// This parameter must be set based on @ref ClearTimerOnCompareMatchPWMMode define.
	uint8_t TIMER1_ClearTimerOnCompareMatchPWMMode;
	// Those parameters must be set based on @ref InterruptEnable define.
	uint8_t TIMER1_OverFlowInterrupt;
	uint8_t TIMER1_ClearOnCompareMatchInterruptA;
	uint8_t TIMER1_ClearOnCompareMatchInterruptB;
	uint8_t TIMER1_InputCaptureInterrupt;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBackOVF)(void);
	void(*P_IRQ_CallBackCTCA)(void);
	void(*P_IRQ_CallBackCTCB)(void);
	void(*P_IRQ_CallBackICR)(void);
}TIMER1_Timer1PWMModeConfig_t;

typedef struct{
	// Those parameters can be sit by the user with any value.
	uint8_t TIMER1_ClearTimerOnCompareMatchValueA;
	uint8_t TIMER1_ClearTimerOnCompareMatchValueB;
	// This parameter can be sit by the user with any value.
	uint8_t TIMER1_InputCaptureValue;
	// This parameter must be set based on @ref inputCaptureEdge define.
	uint8_t TIMER1_InputCaptureEdge;
	// Those parameters must be set based on @ref OutputCompareMatchMode define.
	uint8_t TIMER1_OutputCompareMatchModeA;
	uint8_t TIMER1_OutputCompareMatchModeB;
	// Those parameters must be set based on @ref InterruptEnable define.
	uint8_t TIMER1_ClearOnCompareMatchInterruptA;
	uint8_t TIMER1_ClearOnCompareMatchInterruptB;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBackCTCA)(void);
	void(*P_IRQ_CallBackCTCB)(void);
}TIMER1_Timer1CTCModeConfig_t;

typedef struct{
	// This parameter can be sit by the user with any value.
	uint8_t TIMER1_ClearTimerOnCompareMatchValueA;
	uint8_t TIMER1_ClearTimerOnCompareMatchValueB;
	// This parameter can be sit by the user with any value.
	uint8_t TIMER1_InputCaptureValue;
	// This parameter must be set based on @ref inputCaptureEdge define.
	uint8_t TIMER1_InputCaptureEdge;
	// Those parameters must be set based on @ref OutputCompareMatchMode define.
	uint8_t TIMER1_OutputCompareMatchModeA;
	uint8_t TIMER1_OutputCompareMatchModeB;
	// Those parameters must be set based on @ref InterruptEnable define.
	uint8_t TIMER1_OverFlowInterrupt;
	uint8_t TIMER1_ClearOnCompareMatchInterruptA;
	uint8_t TIMER1_ClearOnCompareMatchInterruptB;
	uint8_t TIMER1_InputCaptureInterrupt;
	// Set the C function() which will be called once IRQ happen.
	void(*P_IRQ_CallBackOVF)(void);
	void(*P_IRQ_CallBackCTCA)(void);
	void(*P_IRQ_CallBackCTCB)(void);
	void(*P_IRQ_CallBackICR)(void);
}TIMER1_Timer1FastPWMModeConfig_t;

typedef struct{
	// This parameter must be set based on @ref WaveFormGenerationMode define.
	uint8_t TIMER1_WaveFormGenerationMode;
	// This parameter must be set based on @ref Prescaler define.
	uint8_t TIMER1_Prescaler;
	// This parameter contains the normal mode configuration.
	TIMER1_Timer1NormalModeConfig_t timer1NormalModeConfiguration;
	// This parameter contains the PWM mode configuration.
	TIMER1_Timer1PWMModeConfig_t timer1PWMModeConfiguration;
	// This parameter contains the CTC mode configuration.
	TIMER1_Timer1CTCModeConfig_t timer1CTCModeConfiguration;
	// This parameter contains the Fast PWM mode configuration.
	TIMER1_Timer1FastPWMModeConfig_t timer1FastPWMModeConfiguration;
	
}TIMER1_Timer1Config_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/
/***** @ref WaveFormGenerationMode define ******/
#define TIMER1_NORMAL_MODE								0
#define TIMER1_PWM_8_BIT_MODE							1
#define TIMER1_PWM_9_BIT_MODE							2
#define TIMER1_PWM_10_BIT_MODE							3
#define TIMER1_CTC_OCR1A_MODE							4
#define TIMER1_FAST_PWM_8_BIT_MODE						5
#define TIMER1_FAST_PWM_9_BIT_MODE 						6
#define TIMER1_FAST_PWM_10_BIT_MODE						7
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE		8
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE	9
#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE				10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE				11
#define TIMER1_CTC_ICR1_MODE							12
#define TIMER1_FAST_PWM_ICR1_MODE						14
#define TIMER1_FAST_PWM_OCR1A_MODE						15

/************ @ref Prescaler define ***********/
#define TIMER1_NO_CLOCK_SOURCE	 	                    0
#define TIMER1_NO_PRESCALER_FACTOR 	                    1
#define TIMER1_DIVISION_FACTOR_8	 	                2
#define TIMER1_DIVISION_FACTOR_64	                    3
#define TIMER1_DIVISION_FACTOR_256	                    4
#define TIMER1_DIVISION_FACTOR_1024	                    5
#define TIMER1_EXTERNAL_CLOCK_SOURCE_FALLING	        6
#define TIMER1_EXTERNAL_CLOCK_SOURCE_RISING				7

/************** @ref InterruptEnable define ******************/
#define DISABLE						                    0
#define ENABLE						                    1

/***** @ref ClearTimerOnCompareMatchPWMMode define **********/
#define TIMER1_OC_DISCONNECTED							0
#define TIMER1_CLR_ON_CTC_SET_ON_TOP				    1
#define TIMER1_SET_ON_CTC_CLR_ON_TOP				    2

/*********** @ref OutputCompareMatchMode define *************/
#define TIMER1_OC_DISCONNECTED					        0
#define TIMER1_OC_TOGGEL							    1
#define TIMER1_OC_LOW							        2
#define TIMER1_OC_HIGH							        3

/************* @ref inputCaptureEdge define ****************/
#define RISING_EDGE										1
#define FALLING_EDGE									0


/********************************************
 *                                          *
 *  APIs Supported by "MCAL TIMER1 DRIVER"  *
 *  									    *
 ********************************************/
void MCAL_TIMER1_Init(TIMER1_Timer1Config_t* Timer1Configuration);
uint16_t MCAL_TIMER1_GetTimerCounterValue (void);

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
