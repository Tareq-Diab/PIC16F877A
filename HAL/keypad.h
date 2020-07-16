/*
 * keypad.h
 *
 *  Created on: Feb 18, 2020
 *      Author: Tariq A.Diab
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "../MCAL/DIO.h"

typedef struct  {
	char x ;
	char y ;
}key;
char keypad_map[4][3]={{{1},{2},{3}},{{4},{5},{6}},{{7},{8},{9}},{{'a'},{0},{'h'}}};
// rows of keypad
#define r_port 'd'			//the port of the rows
#define r1 0
#define r2 1
#define r3 2
#define r4 3               // define for the 4th row of a 4x4 keypad

// columns of keypad
#define c_port 'b'			//the port of the columns
#define c1 0
#define c2 1
#define c3 2
//#define c4 0			// define for the 4th column of a 4x4 keypad

void void_init_keypad();

key key_read_keypad();


void delay_msk(unsigned int ms_Count);



#endif /* KEYPAD_H_ */
