/*
 * displayLED.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HuyKiet
 */

#ifndef INC_DISPLAYLED_H_
#define INC_DISPLAYLED_H_



void LEDPinAssign(int LedBuffer[7]){
		  HAL_GPIO_WritePin ( A_GPIO_Port, A_Pin , LedBuffer[0]);
		  HAL_GPIO_WritePin ( B_GPIO_Port, B_Pin , LedBuffer[1]);
		  HAL_GPIO_WritePin ( C_GPIO_Port, C_Pin , LedBuffer[2]);
		  HAL_GPIO_WritePin ( D_GPIO_Port, D_Pin , LedBuffer[3]);
		  HAL_GPIO_WritePin ( E_GPIO_Port, E_Pin , LedBuffer[4]);
		  HAL_GPIO_WritePin ( F_GPIO_Port, F_Pin , LedBuffer[5]);
		  HAL_GPIO_WritePin ( G_GPIO_Port, G_Pin , LedBuffer[6]);
}

void display7SEG(int number){
	switch(number){
		case 0: {
					int LedBuffer[7] = { 0, 0, 0, 0, 0, 0, 1};
					LEDPinAssign(LedBuffer);
				}
		break;

		case 1: {
					int LedBuffer[7] = { 1, 0, 0, 1, 1, 1, 1};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 2: {
					int LedBuffer[7] = { 0, 0, 1, 0, 0, 1, 0};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 3: {
					int LedBuffer[7] = { 0, 0, 0, 0, 1, 1, 0};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 4: {
					int LedBuffer[7] = { 1, 0, 0, 1, 1, 0, 0};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 5: {
					int LedBuffer[7] = { 0, 1, 0, 0, 1, 0, 0};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 6: {
					int LedBuffer[7] = { 0, 1, 0, 0, 0, 0, 0};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 7: {
					int LedBuffer[7] = { 0, 0, 0, 1, 1, 1, 1};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 8: {
					int LedBuffer[7] = { 0, 0, 0, 0, 0, 0, 0};
					LEDPinAssign(LedBuffer);
				}
				break;
		case 9: {
					int LedBuffer[7] = { 0, 0, 0, 0, 1, 0, 0};
					LEDPinAssign(LedBuffer);
				}
				break;
		default: {
					int LedBuffer[7] = { 0, 0, 0, 0, 0, 0, 1};
					LEDPinAssign(LedBuffer);
				}
				break;
	}
}




#endif /* INC_DISPLAYLED_H_ */
