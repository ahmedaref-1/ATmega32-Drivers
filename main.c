/*
 * ATmega32.c
 *
 * Created: 7/29/2023 9:32:11 PM
 * Author : Ahmed Aref Omaira
 */ 

#include "ATmega32_GPIO.h"
#include "ATmega32_EXTERNALINTERRUPTS.h"
void isr(void){
	MCAL_GPIO_TogglePin(GPIOD,GPIO_PIN_5);
	MCAL_GPIO_TogglePin(GPIOD,GPIO_PIN_6);
	MCAL_GPIO_TogglePin(GPIOD,GPIO_PIN_7);

}

int main(void)
{	
	//1.Configuring port D pins 5,6&7 as Output
	GPIOConfiguration_t outputConfiguration;
	outputConfiguration.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	outputConfiguration.GPIO_Pin = GPIO_PIN_5;
	MCAL_GPIO_Init(GPIOD,&outputConfiguration);
	outputConfiguration.GPIO_Pin = GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOD,&outputConfiguration);
	outputConfiguration.GPIO_Pin = GPIO_PIN_7;
	MCAL_GPIO_Init(GPIOD,&outputConfiguration);
	
	//2.Configuring port D pin 2 as input
	GPIOConfiguration_t inputConfiguration;
	inputConfiguration.GPIO_Mode = GPIO_MODE_INPUT_HiZ;
	inputConfiguration.GPIO_Pin = GPIO_PIN_2;
	MCAL_GPIO_Init(GPIOD,&inputConfiguration);
	
	//3.Configuring port D pin2 interrupt
	EXTIConfiguration_t interruptConfiguration;
	interruptConfiguration.EXTI_LineNumber = EXTI_PD2;
	interruptConfiguration.EXTI_TriggerCase = EXTI_RISING_EDGE;
	interruptConfiguration.P_IRQ_CallBack = isr;
	MCAL_EXTI_Enable(&interruptConfiguration);

	while(1){
		
	}
}
