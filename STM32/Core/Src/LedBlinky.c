/*
 * LedBlinky.c
 *
 *  Created on: Nov 6, 2022
 *      Author: HuyKiet
 */
#include "LedBlinky.h"


void LedBlinky(){
	if(timer3_flag == 1){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer3(1000);
	}
}

