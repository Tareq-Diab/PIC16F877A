/*
 * File:   main.c
 * Author: Tariq A.Diab
 *
 * Created on March 3, 2020, 5:40 PM
 */


#define _XTAL_FREQ 8000000
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



#include <xc.h>
#include <pic16f877a.h>
#include <stdio.h>
#include <stdlib.h>
#include "MCAL/DIO.h"
#include "HAL/LCD.h"
#include "HAL/keypad.h"
#include "HAL/sensors_and_actuarors.h"
#include "MCAL/TIMER1.h"

char  text_debug[5];
#define debug

char count=0;
char sec=0;

int mins;
int secs;

int time_s;
char Done_flag=0;

char text[50]="Microwave";
char text_t[10]="00:00";
key k ;
char time[4]={0,0,0,0};


void void_time_input(char * arr,char input);
void void_operation();
void void_microwave_timer();
void void_update_status();


void __interrupt () timer_isr(void){  

    if(TMR1IF==1)
    {
        count++;

        TMR1H=0x3C;     // 0x3CB0 for 200ms delay
        TMR1L=0xB0; 
        TMR1IF=0;       // Clear timer interrupt flag
    } 
}




int main() 
{   
  /* Configure all the ports as Output */

 
    void_init_lcd();
    void_init_keypad();
    void_init_timer(8,1,0x3C,0xB0);
    
    void_init_sensors();
    void_init_actuators();
    void_update_status();
    
    
    while(1)
    {
        void_door();
        __delay_ms(50);
        void_start();
        __delay_ms(50);
        void_pause();
        __delay_ms(50);
        void_operation();

        

        
        k=key_read_keypad();
        if (k.x !=5)
        {
            void_time_input(time,keypad_map[k.x][k.y]);
            sprintf(text_t,"%d%d:%d%d",time[0],time[1],time[2],time[3]); 
            void_update_status();
        }
        
        
        
        #ifdef debug
        sprintf(text_debug,"%d%d%d",start_flag,pause_flag,door_flag);
        void_lcd_goto(2,1);
        void_lcd_print(text_debug);
        #endif
        
       
}
    return (0);
}




void void_time_input(char * arr,char input)
{
    if (arr[0]==0)
    {
        arr[0]=arr[1];
        arr[1]=arr[2];
        arr[2]=arr[3];
        arr[3]=input;
            
    
    }
    mins = arr[0]*10+arr[1]  ;
    secs = arr[2]*10+arr[3]  ;
    time_s =mins*60+secs  ; 
}
void void_microwave_timer()
{   if (time_s==0)
    {   
        reset_flag=1;
        Done_flag=1;
    }
    
    if (count>=5)
    {
        time_s--;
        count=0;
        void_update_status();
    }
    
    mins=time_s/60;
    secs=time_s%60;
    sprintf(text_t,"%d:%d",mins,secs);
}

void void_update_status()
{
        //sprintf(text,"s,p,r %d %d %d ",start_flag,pause_flag,reset_flag);
        void_lcd_clear();
        void_lcd_goto(2,7);
        void_lcd_print(text_t);
        void_lcd_goto(1,5);
        void_lcd_print(text);

        __delay_ms(100);
    
}

void void_operation()
{       if (!door_flag && start_flag)
        {    
            sprintf(text,"door is open!");
            void_lcd_goto(1,3);
            void_lcd_print(text);
        }
        else
        {
        
        sprintf(text,"Microwave");

        }



        if (start_flag&&door_flag && !pause_flag)
        {
            void_start_heating();
            void_microwave_timer();
            TMR1ON = 1;     //Start Timer1 
            

        }
        if (pause_flag || (!door_flag && start_flag))
        {

            void_stop_heating();
            TMR1ON = 0;     //Start Timer1 
            

        }
        if (reset_flag)
        {
            for (char i =0; i<4;i++)
            {
                time[i]=0;
            }
            sprintf(text_t,"%d%d:%d%d",time[0],time[1],time[2],time[3]);
            time_s=0;
            start_flag=0;
            void_stop_heating();
            TMR1ON = 0; 
            reset_flag=0;
            void_update_status();
            
        }
        if (Done_flag)
        {   
            for (char i =0; i<3;i++)
            {
            sprintf(text,"Done");
            void_update_status();
            __delay_ms(500);
            sprintf(text,"    ");
            void_update_status();
            __delay_ms(500);
            }
            sprintf(text,"Microwave");
            void_update_status();
            Done_flag=0;
        }
        

}