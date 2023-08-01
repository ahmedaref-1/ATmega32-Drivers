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
