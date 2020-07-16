/*
 * Keypad.c
 *
 *  Created on: Feb 18, 2020
 *      Author: Tariq A.Diab
 */

#include "keypad.h"
#ifndef r4
char n =3;
char rows[3]={r1,r2,r3};
char columns[3]= {c1,c2,c3};
#endif


#ifdef r4
char n =4;
char rows[4]={r4,r3,r2,r1};
char columns[3]= {c1,c2,c3};
#endif


void void_init_keypad()
{

	//for 3X3 keypad
#ifndef r4
	// intializing rows
void_init_pin(r_port,r1,1);
void_init_pin(r_port,r2,1);
void_init_pin(r_port,r3,1);
	// intializing rows
void_init_pin(c_port,c1,0);
void_init_pin(c_port,c2,0);
void_init_pin(c_port,c3,0);
#endif




	//for 4X4 keypad
#ifdef r4
	// intializing rows
void_init_pin(r_port,r1,0);
void_init_pin(r_port,r2,0);
void_init_pin(r_port,r3,0);
void_init_pin(r_port,r4,0);
	// intializing columns
void_init_pin(c_port,c1,1);
void_init_pin(c_port,c2,1);
void_init_pin(c_port,c3,1);
//void_init_pin(c_port,c4,0);

#endif

//turning all pins off
for (int x=0 ; x<n;x++)
{
	void_write_pin(c_port,columns[x],1);
}
/*
//intializing the pullup resisrors
for (int x=0 ; x<3;x++)
{
	void_write_pin(c_port,columns[x],1);
}
*/
}







key key_read_keypad()
{
key k;
int r,c;

for ( c=0 ; c<(n-1);c++)
{
	void_write_pin(c_port,columns[c],0);
    //delay_msk(100);
	for ( r=0 ;r<n;r++)
		{
        
		if (!char_read_pin(r_port,rows[r]))
		{
            
            delay_msk(50);
			
            
			k.x=r;
			k.y=c;
			return k;
		}




		}
    void_write_pin(c_port,columns[c],1);

    //delay_msk(100);
    

}
k.x=5;
k.y=5;
return k;



}



void delay_msk(unsigned int ms_Count)
{
    unsigned int i,j;
    for(i=0;i<ms_Count;i++)
    {
        for(j=0;j<1000;j++);
    }
}























