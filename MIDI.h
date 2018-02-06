/*
 * MIDI.h
 *
 *  Created on: 23/01/2018
 *      Author: depre
 */



#ifndef MIDI_H_
#define MIDI_H_

class MIDI{
	public: 
		MIDI();
		void send_data(uint8_t in0,uint8_t in1,uint8_t in2);
};

#endif /* MIDI_H_ */
