/*
 * ATmega32_EXTERNALINTERRUPTS.c
 *
 * Created: 7/30/2023 3:56:17 AM
 *  Author: Ahmed Aref Omaira
 */ 
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_EXTERNALINTERRUPTS.h"


/*********************************************
 *                                           *
 *         IRQ HANDLERS DEFINITION           *
 * 							    			 *
 *********************************************/
ISR(EXTI0_IRQHandler) {
	if (GPtr_IRQCallBack[0] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_IRQCallBack[0]();
		//This bit is cleared by writing a ‘1’ into the bit
		GIFR->INTF0 = HIGH;
	}
}

ISR(EXTI1_IRQHandler) {
	if (GPtr_IRQCallBack[1] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_IRQCallBack[1]();
		//This bit is cleared by writing a ‘1’ into the bit
		GIFR->INTF1 = HIGH;
	}
}

ISR(EXTI2_IRQHandler) {
	if (GPtr_IRQCallBack[2] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_IRQCallBack[2]();
		//This bit is cleared by writing a ‘1’ into the bit
		GIFR->INTF2 = HIGH;
	}
}

/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 * ****************************************/
/*******************************************
 *      EXTERNALLY USED FUNCITONS          *
 * *****************************************/
void MCAL_EXTI_Enable( EXTI_InterruptConfig_t* interruptConfiguration){
			// 1.Enable the Global Interrupt
			Enable_GlobalInterrupt();
			// 2.Choose which external interrupt signal 
			switch (interruptConfiguration->EXTI_LineNumber) {
				case EXTI_LINE0:
				// 3.Enable the chosen external interrupt in the General Interrupt Control Register
				GICR->INT0 = HIGH;
				// 4.Pass the Call Back Pointer to Function to the global array to be executed by the ISR
				GPtr_IRQCallBack[0] = interruptConfiguration->P_IRQ_CallBack;
				// 5.Choose the Interrupt Sense
				switch (interruptConfiguration->EXTI_TriggerCase) {
					case EXTI_LOW_LEVEL:
					MCUCR->ISC00 = LOW;
					MCUCR->ISC01 = LOW;
					break;
					case EXTI_ON_CHANGE:
					MCUCR->ISC00 = HIGH;
					MCUCR->ISC01 = LOW;
					break;
					case EXTI_FALLING_EDGE:
					MCUCR->ISC00 = LOW;
					MCUCR->ISC01 = HIGH;
					break;
					case EXTI_RISING_EDGE:
					MCUCR->ISC00 = LOW;
					MCUCR->ISC01 = HIGH;
					break;
				}
				break;

				case EXTI_LINE1:
				GPtr_IRQCallBack[1] = interruptConfiguration->P_IRQ_CallBack;
				GICR->INT1 = HIGH;
				switch (interruptConfiguration->EXTI_TriggerCase) {
					case EXTI_LOW_LEVEL:
					MCUCR->ISC10 = LOW;
					MCUCR->ISC11 = LOW;;
					break;
					case EXTI_ON_CHANGE:
					MCUCR->ISC10 = HIGH;
					MCUCR->ISC11 = LOW;
					break;
					case EXTI_FALLING_EDGE:
					MCUCR->ISC10 = LOW;
					MCUCR->ISC11 = HIGH;
					break;
					case EXTI_RISING_EDGE:
					MCUCR->ISC10 = LOW;
					MCUCR->ISC11 = HIGH;
					break;
				}
				break;

				case EXTI_LINE2:
				GPtr_IRQCallBack[2] = interruptConfiguration->P_IRQ_CallBack;
				GICR->INT2 = HIGH;
				switch (interruptConfiguration->EXTI_TriggerCase) {
					case EXTI_FALLING_EDGE:
					MCUCSR->ISC2 = LOW;
					break;
					case EXTI_RISING_EDGE:
					MCUCSR->ISC2 = HIGH;
					break;
				}
				break;
			}
}
void MCAL_EXTI_Disable( uint8_t externalInterruptLineNumber){
		switch (externalInterruptLineNumber) {
			case EXTI_LINE0:
			GICR->INT0 = LOW;
			break;
			case EXTI_LINE1:
			GICR->INT1 = LOW;
			break;
			case EXTI_LINE2:
			GICR->INT2 = LOW;
			break;
		}
}
void MCAL_EXTI_Update (EXTI_InterruptConfig_t* EXTI_Config){
	MCAL_EXTI_Enable(EXTI_Config);
}
