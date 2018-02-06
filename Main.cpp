#include <avr/io.h>
#include "MIDI.h"


#define OCTAVE 0
#define CC OCTAVE*12
#define DD CC+2
#define EE DD+2
#define FF EE+1
#define GG FF+2
#define AA GG+2
#define BB AA+2
#define CC1 BB+1

#define VELOCITY 0b01000000

#define CHANNEL 0b10010000

int main(void){
  DDRB&=0b00000000; //making sure all pins are input
  PORTB|=0b11111111; //Pullup inputs

  MIDI midi;

  while(1){
    if(!PINB){
      if(PINB&=0b00000001){
        midi.send_data(CHANNEL,CC,VELOCITY);
      }else if(PINB&=0b00000010){
        midi.send_data(CHANNEL,DD,VELOCITY);
      }else if(PINB&=0b00000100){
        midi.send_data(CHANNEL,EE,VELOCITY);
      }else if(PINB&=0b00001000){
        midi.send_data(CHANNEL,FF,VELOCITY);
      }else if(PINB&=0b00010000){
        midi.send_data(CHANNEL,GG,VELOCITY);
      }else if(PINB&=0b00100000){
        midi.send_data(CHANNEL,AA,VELOCITY);
      }else if(PINB&=0b01000000){
        midi.send_data(CHANNEL,BB,VELOCITY);
      }else if(PINB&=0b10000000){
        midi.send_data(CHANNEL,CC1,VELOCITY);
      }
    }
  }

  return 0;
}

void capacitive_touch(){ //test capacitive touch
  DDRC&=0b00000000; //making sure pins are inputs
  DDRC|=0b00000001; //set LSB output
  PORTC|=0b00000001; //set output high
  
  //maybe set all pins to input, and using 5v port to feed the capacitive sensing circuit
  
  if(PINC==0b00000001){ //one of the inputs turned from 1 to 0
    //do something
    /*
    *  midi.send_data(CHANNEL,C,VELOCITY);
    *
    */
  }
  
  
}
