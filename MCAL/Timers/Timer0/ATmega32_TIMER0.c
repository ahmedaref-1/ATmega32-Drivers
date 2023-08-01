/*
 * ATmega32_TIMER0.c
 *
 * Created: 8/1/2023 6:25:04 AM
 *  Author: Ahmed Aref Omaira
 */ 
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_TIMER0.h"


/*********************************************
 *                                           *
 *         IRQ HANDLERS DEFINITION           *
 * 							    			 *
 *********************************************/

ISR(TIMER0_CTC_IRQHandler) {
	if (GPtr_TIMER0_IRQCallBack[TIMER0_CTC_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER0_IRQCallBack[TIMER0_CTC_VECTOR_ID]();
	}
}

ISR(TIMER0_OVF_IRQHandler) {
	if (GPtr_TIMER0_IRQCallBack[TIMER0_OVF_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER0_IRQCallBack[TIMER0_OVF_VECTOR_ID]();
	}
}
/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 ******************************************/
void TIMER0_Init(TIMER0_Timer0Config_t* Timer0Configuration)
{
	/*Set Configurable Modes*/
switch (Timer0Configuration->TIMER0_WaveFormGenerationMode)
{
	case(TIMER0_NORMAL_MODE):
		/*1.Initialize Waveform Generation Mode as Normal Mode*/
		TCCR0->WGM00 = LOW;
		TCCR0->WGM01 = LOW;
		/*2.Set the Required Preload Value*/
		TCNT0 = Timer0Configuration->timer0NormalModeConfiguration.TIMER0_PreloadValue ;	
		/*3.Timer0 Overflow Interrupt Enable*/
		if(ENABLE == Timer0Configuration->timer0NormalModeConfiguration.TIMER0_OverFlowInterrupt){
			TIMSK->TOIE0 = HIGH;
			GPtr_TIMER0_IRQCallBack[TIMER0_OVF_VECTOR_ID] = Timer0Configuration->timer0NormalModeConfiguration.P_IRQ_CallBack;
		}
		else if(DISABLE == Timer0Configuration->timer0NormalModeConfiguration.TIMER0_OverFlowInterrupt){
			TIMSK->TOIE0 = LOW;
		}
		else{
			/* MISRA */
		}
		break;
		
	case(TIMER0_PWM_MODE):
		/*1.Initialize Waveform Generation Mode as PWM Mode*/
		TCCR0->WGM00 = HIGH;
		TCCR0->WGM01 = LOW;
		/*2.Set CTC PWM MODE*/
		switch(Timer0Configuration->timer0PWMModeConfiguration.TIMER0_ClearTimerOnCompareMatchPWMMode){
			case(TIMER0_OC_DISCONNECTED):
			TCCR0->COM00 = LOW;
			TCCR0->COM01 = LOW;
			break;
			case(TIMER0_CLR_ON_CTC_SET_ON_TOP):
			TCCR0->COM00 = LOW ;
			TCCR0->COM01 = HIGH ;
			break;
			case(TIMER0_SET_ON_CTC_CLR_ON_TOP):
			TCCR0->COM00 = HIGH;
			TCCR0->COM01 = HIGH;
			break;

		}
		/*3.Set the Required CTC Value*/
		OCR0 = Timer0Configuration->timer0PWMModeConfiguration.TIMER0_ClearTimerOnCompareMatchValue ;
		break;
	
		case (TIMER0_CTC_MODE):
		/*1.Initialize Waveform Generation Mode as CTC Mode*/
		TCCR0->WGM00 = LOW;
		TCCR0->WGM01 = HIGH;
		/*2.Set the Required CTC Value*/
		OCR0 = Timer0Configuration->timer0CTCModeConfiguration.TIMER0_ClearTimerOnCompareMatchValue ;
		/*3.Timer0 Compare Match Interrupt Enable*/
		if(ENABLE == Timer0Configuration->timer0CTCModeConfiguration.TIMER0_ClearOnCompareMatchInterrupt){
			TIMSK->OCIE0 = HIGH;
			GPtr_TIMER0_IRQCallBack[TIMER0_CTC_VECTOR_ID] = Timer0Configuration->timer0CTCModeConfiguration.P_IRQ_CallBack;
		}
		else if(DISABLE == Timer0Configuration->timer0CTCModeConfiguration.TIMER0_ClearOnCompareMatchInterrupt){
			TIMSK->OCIE0 = LOW;
		}
		else{
			/* MISRA */
		}
		break;
	
	case(TIMER0_FAST_PWM_MODE):
		/*1.Initialize Waveform Generation Mode as Fast PWM Mode*/
		TCCR0->WGM00 = HIGH;
		TCCR0->WGM01 = HIGH;	
		/*2.Set CTC Fast PWM MODE*/
		switch(Timer0Configuration->timer0FastPWMModeConfiguration.TIMER0_OutputCompareMatchMode){
			case(TIMER0_OC_DISCONNECTED):
				TCCR0->COM00 = LOW;
				TCCR0->COM01 = LOW;
				break;
			case(TIMER0_CLR_ON_CTC_SET_ON_TOP):
				TCCR0->COM00 = LOW;
				TCCR0->COM01 = HIGH;
				break;
			case(TIMER0_SET_ON_CTC_CLR_ON_TOP):
				TCCR0->COM00 = HIGH;
				TCCR0->COM01 = HIGH;
				break;
		}

		/*3.Set the Required CTC Value*/
		OCR0 = Timer0Configuration->timer0FastPWMModeConfiguration.TIMER0_ClearTimerOnCompareMatchValue ;
		break;
}

	/*Set the Required Prescaler*/
	switch(Timer0Configuration->TIMER0_Prescaler){
		case(TIMER0_NO_CLOCK_SOURCE):
			TCCR0->CS00 = LOW;
			TCCR0->CS01 = LOW;
			TCCR0->CS02 = LOW;
			break;
			
		case(TIMER0_NO_PRESCALER_FACTOR):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = LOW;
			TCCR0->CS02 = LOW;
			break;
			
		case(TIMER0_DIVISION_FACTOR_8):
			TCCR0->CS00 = LOW;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = LOW;
		break;
		
		case(TIMER0_DIVISION_FACTOR_64):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = LOW;
			break;
			
		case(TIMER0_DIVISION_FACTOR_256):
			TCCR0->CS00 = LOW;
			TCCR0->CS01 = LOW;
			TCCR0->CS02 = HIGH;
		break;
		
		case(TIMER0_DIVISION_FACTOR_1024):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = LOW;
			TCCR0->CS02 = HIGH;
		break;
		
		case(TIMER0_EXTERNAL_CLOCK_SOURCE_FALLING):
			TCCR0->CS00 = LOW;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = HIGH;
		break;
		
		case(TIMER0_EXTERNAL_CLOCK_SOURCE_RISING):
			TCCR0->CS00 = HIGH;
			TCCR0->CS01 = HIGH;
			TCCR0->CS02 = HIGH;
		break;
	}
}

uint8_t TIMER0_GetTimerCounterValue (void)
{
	return TCNT0 ;
}