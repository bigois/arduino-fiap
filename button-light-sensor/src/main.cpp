#include <Arduino.h>
#include <ArduinoJson.h>

const int SENSOR = A1;
const int BUTTON = 8;

void setup() {
	Serial.begin(9600);
	pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
	if (digitalRead(BUTTON) == LOW) {
		StaticJsonBuffer<200> jsonBuffer;
		JsonObject& json = jsonBuffer.createObject();
		String text;

		json["luminosity"] = analogRead(SENSOR);

		json.printTo(text);
		Serial.println(text);
	}

	delay(200);
}
