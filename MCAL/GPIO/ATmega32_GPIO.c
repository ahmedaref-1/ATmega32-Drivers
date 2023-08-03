/*
 * ATmega32_GPIO.c
 *
 * Created: 7/30/2023 3:55:23 AM
 *  Author: Ahmed Aref Omaira
 */ 
/******************************************
 *                                        *
 *                INCLUDES                *
 * 										  *
 ******************************************/
#include "ATmega32_GPIO.h"

/******************************************
 *                                        *
 *         FUNCTIONS DEFINITION           *
 * 										  *
 ******************************************/
/*******************************************
 *        EXTERNALLY USED FUNCITONS        *
 *******************************************/
/* ================================================================
 * @Fn			-MCAL_GPIO_Init.
 * @brief	    -initialize the GPIOx PINy according to config instance PinConfig.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-PinConfig: pointer to GPIO_config that contains pin/port configuration.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_Init(GPIO_Typedef_t *GPIOx,GPIOConfiguration_t *PinConfig)
{
	switch(PinConfig->GPIO_Pin)
	{
		case GPIO_PIN_0:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
				    GPIOx->DDR.bits.DD0 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT0 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD0 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT0 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD0 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT0 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		
		case GPIO_PIN_1:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.bits.DD1 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT1 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD1 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT1 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD1 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT1 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_2:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.bits.DD2 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT2 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD2 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT2 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD2 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT2 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		
		case GPIO_PIN_3:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.bits.DD3 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT3 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD3 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT3 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD3 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT3 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_4:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.bits.DD4 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT4 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD4 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT4 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD4 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT4 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		
		case GPIO_PIN_5:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.bits.DD5 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT5 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD5 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT5 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD5 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT5 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_6:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.bits.DD6 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT6 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD6 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT6 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD6 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT6 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		case GPIO_PIN_7:{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.bits.DD7 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT7 = GPIO_PIN_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.bits.DD7 = GPIO_PIN_LOW;
					GPIOx->PORT.bits.PORT7 = GPIO_PIN_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.bits.DD7 = GPIO_PIN_HIGH;
					GPIOx->PORT.bits.PORT7 = GPIO_PIN_LOW;
					break;
				}
			}
			break;
		}
		
		case GPIO_PIN_ALL:
		{
			switch(PinConfig->GPIO_Mode)
			{
				case GPIO_MODE_INPUT_HiZ:
				{
					GPIOx->DDR.DDR = GPIO_PORT_LOW;
					GPIOx->PORT.PORT = GPIO_PORT_LOW;
					break;
				}
				case GPIO_MODE_INPUT_PU:
				{
					GPIOx->DDR.DDR = GPIO_PORT_LOW;
					GPIOx->PORT.PORT = GPIO_PORT_HIGH;
					break;
				}
				case GPIO_MODE_OUTPUT_PP:
				{
					GPIOx->DDR.DDR = GPIO_PORT_HIGH;
					GPIOx->PORT.PORT = GPIO_PORT_LOW;
					break;
				}
			}
			break;
		}
	}
}

/* ================================================================
 * @Fn			-MCAL_GPIO_DeInit.
 * @brief	    -Reset the GPIOx registers.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_DeInit(GPIO_Typedef_t *GPIOx)
{
	GPIOx->DDR.DDR = GPIO_PORT_LOW;
	GPIOx->PORT.PORT = GPIO_PORT_LOW;
}

/* ================================================================
 * @Fn			-MCAL_GPIO_ReadPin.
 * @brief	    -Reads the GPIOx PINy input value.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be read.
 * @retval 		-either one of two states check: @ref GPIO_PIN_STATE
 * Note			-none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef_t *GPIOx,uint8_t PinNumber)
{
	uint8_t PinState = GPIO_PIN_LOW;
	switch(PinNumber)
	{
		case GPIO_PIN_0:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN0);
			break;
		}
		
		case GPIO_PIN_1:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN1);
			break;
		}
		
		case GPIO_PIN_2:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN2);
			break;
		}
		
		case GPIO_PIN_3:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN3);
			break;
		}
		
		case GPIO_PIN_4:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN4);
			break;
		}
		
		case GPIO_PIN_5:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN5);
			break;
		}
		
		case GPIO_PIN_6:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN6);
			break;
		}
		
		case GPIO_PIN_7:
		{
			PinState = (uint8_t)(GPIOx->PIN.bits.PIN7);
			break;
		}
	}
		return PinState;
}

/* ================================================================
 * @Fn			-MCAL_GPIO_ReadPort.
 * @brief	    -Reads the GPIOx input value.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @retval 		-the input value on GPIOx
 * Note			-none
 */
