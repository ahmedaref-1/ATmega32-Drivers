/*
 * ATmega32_LCD.h
 *
 * Created: 8/5/2023 2:29:40 AM
 *  Author: Ahmed Aref Omaira
 */ 

/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include "ATmega32_GPIO.h"
#include "ATmega32_REGISTERS.h"


/******************************************
 *                                        *
 *   LCD INTERFACING AND CONFIGURATION    *
 * 										  *
 * ****************************************/
/*******************************************
 *             MODE CONFIGURATION          *
 * *****************************************/
#define	EIGHT_BIT_MODE 				8
#define FOUR_BIT_MODE				4
#define LCD_OPERATING_MODE 			FOUR_BIT_MODE

/*******************************************
 *             LCD INTERFACING             *
 * *****************************************/
#define LCD_DATA_PORT		GPIOA
#define LCD_CTRL_PORT		GPIOB

#define LCD_EN_SWITCH		GPIO_PIN_3
#define LCD_RW_SWITCH		GPIO_PIN_2
#define LCD_RS_SWITCH		GPIO_PIN_1

#define LCD_D0_PIN			GPIO_PIN_0
#define LCD_D1_PIN			GPIO_PIN_1
#define LCD_D2_PIN			GPIO_PIN_2
#define LCD_D3_PIN			GPIO_PIN_3
#define LCD_D4_PIN			GPIO_PIN_4
#define LCD_D5_PIN			GPIO_PIN_5
#define LCD_D6_PIN			GPIO_PIN_6
#define LCD_D7_PIN			GPIO_PIN_7

#define LCD_FIRST_LINE		(0UL)
#define LCD_SECOND_LINE		(1UL)
#define LCD_FIRST_COLUMN	(0UL)

/*******************************************
 *               LCD COMMANDS              *
 * *****************************************/
#define LCD_CMD_CLEAR                                  0x01
#define LCD_CMD_4BIT_MODE_2_LINE_FIRST                 0x02
#define LCD_CMD_ENTERY_MODE_DEC_SHIFT_OFF              0x04
#define LCD_CMD_ENTERY_MODE_DEC_SHIFT_ON               0x05
#define LCD_CMD_ENTERY_MODE_INC_SHIFT_OFF              0x06
#define LCD_CMD_ENTERY_MODE_INC_SHIFT_ON               0x07
#define LCD_CMD_CURSOR_MOVE_SHIFT_LEFT                 0x10
#define LCD_CMD_CURSOR_MOVE_SHIFT_RIGHT                0x14
#define LCD_CMD_DISPLAY_SHIFT_LEFT                     0x18
#define LCD_CMD_DISPLAY_SHIFT_RIGHT                    0x1C
#define LCD_CMD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF    0x0C
#define LCD_CMD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON     0x0D
#define LCD_CMD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF     0x0E
#define LCD_CMD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON      0x0F
#define LCD_CMD_DISPLAY_OFF_CURSOR_OFF                 0x08
#define LCD_CMD_8BIT_MODE_2_LINE                       0x38
#define LCD_CMD_4BIT_MODE_2_LINE_SECOND                0x28
#define LCD_CMD_BEGIN_AT_FIRST_ROW				       0x80
#define LCD_CMD_BEGIN_AT_SECOND_ROW				       0xC0

/******************************************
 *                                        *
 *   APIs SUPPORTED BY THE "LCD DRIVER"   *
 * 										  *
 * ****************************************/
void HAL_LCD_IsBusy(void);
void HAL_LCD_kick(void);
void HAL_LCD_SendCommand(uint8_t command);
void HAL_LCD_Init(void);
void HAL_LCD_DisplayCharacter(uint8_t character);
void HAL_LCD_DisplayString(uint8_t *The_char);
void HAL_LCD_SetPosition(uint8_t line ,uint8_t pos);
void HAL_LCD_ClearScreen(void);
void HAL_LCD_DisplayInteger(uint32_t number);
void HAL_LCD_DispalyReal(float32_t number);