#ifndef _TIMING_H_
#define _TIMING_H_

#include <Arduino.h>

class TimingClass {
	public:
		TimingClass();
		void handle();
		void tick(uint8_t);
	private:
		void handle_beat();
		unsigned long m5ms;
		uint8_t c_beat;
		uint8_t c_sync;
};

extern TimingClass Timing;
#endif
