/* 
 * File:   inputs_outputs.h
 * Author: Tariq A.Diab
 *
 * Created on March 5, 2020, 12:54 AM
 */

#ifndef INPUTS_OUTPUTS_H
#define	INPUTS_OUTPUTS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../MCAL/DIO.h"

char door_flag=0;
char start_flag=0;
char pause_flag=0;
char reset_flag=0;    
    
void void_init_sensors();
void void_init_actuators();
void void_start_heating();
void void_stop_heating();
void void_door();
void void_start();
void void_pause();
    
    
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* INPUTS_OUTPUTS_H */

