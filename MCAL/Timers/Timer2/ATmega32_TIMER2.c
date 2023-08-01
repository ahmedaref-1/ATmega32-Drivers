/*
 * ATmega32_TIMER2.c
 *
 * Created: 8/1/2023 6:30:18 AM
 *  Author: Ahmed Aref Omaira
 */ 

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_TIMER2.h"


/*********************************************
 *                                           *
 *         IRQ HANDLERS DEFINITION           *
 * 							    			 *
 *********************************************/
ISR(TIMER2_CTC_IRQHandler) {
	if (GPtr_TIMER2_IRQCallBack[TIMER2_CTC_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER2_IRQCallBack[TIMER2_CTC_VECTOR_ID]();
	}
}

ISR(TIMER2_OVF_IRQHandler) {
	if (GPtr_TIMER2_IRQCallBack[TIMER2_OVF_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER2_IRQCallBack[TIMER2_OVF_VECTOR_ID]();
	}
}


/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 ******************************************/
void TIMER2_Init(TIMER2_Timer2Config_t* Timer2Configuration)
{
	/*Set Configurable Modes*/
switch (Timer2Configuration->TIMER2_WaveFormGenerationMode)
{
	case(TIMER2_NORMAL_MODE):
		/*1.Initialize Waveform Generation Mode as Normal Mode*/
		TCCR2->WGM20 = LOW;
		TCCR2->WGM21 = LOW;
		/*2.Set the Required Preload Value*/
		TCNT2 = Timer2Configuration->timer2NormalModeConfiguration.TIMER2_PreloadValue ;	
		/*3.Timer2 Overflow Interrupt Enable*/
		if(ENABLE == Timer2Configuration->timer2NormalModeConfiguration.TIMER2_OverFlowInterrupt){
			TIMSK->TOIE2 = HIGH;
			GPtr_TIMER2_IRQCallBack[TIMER2_OVF_VECTOR_ID] = Timer2Configuration->timer2NormalModeConfiguration.P_IRQ_CallBack;
		}
		else if(DISABLE == Timer2Configuration->timer2NormalModeConfiguration.TIMER2_OverFlowInterrupt){
			TIMSK->TOIE2 = LOW;
		}
		else{
			/* MISRA */
		}
		break;
		
	case(TIMER2_PWM_MODE):
		/*1.Initialize Waveform Generation Mode as PWM Mode*/
		TCCR2->WGM20 = HIGH;
		TCCR2->WGM21 = LOW;
		/*2.Set CTC PWM MODE*/
		switch(Timer2Configuration->timer2PWMModeConfiguration.TIMER2_ClearTimerOnCompareMatchPWMMode){
			case(TIMER2_OC_DISCONNECTED):
			TCCR2->COM20 = LOW;
			TCCR2->COM21 = LOW;
			break;
			case(TIMER2_CLR_ON_CTC_SET_ON_TOP):
			TCCR2->COM20 = LOW ;
			TCCR2->COM21 = HIGH ;
			break;
			case(TIMER2_SET_ON_CTC_CLR_ON_TOP):
			TCCR2->COM20 = HIGH;
			TCCR2->COM21 = HIGH;
			break;

		}
		/*3.Set the Required CTC Value*/
		OCR2 = Timer2Configuration->timer2PWMModeConfiguration.TIMER2_ClearTimerOnCompareMatchValue ;
		break;
	
		case (TIMER2_CTC_MODE):
		/*1.Initialize Waveform Generation Mode as CTC Mode*/
		TCCR2->WGM20 = LOW;
		TCCR2->WGM21 = HIGH;
		/*2.Set the Required CTC Value*/
		OCR2 = Timer2Configuration->timer2CTCModeConfiguration.TIMER2_ClearTimerOnCompareMatchValue ;
		/*3.Timer0 Compare Match Interrupt Enable*/
		if(ENABLE == Timer2Configuration->timer2CTCModeConfiguration.TIMER2_ClearOnCompareMatchInterrupt){
			TIMSK->OCIE2 = HIGH;
			GPtr_TIMER2_IRQCallBack[TIMER2_CTC_VECTOR_ID] = Timer2Configuration->timer2CTCModeConfiguration.P_IRQ_CallBack;
		}
		else if(DISABLE == Timer2Configuration->timer2CTCModeConfiguration.TIMER2_ClearOnCompareMatchInterrupt){
			TIMSK->OCIE2 = LOW;
		}
		else{
			/* MISRA */
		}
		break;
	
	case(TIMER2_FAST_PWM_MODE):
		/*1.Initialize Waveform Generation Mode as Fast PWM Mode*/
		TCCR2->WGM20 = HIGH;
		TCCR2->WGM21 = HIGH;	
		/*2.Set CTC Fast PWM MODE*/
		switch(Timer2Configuration->timer2FastPWMModeConfiguration.TIMER2_OutputCompareMatchMode){
			case(TIMER2_OC_DISCONNECTED):
				TCCR2->COM20 = LOW;
				TCCR2->COM21 = LOW;
				break;
			case(TIMER2_CLR_ON_CTC_SET_ON_TOP):
				TCCR2->COM20 = LOW;
				TCCR2->COM21 = HIGH;
				break;
			case(TIMER2_SET_ON_CTC_CLR_ON_TOP):
				TCCR2->COM20 = HIGH;
				TCCR2->COM21 = HIGH;
				break;
		}

		/*3.Set the Required CTC Value*/
		OCR2 = Timer2Configuration->timer2FastPWMModeConfiguration.TIMER2_ClearTimerOnCompareMatchValue ;
		break;
}

	/*Set the Required Prescaler*/
	switch(Timer2Configuration->TIMER2_Prescaler){
		case(TIMER2_NO_CLOCK_SOURCE):
			TCCR2->CS20 = LOW;
			TCCR2->CS21 = LOW;
			TCCR2->CS22 = LOW;
			break;
		case(TIMER2_NO_PRESCALER_FACTOR):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = LOW;
			TCCR2->CS22 = LOW;
			break;
		case(TIMER2_DIVISION_FACTOR_8):
			TCCR2->CS20 = LOW;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = LOW;
		break;
		case(TIMER2_DIVISION_FACTOR_64):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = LOW;
		break;
		case(TIMER2_DIVISION_FACTOR_256):
			TCCR2->CS20 = LOW;
			TCCR2->CS21 = LOW;
			TCCR2->CS22 = HIGH;
		break;
		case(TIMER2_DIVISION_FACTOR_1024):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = LOW;
			TCCR2->CS22 = HIGH;
		break;
		case(TIMER2_EXTERNAL_CLOCK_SOURCE_FALLING):
			TCCR2->CS20 = LOW;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = HIGH;
		break;
		case(TIMER2_EXTERNAL_CLOCK_SOURCE_RISING):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = HIGH;
		break;
	}
}

uint8_t TIMER2_GetTimerCounterValue (void)
{
	return TCNT2 ;
}