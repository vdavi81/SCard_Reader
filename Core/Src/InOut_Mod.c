/*
 * InOut_Mod.c
 *
 *  Created on: Jul 2, 2024
 *      Author: vdavi81
 */
#include "InOut_Mod.h"
#include "main.h"

void iomod_ScanINs(iomod_Input_t *INS)
{
	INS->IN1 = (uint8_t)HAL_GPIO_ReadPin(IN1_GPIO_Port, IN1_Pin);
	INS->IN2 = (uint8_t)HAL_GPIO_ReadPin(IN2_GPIO_Port, IN2_Pin);

}

iomod_Compare_state iomod_Compare_Input_ste(iomod_Input_t INs1,iomod_Input_t INs2)
{
	iomod_Compare_state ret = EQUALS;

	if(INs1.IN1 != INs2.IN1)
	{
		ret = NOT_EQUALS;
	}

	if(INs1.IN2 != INs2.IN2)
	{
		ret = NOT_EQUALS;
	}

	return ret;

}

void iomod_UpdateOutput(iomod_Input_t INs)
{
	if(INs.IN1 == 0 && INs.IN2 == 0)
	{
     // HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, GPIO_PIN_RESET);
	}
	else if(INs.IN1 == 0 && INs.IN2 == 1)
	{
     // HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, GPIO_PIN_RESET);
	}
	else if(INs.IN1 == 1 && INs.IN2 == 0)
	{
     // HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, GPIO_PIN_RESET);
	}
	else if(INs.IN1 == 1 && INs.IN2 == 1)
	{
     // HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED3_GPIO_Port,LED3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED4_GPIO_Port,LED4_Pin, GPIO_PIN_SET);
	}

}
