/*
 * ATmega32_TIMER1.c
 *
 * Created: 8/1/2023 6:26:04 AM
 *  Author: Ahmed Aref Omaira
 */ 
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_TIMER1.h"


/*********************************************
 *                                           *
 *         IRQ HANDLERS DEFINITION           *
 * 							    			 *
 *********************************************/
ISR(TIMER1_CAPT_IRQHandler) {
	if (GPtr_TIMER1_IRQCallBack[TIMER1_ICU_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER1_IRQCallBack[TIMER1_ICU_VECTOR_ID]();
	}
}

ISR(TIMER1_CTCA_IRQHandler) {
	if (GPtr_TIMER1_IRQCallBack[TIMER1_CTCA_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER1_IRQCallBack[TIMER1_CTCA_VECTOR_ID]();
	}
}

ISR(TIMER1_CTCB_IRQHandler) {
	if (GPtr_TIMER1_IRQCallBack[TIMER1_CTCB_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER1_IRQCallBack[TIMER1_CTCB_VECTOR_ID]();
	}
}

ISR(TIMER1_OVF_IRQHandler) {
	if (GPtr_TIMER1_IRQCallBack[TIMER1_OVF_VECTOR_ID] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_TIMER1_IRQCallBack[TIMER1_OVF_VECTOR_ID]();
	}
}
/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 ******************************************/
void TIMER1_Init(TIMER1_Timer1Config_t* Timer1Configuration)
{
	/*Set Configurable Modes*/
	switch (Timer1Configuration->TIMER1_WaveFormGenerationMode)
	{
		case(TIMER1_NORMAL_MODE):	
			/*1.Set Waveform generation mode as Normal mode */
			TCCR1A->WGM10 = LOW;
			TCCR1A->WGM11 = LOW;
			TCCR1B->WGM12 = LOW;
			TCCR1B->WGM13 = LOW;
			/*2.Set the require Preload Value*/
			TCNT1 = Timer1Configuration->timer1NormalModeConfiguration.TIMER1_PreloadValue ;
			/*3.Timer1 Overflow Interrupt Enable*/
			if(ENABLE == Timer1Configuration->timer1NormalModeConfiguration.TIMER1_OverFlowInterrupt){
				TIMSK->TOIE1 = HIGH;
				GPtr_TIMER1_IRQCallBack[TIMER1_OVF_VECTOR_ID] = Timer1Configuration->timer1NormalModeConfiguration.P_IRQ_CallBack;
			}
			else if(DISABLE == Timer1Configuration->timer1NormalModeConfiguration.TIMER1_OverFlowInterrupt){
				TIMSK->TOIE1 = LOW;
			}
			else{
				/* MISRA */
			}
			break;
		
			
		case(TIMER1_CTC_OCR1A_MODE):
		case(TIMER1_CTC_ICR1_MODE):
			/*1.Set Waveform generation mode as CTC mode */
			if(TIMER1_CTC_OCR1A_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
			TCCR1A->WGM10 = LOW;
			TCCR1A->WGM11 = LOW;
			TCCR1B->WGM12 = HIGH;
			TCCR1B->WGM13 = LOW;
			}
			else if (TIMER1_CTC_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
			TCCR1A->WGM10 = LOW;
			TCCR1A->WGM11 = LOW;
			TCCR1B->WGM12 = HIGH;
			TCCR1B->WGM13 = HIGH;
			}
			else{
				/*Misra*/
			}			
			/*2.Set the require CTC Values*/
			OCR1A = Timer1Configuration->timer1CTCModeConfiguration.TIMER1_ClearTimerOnCompareMatchValueA ;
			OCR1B = Timer1Configuration->timer1CTCModeConfiguration.TIMER1_ClearTimerOnCompareMatchValueB ;
			/*3.Configure the ICR1 */
			if(TIMER1_CTC_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
							/*1.Set ICR1 Value*/
							ICR1 = Timer1Configuration->timer1CTCModeConfiguration.TIMER1_InputCaptureValue;
							/*2.Configure the input capture mode edge trigger*/
							if(RISING_EDGE == Timer1Configuration->timer1CTCModeConfiguration.TIMER1_InputCaptureEdge){
								TCCR1B->ICES1 = HIGH;
							}
							else if(FALLING_EDGE == Timer1Configuration->timer1CTCModeConfiguration.TIMER1_InputCaptureEdge){
								TCCR1B->ICES1 = LOW;
							}
							else{
								/* MISRA */
							}
			}
			/*3.Set OCR1A mode*/
			switch(Timer1Configuration->timer1CTCModeConfiguration.TIMER1_OutputCompareMatchModeA){
				case(TIMER1_OC_DISCONNECTED):
					TCCR1A->COM1A0 = LOW;
					TCCR1A->COM1A1 = LOW;
					break;
				case(TIMER1_OC_TOGGEL):
					TCCR1A->COM1A0 = LOW ;
					TCCR1A->COM1A1 = HIGH ;
					break;
				case(TIMER1_OC_LOW):
					TCCR1A->COM1A0 = HIGH;
					TCCR1A->COM1A1 = HIGH;
					break;
				case(TIMER1_OC_HIGH):
					TCCR1A->COM1A0 = HIGH;
					TCCR1A->COM1A1 = HIGH;
					break;
			}
			/*4.Set OCR1B mode*/
			switch(Timer1Configuration->timer1CTCModeConfiguration.TIMER1_OutputCompareMatchModeB){
				case(TIMER1_OC_DISCONNECTED):
				TCCR1A->COM1B0 = LOW;
				TCCR1A->COM1B1 = LOW;
				break;
				case(TIMER1_OC_TOGGEL):
				TCCR1A->COM1B0 = LOW ;
				TCCR1A->COM1B1 = HIGH ;
				break;
				case(TIMER1_OC_LOW):
				TCCR1A->COM1B0 = HIGH;
				TCCR1A->COM1B1 = HIGH;
				break;
				case(TIMER1_OC_HIGH):
				TCCR1A->COM1B0 = HIGH;
				TCCR1A->COM1B1 = HIGH;
				break;
			}
		    /*5.Timer1 CTC Interrupt A Enable*/
		    if(ENABLE == Timer1Configuration->timer1CTCModeConfiguration.TIMER1_ClearOnCompareMatchInterruptA){
			    TIMSK->OCIE1A = HIGH;
			    GPtr_TIMER1_IRQCallBack[TIMER1_CTCA_VECTOR_ID] = Timer1Configuration->timer1CTCModeConfiguration.P_IRQ_CallBackCTCA;
		    }
		    else if(DISABLE == Timer1Configuration->timer1CTCModeConfiguration.TIMER1_ClearOnCompareMatchInterruptA){
			    TIMSK->OCIE1B = LOW;
		    }
		    else{
			    /* MISRA */
		    }
			/*6.Timer1 CTC Interrupt B Enable*/
		    if(ENABLE == Timer1Configuration->timer1CTCModeConfiguration.TIMER1_ClearOnCompareMatchInterruptB){
			    TIMSK->OCIE1B = HIGH;
			    GPtr_TIMER1_IRQCallBack[TIMER1_CTCB_VECTOR_ID] = Timer1Configuration->timer1CTCModeConfiguration.P_IRQ_CallBackCTCB;
		    }
		    else if(DISABLE == Timer1Configuration->timer1CTCModeConfiguration.TIMER1_ClearOnCompareMatchInterruptB){
			    TIMSK->OCIE1B = LOW;
		    }
		    else{
			    /* MISRA */
		    }
			break;
	
	
		case(TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE):
		case(TIMER1_PWM_PHASE_CORRECT_ICR1_MODE):
		case(TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE):
		case(TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE):
		case(TIMER1_PWM_10_BIT_MODE):
		case(TIMER1_PWM_9_BIT_MODE):
		case(TIMER1_PWM_8_BIT_MODE):
			/*1.Set Waveform generation mode as PWM modes */
			if(TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = HIGH;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = LOW;
				TCCR1B->WGM13 = HIGH;
			}
			else if (TIMER1_PWM_PHASE_CORRECT_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = LOW;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = LOW;
				TCCR1B->WGM13 = HIGH;
			}
			else if (TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = HIGH;
				TCCR1A->WGM11 = LOW;
				TCCR1B->WGM12 = LOW;
				TCCR1B->WGM13 = HIGH;
			}
			else if (TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = LOW;
				TCCR1A->WGM11 = LOW;
				TCCR1B->WGM12 = LOW;
				TCCR1B->WGM13 = HIGH;
			}
			else if (TIMER1_PWM_10_BIT_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = HIGH;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = LOW;
				TCCR1B->WGM13 = LOW;
			}
			else if (TIMER1_PWM_9_BIT_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = LOW;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = LOW;
				TCCR1B->WGM13 = LOW;
			}
			else if (TIMER1_PWM_8_BIT_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = HIGH;
				TCCR1A->WGM11 = LOW;
				TCCR1B->WGM12 = LOW;
				TCCR1B->WGM13 =	LOW;		
			}
			else
			{
				/*Misra*/
			}
			/*2.Set the require CTC Values*/
			OCR1A = Timer1Configuration->timer1PWMModeConfiguration.TIMER1_ClearTimerOnCompareMatchValueA ;
			OCR1B = Timer1Configuration->timer1PWMModeConfiguration.TIMER1_ClearTimerOnCompareMatchValueB ;	
			/*3.Set ICR1*/
			if(TIMER1_PWM_PHASE_CORRECT_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode ||
			TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				/*1.Set ICR1 Value*/
				ICR1 = Timer1Configuration->timer1PWMModeConfiguration.TIMER1_InputCaptureValue;
				/*2.Configure the input capture mode edge trigger*/
				if(RISING_EDGE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_InputCaptureEdge){
					TCCR1B->ICES1 = HIGH;
				}
				else if(FALLING_EDGE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_InputCaptureEdge){
					TCCR1B->ICES1 = LOW;
				}
				else{
					/* MISRA */
				}
			}
			/*4.Set OCR1A mode*/
			switch(Timer1Configuration->timer1PWMModeConfiguration.TIMER1_OutputCompareMatchModeA){
				case(TIMER1_OC_DISCONNECTED):
				TCCR1A->COM1A0 = LOW;
				TCCR1A->COM1A1 = LOW;
				break;
				case(TIMER1_CLR_ON_CTC_SET_ON_TOP):
				TCCR1A->COM1A0 = LOW ;
				TCCR1A->COM1A1 = HIGH ;
				break;
				case(TIMER1_SET_ON_CTC_CLR_ON_TOP):
				TCCR1A->COM1A0 = HIGH;
				TCCR1A->COM1A1 = HIGH;
				break;
			}
			/*5.Set OCR1B mode*/
			switch(Timer1Configuration->timer1PWMModeConfiguration.TIMER1_OutputCompareMatchModeB){
				case(TIMER1_OC_DISCONNECTED):
				TCCR1A->COM1B0 = LOW;
				TCCR1A->COM1B1 = LOW;
				break;
				case(TIMER1_CLR_ON_CTC_SET_ON_TOP):
				TCCR1A->COM1B0 = LOW ;
				TCCR1A->COM1B1 = HIGH ;
				break;
				case(TIMER1_SET_ON_CTC_CLR_ON_TOP):
				TCCR1A->COM1B0 = HIGH;
				TCCR1A->COM1B1 = HIGH;
				break;
			}
			/*6.Timer1 PWM Interrupt Enable*/
			/*6.1.Timer1 Overflow Interrupt Enable*/
			if(ENABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_OverFlowInterrupt){
				TIMSK->TOIE1 = HIGH;
				GPtr_TIMER1_IRQCallBack[TIMER1_OVF_VECTOR_ID] = Timer1Configuration->timer1FastPWMModeConfiguration.P_IRQ_CallBackOVF;
			}
			else if(DISABLE == Timer1Configuration->timer1FastPWMModeConfiguration.P_IRQ_CallBackOVF){
				TIMSK->TOIE1 = LOW;
			}
			else{
				/* MISRA */
			}
		    /*6.2.Timer1 CTC Interrupt A Enable*/
		    if(ENABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptA){
			    TIMSK->OCIE1A = HIGH;
			    GPtr_TIMER1_IRQCallBack[TIMER1_CTCA_VECTOR_ID] = Timer1Configuration->timer1PWMModeConfiguration.P_IRQ_CallBackCTCA;
		    }
		    else if(DISABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptA){
			    TIMSK->OCIE1A = LOW;
		    }
		    else{
			    /* MISRA */
		    }
		    /*6.3.Timer1 CTC Interrupt B Enable*/
		    if(ENABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptB){
			    TIMSK->OCIE1B = HIGH;
			    GPtr_TIMER1_IRQCallBack[TIMER1_CTCB_VECTOR_ID] = Timer1Configuration->timer1PWMModeConfiguration.P_IRQ_CallBackCTCB;
		    }
		    else if(DISABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptB){
			    TIMSK->OCIE1B = LOW;
		    }
		    else{
			    /* MISRA */
		    }
			/*6.4.Timer1 ICR Interrupt Enable*/
			if(ENABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_InputCaptureInterrupt){
				TIMSK->TICIE1 = HIGH;
				GPtr_TIMER1_IRQCallBack[TIMER1_CTCB_VECTOR_ID] = Timer1Configuration->timer1PWMModeConfiguration.P_IRQ_CallBackICR;
			}
			else if(DISABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_InputCaptureInterrupt){
				TIMSK->TICIE1 = LOW;
			}
			else{
				/* MISRA */
			}
		    break;
			
		case(TIMER1_FAST_PWM_OCR1A_MODE):
		case(TIMER1_FAST_PWM_ICR1_MODE):
		case(TIMER1_FAST_PWM_10_BIT_MODE):
		case(TIMER1_FAST_PWM_9_BIT_MODE):
		case(TIMER1_FAST_PWM_8_BIT_MODE):
			/*1.Set Waveform generation mode as PWM modes */
			if(TIMER1_FAST_PWM_OCR1A_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = HIGH;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = HIGH;
				TCCR1B->WGM13 = HIGH;
			}
			else if (TIMER1_FAST_PWM_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = LOW;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = HIGH;
				TCCR1B->WGM13 = HIGH;
			}
			else if (TIMER1_FAST_PWM_10_BIT_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = HIGH;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = HIGH;
				TCCR1B->WGM13 = LOW;
			}
			else if (TIMER1_FAST_PWM_9_BIT_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = LOW;
				TCCR1A->WGM11 = HIGH;
				TCCR1B->WGM12 = HIGH;
				TCCR1B->WGM13 = LOW;
			}
			else if (TIMER1_FAST_PWM_8_BIT_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				TCCR1A->WGM10 = HIGH;
				TCCR1A->WGM11 = LOW;
				TCCR1B->WGM12 = HIGH;
				TCCR1B->WGM13 = LOW;
			}
			else
			{
				/*Misra*/
			}
			/*2.Set the require CTC Values*/
			OCR1A = Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_ClearTimerOnCompareMatchValueA ;
			OCR1B = Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_ClearTimerOnCompareMatchValueB ;	
			/*3.Set ICR1*/
			if(TIMER1_PWM_PHASE_CORRECT_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode ||
			TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE == Timer1Configuration->TIMER1_WaveFormGenerationMode){
				/*1.Set ICR1 Value*/
				ICR1 = Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_InputCaptureValue;
				/*2.Configure the input capture mode edge trigger*/
				if(RISING_EDGE == Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_InputCaptureEdge){
					TCCR1B->ICES1 = HIGH;
				}
				else if(FALLING_EDGE == Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_InputCaptureEdge){
					TCCR1B->ICES1 = LOW;
				}
				else{
					/* MISRA */
				}
			}
			/*4.Set OCR1A mode*/
			switch(Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_OutputCompareMatchModeA){
				case(TIMER1_OC_DISCONNECTED):
				TCCR1A->COM1A0 = LOW;
				TCCR1A->COM1A1 = LOW;
				break;
				case(TIMER1_CLR_ON_CTC_SET_ON_TOP):
				TCCR1A->COM1A0 = LOW ;
				TCCR1A->COM1A1 = HIGH ;
				break;
				case(TIMER1_SET_ON_CTC_CLR_ON_TOP):
				TCCR1A->COM1A0 = HIGH;
				TCCR1A->COM1A1 = HIGH;
				break;
			}
			/*5.Set OCR1B mode*/
			switch(Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_OutputCompareMatchModeB){
				case(TIMER1_OC_DISCONNECTED):
				TCCR1A->COM1B0 = LOW;
				TCCR1A->COM1B1 = LOW;
				break;
				case(TIMER1_CLR_ON_CTC_SET_ON_TOP):
				TCCR1A->COM1B0 = LOW ;
				TCCR1A->COM1B1 = HIGH ;
				break;
				case(TIMER1_SET_ON_CTC_CLR_ON_TOP):
				TCCR1A->COM1B0 = HIGH;
				TCCR1A->COM1B1 = HIGH;
				break;
			}
			/*6.Timer1 PWM Interrupt Enable*/
			/*6.1.Timer1 Overflow Interrupt Enable*/
			if(ENABLE == Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_OverFlowInterrupt){
				TIMSK->TOIE1 = HIGH;
				GPtr_TIMER1_IRQCallBack[TIMER1_OVF_VECTOR_ID] = Timer1Configuration->timer1FastPWMModeConfiguration.P_IRQ_CallBackOVF;
			}
			else if(DISABLE == Timer1Configuration->timer1FastPWMModeConfiguration.P_IRQ_CallBackOVF){
				TIMSK->TOIE1 = LOW;
			}
			else{
				/* MISRA */
			}
		    /*6.2.Timer1 CTC Interrupt A Enable*/
		    if(ENABLE == Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptA){
			    TIMSK->OCIE1A = HIGH;
			    GPtr_TIMER1_IRQCallBack[TIMER1_CTCA_VECTOR_ID] = Timer1Configuration->timer1FastPWMModeConfiguration.P_IRQ_CallBackCTCA;
		    }
		    else if(DISABLE == Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptA){
			    TIMSK->OCIE1A = LOW;
		    }
		    else{
			    /* MISRA */
		    }
		    /*6.3.Timer1 CTC Interrupt B Enable*/
		    if(ENABLE == Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptB){
			    TIMSK->OCIE1B = HIGH;
			    GPtr_TIMER1_IRQCallBack[TIMER1_CTCB_VECTOR_ID] = Timer1Configuration->timer1FastPWMModeConfiguration.P_IRQ_CallBackCTCB;
		    }
		    else if(DISABLE == Timer1Configuration->timer1FastPWMModeConfiguration.TIMER1_ClearOnCompareMatchInterruptB){
			    TIMSK->OCIE1B = LOW;
		    }
		    else{
			    /* MISRA */
		    }
			/*6.4.Timer1 ICR Interrupt Enable*/
			if(ENABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_InputCaptureInterrupt){
				TIMSK->TICIE1 = HIGH;
				GPtr_TIMER1_IRQCallBack[TIMER1_CTCB_VECTOR_ID] = Timer1Configuration->timer1PWMModeConfiguration.P_IRQ_CallBackICR;
			}
			else if(DISABLE == Timer1Configuration->timer1PWMModeConfiguration.TIMER1_InputCaptureInterrupt){
				TIMSK->TICIE1 = LOW;
			}
			else{
				/* MISRA */
			}
		    break;						
	}
	
		/*Set the Required Prescaler*/
		switch(Timer1Configuration->TIMER1_Prescaler){
			case(TIMER1_NO_CLOCK_SOURCE):
			TCCR1B->CS10 = LOW;
			TCCR1B->CS11 = LOW;
			TCCR1B->CS12 = LOW;
			break;
			
			case(TIMER1_NO_PRESCALER_FACTOR):
			TCCR1B->CS10 = HIGH;
			TCCR1B->CS11 = LOW;
			TCCR1B->CS12 = LOW;
			break;
			
			case(TIMER1_DIVISION_FACTOR_8):
			TCCR1B->CS10 = LOW;
			TCCR1B->CS11 = HIGH;
			TCCR1B->CS12 = LOW;
			break;
			
			case(TIMER1_DIVISION_FACTOR_64):
			TCCR1B->CS10 = HIGH;
			TCCR1B->CS11 = HIGH;
			TCCR1B->CS12 = LOW;
			break;
			
			case(TIMER1_DIVISION_FACTOR_256):
			TCCR1B->CS10 = LOW;
			TCCR1B->CS11 = LOW;
			TCCR1B->CS12 = HIGH;
			break;
			
			case(TIMER1_DIVISION_FACTOR_1024):
			TCCR1B->CS10 = HIGH;
			TCCR1B->CS11 = LOW;
			TCCR1B->CS12 = HIGH;
			break;
			
			case(TIMER1_EXTERNAL_CLOCK_SOURCE_FALLING):
			TCCR1B->CS10 = LOW;
			TCCR1B->CS11 = HIGH;
			TCCR1B->CS12 = HIGH;
			break;
			
			case(TIMER1_EXTERNAL_CLOCK_SOURCE_RISING):
			TCCR1B->CS10 = HIGH;
			TCCR1B->CS11 = HIGH;
			TCCR1B->CS12 = HIGH;
			break;
		}
}

uint16_t MCAL_TIMER1_GetTimerCounterValue ()
{
	return TCNT1 ;
}
