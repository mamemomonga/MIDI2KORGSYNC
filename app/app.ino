#include "MIDIproc.h"
#include "config.h"
#include "timing.h"

void setup() {
	pinMode(SW_TA1,INPUT_PULLUP);
	pinMode(SW_TA2,INPUT_PULLUP);
	pinMode(SW_TB1,INPUT_PULLUP);
	pinMode(SW_TB2,INPUT_PULLUP);

	pinMode(LED_BEAT,OUTPUT);
	pinMode(OUT_SYNCA,OUTPUT);
	pinMode(OUT_SYNCB,OUTPUT);

	digitalWrite(LED_BEAT,HIGH);
	digitalWrite(OUT_SYNCA,HIGH);
	digitalWrite(OUT_SYNCB,HIGH);
	delay(1000);

	digitalWrite(LED_BEAT,LOW);
	digitalWrite(OUT_SYNCA,LOW);
	digitalWrite(OUT_SYNCB,LOW);
	delay(1000);
	
	MIDIproc.start();
}

void loop() {
	MIDIproc.recieve();
	Timing.handle();
}