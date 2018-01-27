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


