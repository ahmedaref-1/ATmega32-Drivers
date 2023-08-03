/*
 * ATmega32_TIMER2.c
 *
 * Created: 8/1/2023 6:25:04 AM
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
void (*GPtr_TIMER2_IRQCallBack[2])(void) = {NULL};
	
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
void MCAL_TIMER2_Init(TIMER2Configuration_t* TIMER2_Config){
		
	// 1. Select Timer Mode
	switch(TIMER2_Config->Timer2Mode){
		case(TIMER2_MODE_NORMAL):
			TCCR2->WGM20 = LOW;
			TCCR2->WGM21 = LOW;
		break;
		case(TIMER2_MODE_CTC):
			TCCR2->WGM20 = LOW;
			TCCR2->WGM21 = HIGH;
		break;
		case(TIMER2_MODE_Fast_PWM_Inverting):
			TCCR2->WGM20 = HIGH;
			TCCR2->WGM21 = HIGH;
			TCCR2->COM20 = HIGH;
			TCCR2->COM21 = HIGH;
		break;
		case(TIMER2_MODE_Fast_PWM_Noninverting):
			TCCR2->WGM20 = HIGH;
			TCCR2->WGM21 = HIGH;
			TCCR2->COM20 = LOW;
			TCCR2->COM21 = HIGH;		
		break;
		case(TIMER2_MODE_Phase_Correct_PWM_Set_DC):
			TCCR2->WGM20 = LOW;
			TCCR2->WGM21 = HIGH;
			TCCR2->COM20 = LOW;
			TCCR2->COM21 = HIGH;	
		break;
		case(TIMER2_MODE_Phase_Correct_PWM_Set_UC):
			TCCR2->WGM20 = LOW;
			TCCR2->WGM21 = HIGH;
			TCCR2->COM20 = HIGH;
			TCCR2->COM21 = HIGH;			
		break;
	}
	
	if ((TIMER2_Config->Timer2Mode != TIMER2_MODE_CTC) && (TIMER2_Config->Timer2Mode != TIMER2_MODE_NORMAL))
		SET_BIT(OCR2,3);    //Configure OC0 (PINB3) as Output
		
	// 2. Select Clock Source
	switch(TIMER2_Config->Timer2ClockSource){
		case(TIMER2_CLOCK_SOURCE_INTERNAL_NO_PRESCALER):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = LOW;
			TCCR2->CS22 = LOW;
		break;
		case(TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_8):
			TCCR2->CS20 = LOW;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = LOW;
		break;
		case(TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_64):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = LOW;
		break;
		case(TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_256):
			TCCR2->CS20 = LOW;
			TCCR2->CS21 = LOW;
			TCCR2->CS22 = HIGH;
		break;
		case(TIMER2_CLOCK_SOURCE_INTERNAL_PRESCALER_1024):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = LOW;
			TCCR2->CS22 = HIGH;
		break;
		case(TIMER2_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE):
			TCCR2->CS20 = LOW;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = HIGH;
		break;
		case(TIMER2_CLOCK_SOURCE_EXTERNAL_RISING_EDGE):
			TCCR2->CS20 = HIGH;
			TCCR2->CS21 = HIGH;
			TCCR2->CS22 = HIGH;
		break;
	}
	if ((TIMER2_Config->Timer2ClockSource == TIMER2_CLOCK_SOURCE_EXTERNAL_RISING_EDGE) && (TIMER2_Config->Timer2ClockSource == TIMER2_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE))
		SET_BIT(OCR2,0);  //Configure T0 (PINB0) as Input
	
	// 3. Enable Or Disable IRQ
	switch(TIMER2_Config->Timer2IRQEnable){
		case(TIMER2_IRQ_ENABLE_TOIE2):
		TIMSK->TOIE2 = HIGH;
		break;
		case(TIMER2_IRQ_ENABLE_OCIE2):
		TIMSK->OCIE2 = HIGH;
		break;
	}
	if (TIMER2_Config->Timer2IRQEnable != TIMER2_IRQ_ENABLE_NONE)
		Enable_GlobalInterrupt();
	
	// 4. Call back ISR function
		switch(TIMER2_Config->Timer2IRQEnable){
			case(TIMER2_IRQ_ENABLE_TOIE2):
				GPtr_TIMER2_IRQCallBack[TIMER2_OVF_VECTOR_ID] = TIMER2_Config->P_IRQ_CallBack;
			break;
			case(TIMER2_IRQ_ENABLE_OCIE2):
				GPtr_TIMER2_IRQCallBack[TIMER2_CTC_VECTOR_ID] = TIMER2_Config->P_IRQ_CallBack;
			break;
		}
}
void MCAL_TIMER2_DeInit(void){
	/* Reset the Pre-scaler */
	TCCR2->CS20 = LOW;
	TCCR2->CS21 = LOW;
	TCCR2->CS22 = LOW;
}
void MCAL_TIMER2_GetCounterValue(uint8_t* TicksNumber){
	*TicksNumber = TCNT2;
}

void MCAL_TIMER2_SetCounterValue(uint8_t u8_TicksNumber){
	TCNT2 = u8_TicksNumber;
}

void MCAL_TIMER2_GetCompareValue(uint8_t* TicksNumber){
	 *TicksNumber = OCR2;
}
void MCAL_TIMER2_SetCompareValue(uint8_t  u8TicksNumber){
	OCR2 = u8TicksNumber;
}
void MCAL_TIMER2_SetPWMDutyCycle(TIMER2Configuration_t* TIMER2_Config,uint8_t Duty_Cycle){
		if(TIMER2_Config->Timer2Mode == TIMER2_MODE_Fast_PWM_Noninverting)
		{
			OCR2 = Duty_Cycle;
		}
		else if(TIMER2_Config->Timer2Mode == TIMER2_MODE_Fast_PWM_Inverting)
		{
			OCR2 = (uint8_t)(255 - Duty_Cycle);
		}
}