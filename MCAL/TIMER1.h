/* 
 * File:   TIMER1.h
 * Author: Tariq A.Diab
 *
 * Created on March 5, 2020, 8:22 AM
 */

#ifndef TIMER1_H
#define	TIMER1_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <pic16f877a.h>
    
#define SBIT_PS1  5
#define SBIT_PS0  4

void void_init_timer(char prescaler , char I,int timer_H_reg,int timer_L_reg);



#ifdef	__cplusplus
}
#endif

#endif	/* TIMER1_H */

