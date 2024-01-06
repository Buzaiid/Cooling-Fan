/*
 * PWM.c
 *
 * Created: 5/27/2023 7:25:55 PM
 *  Author: Mohammad osama
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#include "PWM.h"
#include "STD_TYPES.h"
#include "MACROS.h"
		/***************************************timer 0*******************************************/
void Fast_PWM_INIT_0()
{
	SET_BIT(TCCR0,WGM01);						//Setting Fast PWM Mode
	SET_BIT(TCCR0,WGM00);						//Setting Fast PWM Mode
	SET_BIT(TCCR0,COM01);						//Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
	SET_BIT(TCCR0,CS00);						//Choosing no Prescaling option 
	SET_BIT(DDRB,3);							//Setting OC0 Pin as an O/P

}
		/***************************************timer 2*******************************************/
void Fast_PWM_INIT_2()
{
	SET_BIT(TCCR0,WGM21);						//Setting Fast PWM Mode
	SET_BIT(TCCR0,WGM20);						//Setting Fast PWM Mode
	SET_BIT(TCCR0,COM21);						//Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
	SET_BIT(TCCR0,CS20);						//Choosing no Prescaler option
	SET_BIT(DDRB,7);							//Setting OC0 Pin as an O/P

}

void PhaseCorrect_PWM_INIT()
{
	CLR_BIT(TCCR0,WGM01);						//Setting Phase correct PWM Mode
	SET_BIT(TCCR0,WGM00);						//Setting Phase correct PWM Mode
	SET_BIT(TCCR0,COM01);						//Clear OC0 on compare match when up-counting. Set OC0 on compare match when down counting.
	SET_BIT(TCCR0,CS00);						//Choosing no Prescaling option
	SET_BIT(DDRB,3);							//Setting OC0 Pin as an O/P

}


void Set_PWM_DC_0(float DC)
{
	u8 num = 0;
	num = 256.0*DC-1;
	if (num==-1)
	{
		OCR0=0;
	}
	else 
	{
		OCR0=num;
	}
}

void Set_PWM_DC_2(float DC)
{
	u8 num = 0;
	num = 256.0*DC-1;
	if (num==-1)
	{
		OCR2=0;
	}
	else
	{
		OCR0=num;
	}
}
