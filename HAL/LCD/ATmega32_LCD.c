/*
 * ATmega32_LCD.c
 *
 * Created: 8/5/2023 6:23:40 AM
 *  Author: Ahmed Aref Omaira
 */ 
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 * ****************************************/
#include "ATmega32_LCD.h"


/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 * ****************************************/
/******************************************
*      INTERNAL FUNCTIONS DEFINITION      *
*******************************************/
void _delay_ms(uint8_t n){
	for(uint8_t i = 0 ; i <= n ; i++)
		for(uint8_t j = 0 ; j < 255 ; j++);
}


void HAL_LCD_GPIOINIT(void){
	
		// 1.Configure the Data Pins (D0->D7) as Input to read from the LCD
		GPIOConfiguration_t LCDconfig;
		LCDconfig.GPIO_Mode = GPIO_MODE_INPUT_HiZ;
	
	#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
		LCDconfig.GPIO_Pin = LCD_D0_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D1_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D2_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D3_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	#endif
		LCDconfig.GPIO_Pin = LCD_D4_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D5_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D6_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D7_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		
		// 2.Configure the control Pins to the Read Mode
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_HIGH);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_LOW);
		
		HAL_LCD_kick();
		
		// 3.Configure the Data Pins (D0->D7) as Output to write on the LCD
		LCDconfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
		
	#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
		LCDconfig.GPIO_Pin = LCD_D0_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D1_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D2_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D3_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	#endif
		LCDconfig.GPIO_Pin = LCD_D4_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D5_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D6_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
		LCDconfig.GPIO_Pin = LCD_D7_PIN;
		MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);

		// 4.Configure the control Pins to the Write Mode
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_LOW);		
}


void HAL_LCD_kick(void){
	//1.Make PIN(E) Enabled, to pulse the LCD that i will send a command or data
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_EN_SWITCH , GPIO_PIN_HIGH);
	
	_delay_ms(5);
	
	//2.Return PIN(E) Disabled,To notify the LCD that the command or the data is about to be sent
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_EN_SWITCH , GPIO_PIN_LOW);
}
/******************************************
*      EXTERNAL FUNCTIONS DEFINITION      *
*******************************************/
void HAL_LCD_Init(void){
	// 1. must wait more than 30 ms before any action (VDD rises to 4.5 v)
	_delay_ms(50);
	
	//2.Configure all Pins Control and Data as OutPut pins
	GPIOConfiguration_t LCDconfig;
	LCDconfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	
	//2.1.Configure all the control pins(E,RS,RW) as OutPut pins
	LCDconfig.GPIO_Pin = LCD_EN_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT,&LCDconfig);
	LCDconfig.GPIO_Pin = LCD_RW_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT,&LCDconfig);
	LCDconfig.GPIO_Pin = LCD_RS_SWITCH;
	MCAL_GPIO_Init(LCD_CTRL_PORT,&LCDconfig);
	
	//2.2.Make control pins off to do (reset/set) according the command we want to do after then
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH ,GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_LOW);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_EN_SWITCH , GPIO_PIN_LOW);

	//2.3.Configure all the data pins to work as output
	#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
	LCDconfig.GPIO_Pin = LCD_D0_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_Pin = LCD_D1_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_Pin = LCD_D2_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_Pin = LCD_D3_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	#endif
	LCDconfig.GPIO_Pin = LCD_D4_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_Pin = LCD_D5_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_Pin = LCD_D6_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	LCDconfig.GPIO_Pin = LCD_D7_PIN;
	MCAL_GPIO_Init(LCD_DATA_PORT, &LCDconfig);
	
	_delay_ms(50);
	
	//3.Clear screen to be ready
	HAL_LCD_ClearScreen();
	
	//4.Choose the operating mode
	#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
	HAL_LCD_SendCommand(LCD_CMD_8BIT_MODE_2_LINE);
	#endif
	#if LCD_OPERATING_MODE == FOUR_BIT_MODE
	HAL_LCD_SendCommand(LCD_CMD_4BIT_MODE_2_LINE_FIRST);
	HAL_LCD_SendCommand(LCD_CMD_4BIT_MODE_2_LINE_SECOND);
	#endif
	
	//5.Entry mode configuration
	HAL_LCD_SendCommand(LCD_CMD_ENTERY_MODE_INC_SHIFT_OFF);
	HAL_LCD_SendCommand(LCD_CMD_BEGIN_AT_FIRST_ROW);
	HAL_LCD_SendCommand(LCD_CMD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON);
}


