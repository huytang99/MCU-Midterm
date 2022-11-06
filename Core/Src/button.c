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
int INCBtn_flag = 0;
int DECBtn_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int KeyReg4 = NORMAL_STATE;
int KeyReg5 = NORMAL_STATE;
int KeyReg6 = NORMAL_STATE;
int KeyReg7 = NORMAL_STATE;

int KeyReg8 = NORMAL_STATE;
int KeyReg9 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;


int TimeOutForKeyPress =  300;


int isRESBtnPressed(){
	if(RESBtn_flag == 1){
		RESBtn_flag = 0;
		return 1;
	}
	return 0;
}

int isINCBtnPressed(){
	if(INCBtn_flag == 1){
		INCBtn_flag = 0;
		return 1;
	}
	return 0;
}

int isDECBtnPressed(){
	if(DECBtn_flag == 1){
		DECBtn_flag = 0;
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
	} else if (button == 2) {
		INCBtn_flag = 1;
	} else if (button == 3) {
		DECBtn_flag = 1;
	}
}


// getKetInput: detect button pressed and execute subkeyprocess

void getKeyInput_RESBtn(){
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

void getKeyInput_INCBtn(){
	  KeyReg4 = KeyReg5;
	  KeyReg5 = KeyReg6;
	  KeyReg6 = HAL_GPIO_ReadPin(INC_Btn_GPIO_Port, INC_Btn_Pin);
	  if ((KeyReg4 == KeyReg5) && (KeyReg5 == KeyReg6)){
	    if (KeyReg7 != KeyReg6){
	      KeyReg7 = KeyReg6;

	    if (KeyReg6 == PRESSED_STATE){
		    subKeyProcess(2);
	        TimeOutForKeyPress = 300;
	      }
	    }else{
	        TimeOutForKeyPress--;
	       if (TimeOutForKeyPress == 0){
	        if(KeyReg6 == PRESSED_STATE){
			  subKeyProcess(2);
	        }
	        TimeOutForKeyPress = 300;

	        }

	    }
	  }

}

void getKeyInput_DECBtn(){
	  KeyReg8 = KeyReg9;
	  KeyReg9 = KeyReg10;
	  KeyReg10 = HAL_GPIO_ReadPin(DEC_Btn_GPIO_Port, DEC_Btn_Pin);
	  if ((KeyReg8 == KeyReg9) && (KeyReg9 == KeyReg10)){
	    if (KeyReg11 != KeyReg10){
	      KeyReg11 = KeyReg10;

	    if (KeyReg10 == PRESSED_STATE){
		    subKeyProcess(3);
	        TimeOutForKeyPress = 300;
	      }
	    }else{
	        TimeOutForKeyPress--;
	       if (TimeOutForKeyPress == 0){
	        if(KeyReg10 == PRESSED_STATE){
			  subKeyProcess(3);
	        }
	        TimeOutForKeyPress = 300;

	        }

	    }
	  }

}


