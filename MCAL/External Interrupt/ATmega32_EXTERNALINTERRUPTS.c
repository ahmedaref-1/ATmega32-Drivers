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
		SET_BIT(GIFR, GIFR_INTF0_BIT);
	}
}

ISR(EXTI1_IRQHandler) {
	if (GPtr_IRQCallBack[1] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_IRQCallBack[1]();
		//This bit is cleared by writing a ‘1’ into the bit
		SET_BIT(GIFR, GIFR_INTF1_BIT);
	}
}

ISR(EXTI2_IRQHandler) {
	if (GPtr_IRQCallBack[2] != NULL) {
		//Call Back C function() which will be called once IRQ happen
		GPtr_IRQCallBack[2]();
		//This bit is cleared by writing a ‘1’ into the bit
		SET_BIT(GICR, GICR_INT2_BIT);
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
				// 3.Enable the choosen external interrupt in the General Interupt Control Register
				SET_BIT(GICR, GICR_INT0_BIT);
				// 4.Pass the Call Back Pointer to Function to the global array to be exectued by the ISR
				GPtr_IRQCallBack[0] = interruptConfiguration->P_IRQ_CallBack;
				// 5.Choose the Interrupt Sense
				switch (interruptConfiguration->EXTI_TriggerCase) {
					case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR, MCUCR_ISC00_BIT);
					CLR_BIT(MCUCR, MCUCR_ISC01_BIT);
					break;
					case EXTI_ON_CHANGE:
					SET_BIT(MCUCR, MCUCR_ISC00_BIT);
					CLR_BIT(MCUCR, MCUCR_ISC01_BIT);
					break;
					case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCR, MCUCR_ISC00_BIT);
					SET_BIT(MCUCR, MCUCR_ISC01_BIT);
					break;
					case EXTI_RISING_EDGE:
					CLR_BIT(MCUCR, MCUCR_ISC00_BIT);
					SET_BIT(MCUCR, MCUCR_ISC01_BIT);
					break;
				}
				break;

				case EXTI_LINE1:
				GPtr_IRQCallBack[1] = interruptConfiguration->P_IRQ_CallBack;
				SET_BIT(GICR, GICR_INT1_BIT);
				switch (interruptConfiguration->EXTI_TriggerCase) {
					case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR, MCUCR_ISC10_BIT);
					CLR_BIT(MCUCR, MCUCR_ISC11_BIT);
					break;
					case EXTI_ON_CHANGE:
					SET_BIT(MCUCR, MCUCR_ISC10_BIT);
					CLR_BIT(MCUCR, MCUCR_ISC11_BIT);
					break;
					case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCR, MCUCR_ISC10_BIT);
					SET_BIT(MCUCR, MCUCR_ISC11_BIT);
					break;
					case EXTI_RISING_EDGE:
					CLR_BIT(MCUCR, MCUCR_ISC10_BIT);
					SET_BIT(MCUCR, MCUCR_ISC11_BIT);
					break;
				}
				break;

				case EXTI_LINE2:
				GPtr_IRQCallBack[2] = interruptConfiguration->P_IRQ_CallBack;
				SET_BIT(GICR, GICR_INT2_BIT);
				switch (interruptConfiguration->EXTI_TriggerCase) {
					case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR, MCUCSR_ISC2_BIT);
					break;
					case EXTI_RISING_EDGE:
					SET_BIT(MCUCSR, MCUCSR_ISC2_BIT);
					break;
				}
				break;
			}
}
void MCAL_EXTI_Disable( uint8_t externalInterruptLineNumber){
		switch (externalInterruptLineNumber) {
			case EXTI_LINE0:
			CLR_BIT(GICR, GICR_INT0_BIT);
			break;
			case EXTI_LINE1:
			CLR_BIT(GICR, GICR_INT1_BIT);
			break;
			case EXTI_LINE2:
			CLR_BIT(GICR, GICR_INT2_BIT);
			break;
		}
}
void MCAL_EXTI_Update (EXTI_InterruptConfig_t* EXTI_Config){
	MCAL_EXTI_Enable(EXTI_Config);
}