void HAL_LCD_SendCommand(uint8_t command){
	#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
		MCAL_GPIO_WritePort(LCD_DATA_PORT,command);
		//1.Write Command Mode
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_LOW);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_LOW);
		HAL_LCD_kick();
	#endif
	#if LCD_OPERATING_MODE == FOUR_BIT_MODE
		//1.Send Most Significant 4 Bits in the command
		MCAL_GPIO_WritePort(LCD_DATA_PORT,((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0x0F) | (command & 0xF0)));
		//2.Write Command Mode
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_LOW);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_LOW);
		HAL_LCD_kick();
		//3.Send Least Significant 4 Bits in the command
		MCAL_GPIO_WritePort(LCD_DATA_PORT,((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0x0F) | ((command & 0x0F) << FOUR_BIT_MODE)));
		//4.Write Command Mode
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_LOW);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_LOW);
		HAL_LCD_kick();
	#endif
}


void HAL_LCD_DisplayCharacter(uint8_t character){
	#if LCD_OPERATING_MODE == EIGHT_BIT_MODE
		MCAL_GPIO_WritePort(LCD_DATA_PORT, character);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_HIGH);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_LOW);
		_delay_ms(20);
		HAL_LCD_kick();
	#endif
	#if LCD_OPERATING_MODE == FOUR_BIT_MODE
		MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0x0F) | (character & 0xF0)));
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_HIGH);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_LOW);
		_delay_ms(20);
		HAL_LCD_kick();
		MCAL_GPIO_WritePort(LCD_DATA_PORT, ((MCAL_GPIO_ReadPort(LCD_DATA_PORT) & 0x0F) | ((character & 0x0F) << FOUR_BIT_MODE)));
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_SWITCH , GPIO_PIN_HIGH);
		MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_SWITCH , GPIO_PIN_LOW);
		_delay_ms(20);
		HAL_LCD_kick();
	#endif
}


void HAL_LCD_DisplayString(uint8_t *string){
		uint8_t counter = 0;
		while(*string != 0)
		{
			if(counter == 16)
			{
				HAL_LCD_SetPosition(LCD_SECOND_LINE, LCD_FIRST_COLUMN);
			}
			
			HAL_LCD_DisplayCharacter(*string ++);
			counter++;
			
			if(counter > 31)
			{
				HAL_LCD_SendCommand(LCD_CMD_CLEAR );
				HAL_LCD_SetPosition(LCD_FIRST_LINE, LCD_FIRST_COLUMN);
				counter = 0 ;
			}
			
		}
}


void HAL_LCD_SetPosition(uint8_t row ,uint8_t column){
		if (row == 0)
		{
			if (column < 16 && column >= 0)
			{
				HAL_LCD_SendCommand(LCD_CMD_BEGIN_AT_FIRST_ROW + column);
			}
		}
		else if (row == 1)
		{
			if (column < 16 && column >= 0)
			{
				HAL_LCD_SendCommand(LCD_CMD_BEGIN_AT_SECOND_ROW + column);
			}
		}
}


void HAL_LCD_ClearScreen(void){
	HAL_LCD_SendCommand(LCD_CMD_CLEAR);
}


void HAL_LCD_DisplayInteger(uint32_t number){
		char str[7];
		sprintf(str,"%d",number);
		HAL_LCD_DisplayString(str);
}


void HAL_LCD_DispalyReal(float32_t number){
			char str[16];
			char *tmpSign = (number < 0)?"-":"-";
			float tmpVal = (number < 0)?-number :number;
			
			int tmpInt1 = tmpVal;
			float tmpFrac = tmpVal -tmpInt1;
			int tmpInt2 = tmpFrac*10000;
			sprintf(str,"%s%d.%o4d",tmpSign,tmpInt1,tmpInt2);
			HAL_LCD_DisplayString(str);
}