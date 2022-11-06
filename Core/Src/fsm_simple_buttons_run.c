/*
 * fsm_simple_buttons_run.c
 *
 *  Created on: Nov 5, 2022
 *
 */

#include "fsm_simple_buttons_run.h"
#include "global.h"

void fsm_simple_buttons_run() {
	switch(status) {
		case INIT:
			counter7SEG = 0;
			display7SEG(counter7SEG);
			status = SIM_RES;
			break;
		case SIM_RES:
			//TODO
			display7SEG(counter7SEG);
			if(isRESBtnPressed() == 1){
				counter7SEG = 0;
				setTimer1(10000);
				status = SIM_RES;
			}
			if(isINCBtnPressed() == 1) {
	//			RESBtn_flag = 0;
				counter7SEG += 1;
				if(counter7SEG > 9){
					counter7SEG = 0;
				}
				setTimer1(10000);
				status = SIM_INC;
			}
			if(isDECBtnPressed() == 1) {
				//RESBtn_flag = 0;
				counter7SEG -= 1;
				if(counter7SEG < 0){
					counter7SEG = 9;
				}
				setTimer1(10000);
				status = SIM_DEC;
			}
			break;
		case SIM_INC:
			display7SEG(counter7SEG);
			if(isRESBtnPressed() == 1){
				counter7SEG = 0;
				setTimer1(10000);
				status = SIM_RES;
			}
			else if(isINCBtnPressed() == 1){
				counter7SEG += 1;
				if(counter7SEG > 9){
					counter7SEG = 0;
				}
				setTimer1(10000);
				status = SIM_INC;
			}
			else if(isDECBtnPressed() == 1){
			    counter7SEG -= 1;
				if(counter7SEG < 0){
					counter7SEG = 9;
				}
				setTimer1(10000);
				status = SIM_DEC;
			}
			else{
				if(timer1_flag==1){
					setTimer2(10);
					status = NO_EVENT;
				}
			}
			break;
		case SIM_DEC:
			display7SEG(counter7SEG);
			if(isRESBtnPressed() == 1){
				counter7SEG = 0;
				setTimer1(10000);
				status = SIM_RES;
			}
			else if(isINCBtnPressed() == 1){
				counter7SEG += 1;
				if(counter7SEG > 9){
					counter7SEG = 0;
				}
				setTimer1(10000);
				status = SIM_INC;
			}
			else if(isDECBtnPressed() == 1){
				counter7SEG -= 1;
				if(counter7SEG < 0){
					counter7SEG = 9;
				}
				setTimer1(10000);
				status = SIM_DEC;
			}
			else{
				if(timer1_flag==1){
					setTimer2(10);
					status = NO_EVENT;
				}
			}
			break;
		case NO_EVENT:
			if(timer2_flag == 1){
				if(counter7SEG >= 0){
					counter7SEG--;
					display7SEG(counter7SEG);
					setTimer2(1000);
				}
			}
			if(isINCBtnPressed() == 1){
				counter7SEG += 1;
				if(counter7SEG > 9){
					counter7SEG = 0;
				}
				setTimer1(10000);
				status = SIM_INC;
			}
			if(isDECBtnPressed() == 1){
				counter7SEG -= 1;
				if(counter7SEG < 0){
					counter7SEG = 9;
				}
				setTimer1(10000);
				status = SIM_DEC;
			}
			break;
		default:
			break;
		}
}
