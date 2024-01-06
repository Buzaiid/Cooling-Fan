/*
 * LCD.c
 *
 * Created: 5/12/2023 8:55:10 PM
 *  Author: Mohammad osama
 */ 
#include <avr/io.h>
#define  F_CPU 16000000ul
#include <util/delay.h>
#include "LCD.h"
#include "STD_TYPES.h"
#include "MACROS.h"




void LCD_SEND_DATA(char x)
{
	DDRB = 0xFF;
	PORTA = (x & 0xF0) | (PORTA &0X0F);
	SET_BIT (PORTB,1);   //set RS to send data
	CLR_BIT(PORTB,2);    // Clear RW to write
	SET_BIT (PORTB,4);   //Set Enable
	_delay_ms(1);
	CLR_BIT (PORTB,4);    //Clear Enable
	PORTA = (x<<4) | (PORTA & 0x0F);
	_delay_ms(1);		
	SET_BIT (PORTB,4);    //Set Enable	
	_delay_ms(1);
	CLR_BIT (PORTB,4);   //Clear Enable

}

void LCD_SEND_CMD (char x)
{
	PORTA = (x & 0xF0) | (PORTA &0X0F);
	CLR_BIT (PORTB,1);   //set RS to send CMD
	CLR_BIT(PORTB,2);    // Clear RW to write
	SET_BIT (PORTB,4);   //Set Enable
	_delay_ms(1);
	CLR_BIT (PORTB,4);   //Clear Enable
	PORTA = (x<<4) | (PORTA & 0x0F);
	_delay_ms(1);
	SET_BIT (PORTB,4);   //Set Enable
	_delay_ms(1);
	CLR_BIT (PORTB,4);   //Clear Enable

}

void LCD_Init ()
{
	DDRA|= 0xF0;
	SET_BIT(DDRB,1);		//Set RS
	SET_BIT(DDRB,2);		//Set RW
	SET_BIT(DDRB,4);		//Set enable
	
	LCD_SEND_CMD(0x02);		//return home
	LCD_SEND_CMD(0x28);		//2 line 4 BIT mode
	LCD_SEND_CMD(0x0C);		//display ON
	LCD_SEND_CMD(0x06);		//auto increment
	LCD_SEND_CMD(0x01);		//clear screen 
	LCD_SEND_CMD(0b0000001111);	
	LCD_SEND_CMD(0b0000011100);	
	_delay_ms(20);
	
}

void LCD_SEND_STRING (char *str )
{	
	int i = 0;
	while(str[i]!=0)
	{
		LCD_SEND_DATA(str[i]);
		i++;
	}
}

void LCD_SEND_INT (int x)
{
	char a[10];
	int i =0;
	int len=0;
	while (x!=0)
	{
		a[i]= (char)(x%10)+'0';
		i++;
		len ++;
		x=x/10;
	}
for (i=len-1;i >=0;i--)
{
	LCD_SEND_DATA(a[i]);
}

}

void LCD_GOTO(u8 row,u8 col)
{
	u8 lcd_memory_address;
	
	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
		lcd_memory_address=col;
		break;
		case 1:
		lcd_memory_address=col+0x40;
		break;
		case 2:
		lcd_memory_address=col+0x10;
		break;
		case 3:
		lcd_memory_address=col+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_SEND_CMD(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}