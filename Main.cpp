#include <avr/io.h>
#include "MIDI.h"


#define OCTAVE 0
#define C OCTAVE*12
#define D C+2
#define E D+2
#define F E+1
#define G F+2
#define A G+2
#define B A+2
#define C1 B+1

#define VELOCITY 0b01000000

#define CHANNEL 0b10010000

void main(void){
	DDRB&=0b00000000; //making sure all pins are input
	PORTB|=0b11111111; //Pullup inputs

	MIDI midi;

	while(1){
		if(!PINB){
			if(PINB&=0b00000001){
				midi.send_data(CHANNEL,C,VELOCITY);
			}else if(PINB&=0b00000010){
				midi.send_data(CHANNEL,D,VELOCITY);
			}else if(PINB&=0b00000100){
				midi.send_data(CHANNEL,E,VELOCITY);
			}else if(PINB&=0b00001000){
				midi.send_data(CHANNEL,F,VELOCITY);
			}else if(PINB&=0b00010000){
				midi.send_data(CHANNEL,G,VELOCITY);
			}else if(PINB&=0b00100000){
				midi.send_data(CHANNEL,A,VELOCITY);
			}else if(PINB&=0b01000000){
				midi.send_data(CHANNEL,B,VELOCITY);
			}else if(PINB&=0b10000000){
				midi.send_data(CHANNEL,C1,VELOCITY);
			}
		}
	}
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
