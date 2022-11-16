/*
 * button.c
 *

 */


/*
 * button.c
 *
 *  Created on: Sep 21, 2022
 *      Author: KAI
 */

#include "button.h"

int RESBtn_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;



int TimeOutForKeyPress =  300;


int isRESBtnPressed(){
	if(RESBtn_flag == 1){
		RESBtn_flag = 0;
		return 1;
	}
	return 0;
}



// action to be done after button press
void subKeyProcess(int button){
	//TODO
//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	if(button == 1){
		RESBtn_flag = 1;
	}
}


// getKetInput: detect button pressed and execute subkeyprocess

void getKeyInput(){
	  KeyReg0 = KeyReg1;
	  KeyReg1 = KeyReg2;
	  KeyReg2 = HAL_GPIO_ReadPin(RES_Btn_GPIO_Port, RES_Btn_Pin);
	  if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
	    if (KeyReg3 != KeyReg2){
	      KeyReg3 = KeyReg2;

	    if (KeyReg2 == PRESSED_STATE){
		    subKeyProcess(1);
	        TimeOutForKeyPress = 300;
	      }
	    }else{
	        TimeOutForKeyPress--;
	       if (TimeOutForKeyPress == 0){
	        if(KeyReg2 == PRESSED_STATE){
			  subKeyProcess(1);
	        }
	        TimeOutForKeyPress = 300;

	        }

	    }
	  }

}




