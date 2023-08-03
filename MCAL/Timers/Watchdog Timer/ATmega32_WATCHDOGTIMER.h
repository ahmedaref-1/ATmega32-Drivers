/*
 * ATmega32_WATCHDOGTIMER.h
 *
 * Created: 8/1/2023 3:28:52 PM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef ATMEGA32_WATCHDOGTIMER_H_
#define ATMEGA32_WATCHDOGTIMER_H_
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
uint8_t WDT_Prescaler;
}WATCHDOGTIMER_WatchDogTimerConfiguration_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/
/********** WDT Prescaler select ******************/
#define		WDT_PreScaler_16_3_MS			0 //16.3 mS
#define		WDT_PreScaler_32_5_MS	   		1 //32.5 mS
#define		WDT_PreScaler_65_MS	     		2 //65   mS
#define		WDT_PreScaler_0_13_S			3 //0.13 S
#define		WDT_PreScaler_0_26_S			4 //0.26 S
#define		WDT_PreScaler_0_52_S			5 //0.52 S
#define		WDT_PreScaler_1_0_S				6 //1.0  S
#define		WDT_PreScaler_2_1_S				7 //2.1  S


/****************************************************
 *													*
 *  APIs Supported by "MCAL WATCHDOG TIMER DRIVER"  *
 *  												*
 ****************************************************/
void MCAL_WATCHDOGTIMER_WDTSleep(WATCHDOGTIMER_WatchDogTimerConfiguration_t* WDTConfiguration);
void MCAL_WATCHDOGTIMER_WDTEnable (void);
void MCAL_WATCHDOGTIMER_WDTDisable(void);


#endif /* ATMEGA32_WATCHDOGTIMER_H_ */