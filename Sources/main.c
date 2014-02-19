#include <hidef.h>      /* common defines and macros */
#include "derivative.h"
#include <mc9s12c128.h>
#include <stdio.h>
#include <termio.h>
#include <terminal.h>
#include "stdlib.h"

char input[20];
  
unsigned int half_period;
unsigned int frequency;
unsigned int duration;
unsigned int count;
unsigned int duration1;
unsigned int frequency1;
unsigned int durFreq;
unsigned int countTemp;
unsigned int lowpin=0;

void interrupt 7 keyP( ) {
  CRGFLG = 0x80;
  switch (lowpin) {
    case 0:
      PORTB = 0xE;
      break;
    case 1:
      PORTB = 0xD;
      break;
    case 2:
      PORTB = 0xB;
      break;
    default:
      PORTB = 0x7;
      break;
  }
  lowpin++;
  lowpin = lowpin % 4;
}

void interrupt 10 pt3INT( ){
    TFLG1 |= 0x04; 
    /*TC2 += half_period;
    count--;
    //printf("%d  ", count);
    if (count <= 0){
	      TCTL2 = 0x00;
	      //printf("COUNT=ZERO\n");
	      
	  }  */
}


void main(void) {



  TERMIO_Init(); 
  
  printf("REACHED First\n");
  
  /*
  TERM_ReadString(input, 20);
  
  
  
  sscanf(input,"%d %d",&frequency, &duration);
  printf("Frequency %d, Duration %d\n", frequency, duration);
  half_period = 1000000/frequency;
   */
   
   printf("REACHED\n");
  
  EnableInterrupts;
  
  DDRB = 0x0F;
  PORTB = 0x0F;
  TFLG1 = 0x04;
  TSCR1 = 0x80;
  TIOS=0x04;
  TC2+= half_period;
  PTT=0x04;
  TCTL2 = 0x10;
  TIE=0x04;
  CRGINT |= 0x80;
  RTICTL = 0x40;
  
  
  

    
  while(1) {
  
    // printf("REACHED1\n");
     
    if(PORTB == 0xEE) {
      putchar('1');
    }
    if(PORTB == 0xDE) {
      putchar('2');
    }
    if(PORTB == 0xBE) {
      putchar('3');
    }
    if(PORTB == 0x7E) {
      putchar('A');
    }
    if(PORTB == 0xED) {
      putchar('4');
    }
    if(PORTB == 0xDD) {
      putchar('5');
    }
    if(PORTB == 0xBD) {
      putchar('6');
    }
    if(PORTB == 0x7D) {
      putchar('B');
    }
    if(PORTB == 0xEB) {
      putchar('7');
    }
    if(PORTB == 0xDB) {
      putchar('8');
    }
    if(PORTB == 0xBB) {
      putchar('9');
    }
    if(PORTB == 0x7B) {
      putchar('C');
    }
    if(PORTB == 0xE7) {
      putchar('*');
    }
    if(PORTB == 0xD7) {
      putchar('0');
    }
    if(PORTB == 0xB7) {
      putchar('#');
    }
    if(PORTB == 0x77) {
      putchar('D');
    }
    
      
   
     /* TERM_ReadString(input, 20);
    
      sscanf(input,"%d %d",&frequency, &duration);
      printf("Frequency %d, Duration %d\n", frequency, duration);
      half_period = 1000000/frequency;
      
      
      duration1 = (duration/100);
      frequency1 = frequency/10;
      durFreq = (duration1 * frequency1);
      countTemp = (durFreq*2);
      count = countTemp;
      TCTL2 = 0x10;  */
      
      
  
  //printf("REACHED\n");   
  }
      

}

