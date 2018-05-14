#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include "main_asm.h" /* interface to the assembly module */

#define LED1 PTT_PTT4
#define LED2 PTT_PTT5
#define LED3 PTT_PTT6
#define LED4 PTT_PTT7

#define MYWAIT 100

void main(void) 
{
  int i,j,k,z;
  
  /* put your own code here */
  DDRT = 0xF0; // set PTT4 to PTT7 as outputs
  PTT = 0xF0; // set PTT4 to PTT7 to 1 (LED off)
  
  for(;;) 
  {
     for(i=0; i<MYWAIT; i++);
       LED1= LED4 ^ 1;
       for(j=0; j<MYWAIT; j++);
         LED2= LED1;
         for(k=0; k<MYWAIT; k++);
           LED3=LED2;
           for(z=0; z<MYWAIT; z++);
             LED4=LED3;
   
  
  
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
    /* please make sure that you never leave main */
}
