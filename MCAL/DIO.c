

#include "DIO.h"


void void_init_pin(char portname,char pinnumber , char dir)
{       
        switch (portname)
        {
        case 'A':
        case 'a':
                if (!dir)
                        SET_BIT(TRISA,pinnumber);
                else
                        CLEAR_BIT(TRISA,pinnumber);
                break ;
        case 'B':
        case 'b':
                if (!dir)
                        SET_BIT(TRISB,pinnumber);
                else
                        CLEAR_BIT(TRISB,pinnumber);
                break ;
        case 'C':
        case 'c':
                if (!dir)
                        SET_BIT(TRISC,pinnumber);
                else
                        CLEAR_BIT(TRISC,pinnumber);
                break ;
        case 'D':
        case 'd':
                if (!dir)
                        SET_BIT(TRISD,pinnumber);
                else
                        CLEAR_BIT(TRISD,pinnumber);
                break ;
        case 'E':
        case 'e':
                if (!dir)
                        SET_BIT(TRISE,pinnumber);
                else
                        CLEAR_BIT(TRISE,pinnumber);
                break ;


        }

}
void void_write_pin(char portname,char pinnumber , char state)
{


        switch (portname)
        {
        case 'A':
        case 'a':
                if (state)
                        SET_BIT(PORTA,pinnumber);
                else
                        CLEAR_BIT(PORTA,pinnumber);
                break ;
        case 'B':
        case 'b':
                if (state)
                        SET_BIT(PORTB,pinnumber);
                else
                        CLEAR_BIT(PORTB,pinnumber);
                break ;
        case 'C':
        case 'c':
                if (state)
                        SET_BIT(PORTC,pinnumber);
                else
                        CLEAR_BIT(PORTC,pinnumber);
                break ;
        case 'D':
        case 'd':
                if (state)
                        SET_BIT(PORTD,pinnumber);
                else
                        CLEAR_BIT(PORTD,pinnumber);
                break ;
        case 'E':
        case 'e':
                if (state)
                        SET_BIT(PORTE,pinnumber);
                else
                        CLEAR_BIT(PORTE,pinnumber);
                break ;


        }

}
void void_init_port(char portname,char pins_dir)
{

        switch (portname)
        {
        case 'A':
        case 'a':
                TRISA=pins_dir;
                break;

        case 'B':
        case 'b':
                TRISB=pins_dir;
                break ;
        case 'C':
        case 'c':
                TRISC =pins_dir;
                break ;
        case 'D':
        case 'd':
                TRISD=pins_dir;
                break;
        }

}
void void_write_port(char portname,char pins_dir)
{

        switch (portname)
        {
        case 'A':
        case 'a':
                PORTA=pins_dir;
                break;

        case 'B':
        case 'b':
                PORTB=pins_dir;
                break ;
        case 'C':
        case 'c':
                PORTC =pins_dir;
                break ;
        case 'D':
        case 'd':
                PORTD=pins_dir;
                break;
        }

}
char char_read_pin(char portname,char pinnumber)
{
        switch(portname)
        {
        case 'A':
        case 'a':
                return READ_BIT(PORTA,pinnumber);
        case 'B':
        case 'b':
                return READ_BIT(PORTB,pinnumber);
        case 'C':
        case 'c':
                return READ_BIT(PORTC,pinnumber);
        case 'D':
        case 'd':
                return READ_BIT(PORTD,pinnumber);



        }
        return 'N';

}