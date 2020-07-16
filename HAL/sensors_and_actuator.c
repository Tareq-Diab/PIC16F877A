#include "sensors_and_actuarors.h"

void void_init_sensors()
{
    void_init_pin('b',3,0); // intializing RB3 as the start button
    void_init_pin('b',4,0); // intializing RB4 as the pause/clear button
    void_init_pin('b',5,0); // intializing RB5 as the door sensor


}
void void_init_actuators()
{

   void_init_pin('c',2,1); // intializing c2 as the fan
   void_init_pin('c',5,1); // intializing c5 as the heater
   void_init_pin('c',0,1); // intializing c0 as the as lamp
   void_init_pin('b',7,1); // intializing b7 as the as lamp
}

void void_start_heating()
{

   void_write_pin('c',2,1); // intializing c2 as the fan
   void_write_pin('c',5,1); // intializing c5 as the heater
   void_write_pin('c',0,1); // intializing c0 as the as lamp
   void_write_pin('b',7,1); // intializing b7 as the as lamp


}


void void_stop_heating()
{

   void_write_pin('c',2,0); // intializing c2 as the fan
   void_write_pin('c',5,0); // intializing c5 as the heater
   void_write_pin('c',0,0); // intializing c0 as the as lamp
   void_write_pin('b',7,0); // intializing b7 as the as lamp


}

void void_door()
{
    if (!char_read_pin('b',5))
    {
        door_flag = !door_flag;
        
    }

}

void void_start()
{
    if (!char_read_pin('b',3))
    {
        start_flag = 1;
        pause_flag = 0;
        
    }

}
void void_pause()
{
    if (!char_read_pin('b',4) && (pause_flag==0))
    {
        pause_flag = 1;
        return ; 
    }
        if (!char_read_pin('b',4) && (pause_flag==1))
    {
        pause_flag = 0;
        start_flag = 0;
        reset_flag=1;
        
    }

}