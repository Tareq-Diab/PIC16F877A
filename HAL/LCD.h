/*
 * LCD.h
 *
 *  Created on: Feb 19, 2020
 *      Author: Tariq A.Diab
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include "../MCAL/DIO.h"
#include "LCD_CONFIG.h"


#define WRITE_MOST(command)   (command &0xf0)
#define WRITE_LEST(command)  ((command &0x0f)<<4)


#define _4bit	      0x28 /* Command ..0x28---> 4-bit mode - 2 line - 5x7 font */
#define cursor_off    0x0c /* Command ..0x0C---> Display no cursor - no blink */
#define incrimental   0x06 /* Command ..0x06---> Automatic Increment - No Display shift */
#define set_ddram_80h 0x80 /* Command ..0x80---> Address DDRAM with 0 offset 80h */
#define clear         0x01



void delay_ms(unsigned int ms_Count);

void void_init_lcd();
void void_lcd_send_command( char command);
void void_lcd_send_data( char data);
void void_lcd_print( char * string);
void void_lcd_clear();
void void_lcd_goto(char y ,char x);
void void_pulse();
void void_LCD_init_Command(unsigned char command);

#endif /* HAL_LCD_H_ */
