/*
 * fsm_automatic.c
 *
 *
 */
#include "fsm_automatic.h"


void fsm_automatic_run() {
	switch(status) {
		case INIT:
			HAL_GPIO_WritePin ( LED_RED_GPIO_Port , LED_RED_Pin , GPIO_PIN_SET );
			HAL_GPIO_WritePin ( LED_YELLOW_GPIO_Port , LED_YELLOW_Pin , GPIO_PIN_SET );
			HAL_GPIO_WritePin ( LED_GREEN_GPIO_Port , LED_GREEN_Pin , GPIO_PIN_SET );
			status = AUTO_RED;
			setTimer1(5000);
			break;
		case AUTO_RED:
			//TODO
			HAL_GPIO_WritePin ( LED_RED_GPIO_Port , LED_RED_Pin , GPIO_PIN_RESET );
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
			if(timer1_flag == 1) {
				status = AUTO_GREEN;
				setTimer1(3000);
			}
			if(isButton1Pressed() == 1) {
//				button1_flag = 0;
				status = MAN_RED;
				setTimer1(10000);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
			//TODO
			if(timer1_flag == 1) {
				status = AUTO_YELLOW;
				setTimer1(2000);
			}
			break;
		case AUTO_YELLOW:
			//TODO
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
			if(timer1_flag == 1) {
				status = AUTO_RED;
				setTimer1(5000);
			}
			break;
		default:
			break;
	}
}


