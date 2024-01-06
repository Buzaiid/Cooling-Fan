/*
 * Cooling fan.c
 *
 * Created: 12/15/2023 4:55:25 PM
 * Author : Mohammad osama
 */ 

#define F_CPU16000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "MACROS.h"
#include "ADC.h"
#include "LCD.h"
#include "PWM.h"



int main(void)
{
    	LCD_Init();
    	ADC_INIT();
		Fast_PWM_INIT_0();
		
		
		LCD_SEND_STRING(" Temperature");
		LCD_GOTO(1,1);
		LCD_SEND_STRING("  Control!");
		_delay_ms(2000);
		
		SET_BIT(DDRC,0);		//Green LED
		SET_BIT(DDRC,1);		//Yellow LED
		SET_BIT(DDRC,2);		//Red LED
		SET_BIT(DDRC,4);		//Buzzer
		SET_BIT(DDRB,3);		//OC0 output
    	SET_BIT(DDRB,5);		//Setting H-bridge
		SET_BIT(DDRB,6);		//Setting H-bridge
		SET_BIT(PINB,5);		//Setting H-bridge
		SET_BIT(PINB,6);		//Setting H-bridge
    	float read = 0;
		float temp = 0;
    	
    	while (1)
    	{
			read = ADC_READ(0);
			temp = (read*4.88)/10.0;		
				if (temp<=25){	
					SET_BIT(PORTC,0);
					CLR_BIT(PORTC,1);
					CLR_BIT(PORTC,2);
					CLR_BIT(PORTC,3);
					CLR_BIT(PORTC,4);
					LCD_SEND_CMD(0x01);
					LCD_SEND_INT(temp);
					LCD_SEND_STRING(" Celsius");
					CLR_BIT(PINB,5);
					CLR_BIT(PINB,6);
					CLR_BIT(PIND,6);
					CLR_BIT(PIND,7);
					
				}
				
				if (temp>25 && temp<=50){	
					SET_BIT(DDRB,5);		//Setting H-bridge
					SET_BIT(DDRB,6);		//Setting H-bridge
					SET_BIT(PINB,5);		//Setting H-bridge
					SET_BIT(PINB,6);		//Setting H-bridge
					CLR_BIT(PIND,6);
					CLR_BIT(PIND,7);
					CLR_BIT(PORTC,0);
					SET_BIT(PORTC,1);
					CLR_BIT(PORTC,2);
					CLR_BIT(PORTC,3);
					CLR_BIT(PORTC,4);
					Set_PWM_DC_0(0.25);
					LCD_SEND_CMD(0x01);
					LCD_SEND_INT(temp);
					LCD_SEND_STRING(" Celsius");
					
					
				}
				if (temp>50 && temp<=75){
					SET_BIT(DDRB,5);		//Setting H-bridge
					SET_BIT(DDRB,6);		//Setting H-bridge
					SET_BIT(PINB,5);		//Setting H-bridge
					SET_BIT(PINB,6);		//Setting H-bridge
					CLR_BIT(PIND,6);
					CLR_BIT(PIND,7);
					CLR_BIT(PORTC,0);
					CLR_BIT(PORTC,1);
					SET_BIT(PORTC,2);
					CLR_BIT(PORTC,3);
					CLR_BIT(PORTC,4);
					Set_PWM_DC_0(0.5);
					LCD_SEND_CMD(0x01);
					LCD_SEND_INT(temp);
					LCD_SEND_STRING(" Celsius");
					
					
				}
				if (temp>75 && temp<=100){
					SET_BIT(DDRB,5);		//Setting H-bridge
					SET_BIT(DDRB,6);		//Setting H-bridge
					SET_BIT(PINB,5);		//Setting H-bridge
					SET_BIT(PINB,6);		//Setting H-bridge
					CLR_BIT(PIND,6);
					CLR_BIT(PIND,7);
					CLR_BIT(PORTC,0);
					CLR_BIT(PORTC,1);
					CLR_BIT(PORTC,2);
					SET_BIT(PORTC,3);
					CLR_BIT(PORTC,4);
					Set_PWM_DC_0(1);
					LCD_SEND_CMD(0x01);
					LCD_SEND_INT(temp);
					LCD_SEND_STRING(" Celsius");
					
					
				}	
				if (temp>100){
					SET_BIT(DDRB,5);		//Setting H-bridge
					SET_BIT(DDRB,6);		//Setting H-bridge
					SET_BIT(PINB,5);		//Setting H-bridge
					SET_BIT(PINB,6);		//Setting H-bridge
					SET_BIT(DDRD,6);		//Setting 2-nd H-bridge
					SET_BIT(DDRD,7);		//Setting 2-nd H-bridge
					SET_BIT(PIND,6);		//Setting 2-nd H-bridge
					SET_BIT(PIND,7);		//Setting 2-nd H-bridge
					CLR_BIT(PORTC,0);
					CLR_BIT(PORTC,1);
					CLR_BIT(PORTC,2);
					SET_BIT(PORTC,3);
					SET_BIT(PORTC,4);
					Set_PWM_DC_0(1);
					LCD_SEND_CMD(0x01);
					LCD_SEND_INT(temp);
					LCD_SEND_STRING(" Celsius");
					LCD_GOTO(1,2);
					LCD_SEND_STRING(" WARNING!");
					
					
				}	
				_delay_ms(500);												 
    	}
			
}

