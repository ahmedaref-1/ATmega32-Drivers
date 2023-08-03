/*
 * ATmega32_GPIO.h
 *
 * Created: 7/30/2023 3:55:13 AM
 *  Author: Ahmed Aref Omaira
 */ 


#ifndef ATMEGA32_GPIO_H_
#define ATMEGA32_GPIO_H_

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
 *   PIN CONFIGURATION TYPEDEF USED BY USER   *
 *       	                                  *
 **********************************************/
typedef struct{

	/*
	 1.Specifies the GPIO PIN to be configured
	 2.This parameter can be a value of @ref GPIO_PIN_NUMBERS
	*/
	uint16_t GPIO_Pin;
	/*
	 1.Specifies the Mode for selected pin.
	 2.This parameter can be a value of @ref GPIO_PIN_MODES
	*/	
	uint8_t GPIO_Mode;					
}GPIOConfiguration_t;


/**************************************************
 *                                                *
 *   CONFIGURATION MACROS REFRENCES DEFINITIONS   *
 *                                                *
 **************************************************/
/*******************************************
 *          @ref GPIO_PIN_NUMBERS          *
 *******************************************/
#define GPIO_PIN_0                     ((uint16_t)0x0001) // Pin 0 Selected
#define GPIO_PIN_1                     ((uint16_t)0x0002) // Pin 1 Selected
#define GPIO_PIN_2                     ((uint16_t)0x0004) // Pin 2 Selected
#define GPIO_PIN_3                     ((uint16_t)0x0008) // Pin 3 Selected
#define GPIO_PIN_4                     ((uint16_t)0x0010) // Pin 4 Selected
#define GPIO_PIN_5                     ((uint16_t)0x0020) // Pin 5 Selected
#define GPIO_PIN_6                     ((uint16_t)0x0040) // Pin 6 Selected
#define GPIO_PIN_7                     ((uint16_t)0x0080) // Pin 7 Selected
#define GPIO_PIN_8                     ((uint16_t)0x0100) // Pin 8 Selected
#define GPIO_PIN_9                     ((uint16_t)0x0200) // Pin 9 Selected
#define GPIO_PIN_10                    ((uint16_t)0x0400) // Pin 10 Selected
#define GPIO_PIN_11                    ((uint16_t)0x0800) // Pin 11 Selected
#define GPIO_PIN_12                    ((uint16_t)0x1000) // Pin 12 Selected
#define GPIO_PIN_13                    ((uint16_t)0x2000) // Pin 13 Selected
#define GPIO_PIN_14                    ((uint16_t)0x4000) // Pin 14 Selected
#define GPIO_PIN_15                    ((uint16_t)0x8000) // Pin 15 Selected
#define GPIO_PIN_ALL                   ((uint16_t)0xFFFF) // ALL Pins Selected

/*******************************************
 *           @ref GPIO_PIN_MODES           *
 *******************************************/
#define GPIO_MODE_INPUT_HiZ			0	//0: Input with Hi-Z (reset state)
#define GPIO_MODE_INPUT_PU			1	//1: Input with pull-up
#define GPIO_MODE_OUTPUT_PP			2	//2: Output push-pull

/*******************************************
 *           @ref GPIO_PIN_STATE           *
 *******************************************/
#define GPIO_PIN_HIGH					0b1
#define GPIO_PIN_LOW					0b0
#define GPIO_PIN_SET					0b1
#define GPIO_PIN_RESET					0b0
#define GPIO_PORT_HIGH					(uint8_t)0xFF
#define GPIO_PORT_LOW					(uint8_t)0x00
#define GPIO_NIPPLE_HIGH				0xF
#define GPIO_NIPPLE_LOW					0x0

/******************************************
 *                                        *
 *  APIs Supported by "MCAL GPIO DRIVER"  *
 *  									  *
 ******************************************/
void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx,GPIOConfiguration_t *PinConfig);
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx);
uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx,uint8_t PinNumber);
uint8_t MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx);
void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx,uint8_t PinNumber,uint8_t Value);
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx,uint8_t Value);
void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx,uint8_t PinNumber);

#endif /* ATMEGA32_GPIO_H_ */