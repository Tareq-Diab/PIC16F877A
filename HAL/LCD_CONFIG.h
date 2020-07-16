/*
 * LCD_CONFIG.h
 *
 *  Created on: Feb 19, 2020
 *      Author: Tariq A.Diab
 */

#ifndef HAL_LCD_CONFIG_H_
#define HAL_LCD_CONFIG_H_
/*
 * This LCD Driver uses the lcd in 4bit mode
 * And dosen't utilize the rw bit instead of checking if the lcd done
 * working on the previous data , this drivers wait sufficient time after each command.
 *
 * */

#define MCU_d_PORT 'd'
#define d4 4
#define d5 5
#define d6 6
#define d7 7

#define MCU_rs_PORT 'e'
#define rs 2
#define MCU_e_PORT 'e'
#define e  1


#define rw


#endif /* HAL_LCD_CONFIG_H_ */
