/*
 * ADC.c
 *
 * Created: 5/19/2023 8:23:00 PM
 *  Author: Mohammad osama
 */
#include <avr/io.h>
#define F_CPU16000000UL
#include <util/delay.h>
#include <stdio.h>
#include "MACROS.h"
#include "ADC.h"
#define  ADC_VALUE  *((volatile unsigned short * ) 0x24)


void ADC_INIT()
{
    SET_BIT(ADMUX,REFS0);				//setting AVCC with external capacitor at AREF pin.
    SET_BIT(ADCSRA,ADEN);				//Enable ADC
    SET_BIT(ADCSRA,ADPS2);
}


int ADC_READ( char pin)
{
    int read = 0;

    if (pin<8)
    {
		CLR_BIT(ADCSRA,ADLAR);
        ADMUX = (ADMUX &0xE0)| pin;
        SET_BIT(ADCSRA,ADSC);				//Start conversion
        while (READ_BIT(ADCSRA,ADIF)==0);		//busy w8 to end of conversion
		_delay_us(10);
        read =ADC_VALUE ;
    }
    return read;
}

int temp_read (char ch){
	
	int temp = 0;
	int x = 0;
	x = ADC_READ(ch);
	temp = (x*500.0)/1024.0;
	return temp;
}