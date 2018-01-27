/*
 * MIDI.cpp
 *
 *  Created on: 23/01/2018
 *      Author: deeper
 */


#define F_CPU 8000000UL
#define BAUD 31250UL


#include <util/setbaud.h>
#include <avr/io.h>
#include "MIDI.h"


MIDI::MIDI(){
	//0b111101000010010 = 31250
	UBRRH=UBRRH_VALUE;
	UBRRL=UBRRL_VALUE;

	UCSRB|=0b00001000; //set TXEN
	UCSRC|=0b10000110; //set UCSRC select; set data size
}

void MIDI::send_data(uint8_t channel,uint8_t note,uint8_t velocity){
	//1º byte, 10010000 "1001" noteon; "0000" channel 0
	//2º byte, note value
	//3º byte, note velocity
	loop_until_bit_is_set(UCSRA,5); //loop until UDR is ready
	UDR|=channel; //i/o register
	loop_until_bit_is_set(UCSRA,5);
	UDR|=note;
	loop_until_bit_is_set(UCSRA,5);
	UDR|=velocity;

}

