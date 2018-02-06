/*
 * MIDI.cpp
 *
 *  Created on: 23/01/2018
 *      Author: depre
 */


#define F_CPU 8000000UL
#define BAUD 31250


#include <util/setbaud.h>
#include <avr/io.h>
#include "MIDI.h"


MIDI::MIDI(void){
	//0b111101000010010 = 31250
	UBRR0H=UBRRH_VALUE;
	UBRR0L=UBRRL_VALUE;

	UCSR0B|=0b00001000; //set TXEN
	UCSR0C|=0b10000110; //set UCSRC select; set data size
}

void MIDI::send_data(uint8_t channel,uint8_t note,uint8_t velocity){
	//1º byte, 10010000 "1001" noteon; "0000" channel 0
	//2º byte, note value
	//3º byte, note velocity
	loop_until_bit_is_set(UCSR0A,5); //loop until UDR is ready
	UDR0|=channel; //i/o register
	loop_until_bit_is_set(UCSR0A,5);
	UDR0|=note;
	loop_until_bit_is_set(UCSR0A,5);
	UDR0|=velocity;

}
