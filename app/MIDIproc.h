#ifndef _MIDI_PROC_H_
#define _MIDI_PROC_H_

#include <Arduino.h>

#define MIDI_STATUS_INVALIDTYPE          0x00
#define MIDI_STATUS_NOTEOFF              0x80
#define MIDI_STATUS_NOTEON               0x90
#define MIDI_STATUS_AFTERTOUCHPOLY       0xA0
#define MIDI_STATUS_CONTROLCHANGE        0xB0
#define MIDI_STATUS_PROGRAMCHANGE        0xC0
#define MIDI_STATUS_AFTERTOUCHCHANNEL    0xD0
#define MIDI_STATUS_PITCHBEND            0xE0
#define MIDI_STATUS_SYSTEMEXCLUSIVE      0xF0
#define MIDI_STATUS_TIMECODEQUARTERFRAME 0xF1
#define MIDI_STATUS_SONGPOSITION         0xF2
#define MIDI_STATUS_SONGSELECT           0xF3
#define MIDI_STATUS_TUNEREQUEST          0xF6
#define MIDI_STATUS_CLOCK                0xF8
#define MIDI_STATUS_START                0xFA
#define MIDI_STATUS_CONTINUE             0xFB
#define MIDI_STATUS_STOP                 0xFC
#define MIDI_STATUS_ACTIVESENSING        0xFE
#define MIDI_STATUS_SYSTEMRESET          0xFF

class MIDIprocClass {
	public:
		MIDIprocClass();
		void start();
		void reset();
		void recieve();
	private:
		uint8_t clock_tick;
		bool press_key_state;
};

extern MIDIprocClass MIDIproc;
#endif