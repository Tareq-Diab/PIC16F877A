            


#include "TIMER1.h"



void void_init_timer(char prescaler , char I,int timer_H_reg,int timer_L_reg)
{
    switch (prescaler)
    {
        case  1:
            break;
        case 2:
            T1CON =  (1<<SBIT_PS0);
            break;
        case 4:
            T1CON = (1<<SBIT_PS1) ;
            break ;
        case 8:
            T1CON = (1<<SBIT_PS1) | (1<<SBIT_PS0);
            break;
    }
    if(I)
    {
        
    TMR1IE=1;       //Enable timer interrupt bit in PIE1 register
    GIE=1;          //Enable Global Interrupt
    PEIE=1;         //Enable the Peripheral Interrupt
    }
    
    TMR1H=timer_H_reg;     // Load the time value(0xBDC) for 100ms delay
    TMR1L=timer_L_reg;       

}