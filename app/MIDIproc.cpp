#include "MIDIproc.h"
#include "config.h"
#include "timing.h"
#include <MIDI.h>

#define MIDIPROC_MSBHOLD_ENVELOPE_FREQ 0

// https://fortyseveneffects.github.io/arduino_midi_library/
MIDIprocClass MIDIproc;
MIDI_CREATE_DEFAULT_INSTANCE();

MIDIprocClass::MIDIprocClass() {
}

void MIDIprocClass::start() {
	MIDI.begin(MIDI_CHANNEL_OMNI);
	MIDI.turnThruOff();
	reset();
}

void MIDIprocClass::reset() {
	clock_tick = 0;
	press_key_state = false;
}

void MIDIprocClass::recieve() {
	if(!MIDI.read()) return;
	byte channel = MIDI.getChannel();
	byte type    = MIDI.getType();
	byte data1   = MIDI.getData1();
	byte data2   = MIDI.getData2();

	switch( type ) {
		case MIDI_STATUS_SYSTEMRESET:
		 	reset();
			clock_tick = 0;
			return;

		case MIDI_STATUS_START:
			clock_tick = 0;
			return;
		
		case MIDI_STATUS_STOP:
			clock_tick = 0;
			return;
	
		case MIDI_STATUS_SONGPOSITION:
			clock_tick = 0;
			return;
		
		case MIDI_STATUS_CLOCK:
			Timing.tick(clock_tick);
			clock_tick++;
			if (clock_tick == 24) clock_tick = 0;
			return;
		default:
			return;
	}
}
