/*
 * LCD.h
 *
 * Created: 5/12/2023 8:54:55 PM
 *  Author: Mohammad osama
 */ 
#include "STD_TYPES.h"

#ifndef LCD_H_
#define LCD_H_

#define LCD_SET_CURSOR_LOCATION              0x80

void LCD_SEND_DATA(char x);
void LCD_SEND_CMD (char x);
void LCD_Init ();
void LCD_SEND_STRING (char *str);
void LCD_SEND_INT (int x);
void LCD_GOTO(u8 row,u8 col);

#endif /* LCD_H_ */