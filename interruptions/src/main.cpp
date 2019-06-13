#include <Arduino.h>

#define LED 3
#define BUTTON 2

volatile int state = LOW;

void setup() {
	Serial.begin(9600);

	pinMode(LED, OUTPUT);
	pinMode(BUTTON, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(BUTTON), toggle, CHANGE);
}

void loop() {
}

void toggle() {
	state = !state;
	digitalWrite(LED, state);
}
