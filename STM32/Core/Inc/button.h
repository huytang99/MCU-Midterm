/*
 * button.h
 *

 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

//extern int button1_flag;

int isRESBtnPressed();
int isRESBtnLongPressed();
int isRESBtnDoublePressed();

int isINCBtnPressed();
int isINCBtnLongPressed();
int isINCBtnDoublePressed();

int isDECBtnPressed();
int isDECBtnLongPressed();
int isDECBtnDoublePressed();

void getKeyInput_RESBtn();
void getKeyInput_INCBtn();
void getKeyInput_DECBtn();

#endif /* INC_BUTTON_H_ */
