/*
 * ATmega32_WATCHDOGTIMER.c
 *
 * Created: 8/1/2023 3:29:03 PM
 *  Author: Ahmed Aref Omaira
 */ 

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_WATCHDOGTIMER.h"


/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 ******************************************/
void MCAL_WATCHDOGTIMER_WDTSleep(WATCHDOGTIMER_WatchDogTimerConfiguration_t* WDTConfiguration){
	switch(WDTConfiguration->WDT_Prescaler){
		case(WDT_PreScaler_16_3_MS):
			WDTCR->WDP0 = LOW;
			WDTCR->WDP1 = LOW;
			WDTCR->WDP2 = LOW; 
		break;
		case(WDT_PreScaler_32_5_MS):
			WDTCR->WDP0 = HIGH;
			WDTCR->WDP1 = LOW;
			WDTCR->WDP2 = LOW;
		break;
		case(WDT_PreScaler_65_MS):
			WDTCR->WDP0 = LOW;
			WDTCR->WDP1 = HIGH;
			WDTCR->WDP2 = LOW;
		break;
		case(WDT_PreScaler_0_13_S):
			WDTCR->WDP0 =
			WDTCR->WDP1 =
			WDTCR->WDP2 = LOW;
		break;
		case(WDT_PreScaler_0_26_S):
			WDTCR->WDP0 = LOW;
			WDTCR->WDP1 = LOW;
			WDTCR->WDP2 = HIGH;
		break;
		case(WDT_PreScaler_0_52_S):
			WDTCR->WDP0 = HIGH;
			WDTCR->WDP1 = LOW;
			WDTCR->WDP2 = HIGH;
		break;
		case(WDT_PreScaler_1_0_S):
			WDTCR->WDP0 = LOW;
			WDTCR->WDP1 = HIGH;
			WDTCR->WDP2 = HIGH;
		break;
		case(WDT_PreScaler_2_1_S):
			WDTCR->WDP0 = HIGH;
			WDTCR->WDP1 = HIGH;
			WDTCR->WDP2 = HIGH;
		break;		
	}
}
void MCAL_WATCHDOGTIMER_WDTEnable (void){
	WDTCR->WDE = HIGH;
}
void MCAL_WATCHDOGTIMER_WDTDisable(void){
	/* Set Bit 3&4 at the same CLK cycle  */
	WDTCR->WDTCR_ALL |= 0b00011000 ;
	/* I don't care for any value in this Reg because I want to Disable */
	WDTCR->WDTCR_ALL = 0 ;
}
