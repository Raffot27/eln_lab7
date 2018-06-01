#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#define LED1 PTT_PTT4
#define LED2 PTT_PTT5
#define LED3 PTT_PTT6
#define LED4 PTT_PTT7

#define MYWAIT 2

void main(void) 
{
  int i,j,tmp;
  
  /* put your own code here */
  DDRT = 0xF0; // set PTT4 to PTT7 as outputs
  PTT = 0xE0; // set PTT4 to PTT7 to 1 (LED off)
  
  
  
 
	//EnableInterrupts;


  for(;;)
  {
     for (i=0; i<MYWAIT; i++)
        for (j=0; j<MYWAIT; j++); //wait 1 sec
            tmp=LED4;
            LED4=LED3;
            LED3=LED2;
            LED2=LED1;
            LED1=tmp;
  
  
  
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}
