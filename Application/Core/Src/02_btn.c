/*
 * 02_btn.c
 *
 *  Created on: Feb 1, 2022
 *      Author: LENOVO
 */

#include "main.h"


int main(){

	GPIO_InitTypeDef Led = {0};
	GPIO_InitTypeDef Btn = {0};

	HAL_Init();

	  __HAL_RCC_GPIOC_CLK_ENABLE();
	  __HAL_RCC_GPIOA_CLK_ENABLE();
	  __HAL_RCC_GPIOB_CLK_ENABLE();

	// 1. LED - PC10
	Led.Pin = GPIO_PIN_10;
	Led.Mode = GPIO_MODE_OUTPUT_PP;
	Led.Pull = GPIO_NOPULL;
	Led.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &Led);

	// 2. Btn - PB1
	Btn.Pin = GPIO_PIN_1;
	Btn.Mode = GPIO_MODE_INPUT;
	Btn.Pull = GPIO_NOPULL;
	Btn.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &Btn);

	while(1){
		if(!(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1))){
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10);
		}
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, RESET);

	}
}
