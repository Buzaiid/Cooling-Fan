/*
 * PWM.h
 *
 * Created: 5/27/2023 7:26:14 PM
 *  Author: Mohammad osama
 */ 

#include <avr/io.h>
#include "MACROS.h"
#include "STD_TYPES.h"

#ifndef PWM_H_
#define PWM_H_

/*
void Fast_PWM_INIT();
void PhaseCorrect_PWM_INIT();
void Set_PWM_DC(float DC);
*/

void Fast_PWM_INIT_0();
void Fast_PWM_INIT_2();
void PhaseCorrect_PWM_INIT();
void Set_PWM_DC_0(float DC);
void Set_PWM_DC_2(float DC);





#endif /* PWM_H_ */