uint8_t MCAL_GPIO_ReadPort(GPIO_Typedef_t *GPIOx)
{
	uint8_t PortState = GPIO_PORT_LOW;
	PortState = ((uint8_t)(GPIOx->PIN.PIN));
	return PortState;
}

/* ================================================================
 * @Fn			-MCAL_GPIO_WritePin.
 * @brief	    -writes either one of @ref GPIO_PIN_STATE value on the GPIOx PINy.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be read.
 * @param [in]  -Value: Specifies one of @ref GPIO_PIN_STATE to be written.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_WritePin(GPIO_Typedef_t *GPIOx,uint8_t PinNumber,uint8_t Value)
{
	switch(PinNumber)
	{
		case GPIO_PIN_0:
		{
			if(Value)
				GPIOx->PORT.bits.PORT0 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT0 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_1:
		{
			if(Value)
				GPIOx->PORT.bits.PORT1 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT1 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_2:
		{
			if(Value)
				GPIOx->PORT.bits.PORT2 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT2 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_3:
		{
			if(Value)
				GPIOx->PORT.bits.PORT3 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT3 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_4:
		{
			if(Value)
				GPIOx->PORT.bits.PORT4 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT4 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_5:
		{
			if(Value)
				GPIOx->PORT.bits.PORT5 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT5 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_6:
		{
			if(Value)
				GPIOx->PORT.bits.PORT6 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT6 = GPIO_PIN_LOW;
			break;
		}
		case GPIO_PIN_7:
		{
			if(Value)
				GPIOx->PORT.bits.PORT7 = GPIO_PIN_HIGH;
			else
				GPIOx->PORT.bits.PORT7 = GPIO_PIN_LOW;
			break;
		}
	}
}

/* ================================================================
 * @Fn			-MCAL_GPIO_WritePort.
 * @brief	    -writes Value on the GPIOx.
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-Value: Specifies the Value to be written.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_WritePort(GPIO_Typedef_t *GPIOx,uint8_t Value)
{
		GPIOx->PORT.PORT = Value;
}

/* ================================================================
 * @Fn			-MCAL_GPIO_TogglePin.
 * @brief	    -toggle the GPIOx PINy .
 * @param [in] 	-GPIOx: x can be (A...D) to select the GPIO peripheral.
 * @param [in] 	-PinNumber: Specifies the PIN to be toggled.
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_TogglePin(GPIO_Typedef_t *GPIOx,uint8_t PinNumber)
{
	switch(PinNumber)
	{
		case GPIO_PIN_0:
		{
			GPIOx->PORT.bits.PORT0 ^= GPIO_PIN_HIGH;
			break;
		}
		
		case GPIO_PIN_1:
		{
			GPIOx->PORT.bits.PORT1 ^= GPIO_PIN_HIGH;
			break;
		}
		
		case GPIO_PIN_2:
		{
			GPIOx->PORT.bits.PORT2 ^= GPIO_PIN_HIGH;
			break;
		}
		
		case GPIO_PIN_3:
		{
			GPIOx->PORT.bits.PORT3 ^= GPIO_PIN_HIGH;
			break;
		}
		
		case GPIO_PIN_4:
		{
			GPIOx->PORT.bits.PORT4 ^= GPIO_PIN_HIGH;
			break;
		}
		
		case GPIO_PIN_5:
		{
			GPIOx->PORT.bits.PORT5 ^= GPIO_PIN_HIGH;
			break;
		}
		
		case GPIO_PIN_6:
		{
			GPIOx->PORT.bits.PORT6 ^= GPIO_PIN_HIGH;
			break;
		}
		
		case GPIO_PIN_7:
		{
			GPIOx->PORT.bits.PORT7 ^= GPIO_PIN_HIGH;
			break;
		}
	}
}