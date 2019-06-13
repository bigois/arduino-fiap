#include <Arduino.h>

const int LED = 3;
const int BUTTON = 8;

void setup() {
	Serial.begin(9600);

	pinMode(LED, OUTPUT);
	pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
	if (digitalRead(BUTTON) == LOW) {
		digitalWrite(LED, HIGH);
	} else {
		digitalWrite(LED, LOW);
	}
}
