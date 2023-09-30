#include "timing.h"
#include "config.h"

TimingClass Timing;

TimingClass::TimingClass() {
}

void TimingClass::handle() {
	unsigned long m = millis();
	if(m > (m5ms+5)) {
		handle_beat();
		m5ms = m;
	}
}

void TimingClass::tick(uint8_t tick) {
	if(tick == 0) c_beat = 1;

	uint8_t syncA = 0;
	uint8_t syncB = 0;

	if((digitalRead(SW_TA1) == LOW) && (digitalRead(SW_TA2) == HIGH)) {
		// 1
		if(tick % 6 == 0) syncA = 1;
	} else if((digitalRead(SW_TA1) == HIGH) && (digitalRead(SW_TA2) == LOW)) {
		// 3
		if(tick % 24 == 0) syncA = 1;
	} else {
		// 2
		if(tick % 12 == 0) syncA = 1;
	}

	if((digitalRead(SW_TB1) == LOW) && (digitalRead(SW_TB2) == HIGH)) {
		// 1
		if(tick % 6 == 0) syncB = 1;
	} else if((digitalRead(SW_TB1) == HIGH) && (digitalRead(SW_TB2) == LOW)) {
		// 3
		if(tick % 24 == 0) syncB = 1;
	} else {
		// 2
		if(tick % 12 == 0) syncB = 1;
	}

	if(syncA) digitalWrite(OUT_SYNCA, HIGH);
	if(syncB) digitalWrite(OUT_SYNCB, HIGH);
	delayMicroseconds(500);
	digitalWrite(OUT_SYNCA, LOW);
	digitalWrite(OUT_SYNCB, LOW);
}

void TimingClass::handle_beat() {
	switch(c_beat) {
		case 0:
			return;
		case 1:
			digitalWrite(LED_BEAT, HIGH);
			break;
		case 10:
			digitalWrite(LED_BEAT, LOW);
			c_beat = 0;
			return;
	}
	c_beat++;
}

