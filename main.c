#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#define SW1 PT1AD_PT1AD4
#define SW2 PT1AD_PT1AD5
#define SW3 PT1AD_PT1AD6
#define SW4 PT1AD_PT1AD7

#define LED1 PTT_PTT4
#define LED2 PTT_PTT5
#define LED3 PTT_PTT6
#define LED4 PTT_PTT7

void main(void) 
{
  /* put your own code here */
  
  DDR1AD=0x00; //setto gli sw come input
  DDRT=0xF0;  //set led come output
  PER1AD=0xF0; // abilito il pull degli switch
  //PPS1AD=0x00;   pull up si accende a 1 , commentato perchè e una merda il chip
  PTT=0xF0;  //tutti e 4 i led spenti
  
  ATDDIEN=0x00F0;
     
  


	EnableInterrupts;


  for(;;) 
 { 
    LED1=!SW1;
    LED2=!SW2;
    LED3=!SW3;
    LED4=!SW4;
    
    
    
    
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
