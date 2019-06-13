#include <Arduino.h>
#include <ArduinoJson.h>

const int SENSOR = A1;

void setup() {
	Serial.begin(9600);
}

void loop() {
	StaticJsonBuffer<200> jsonBuffer;
	JsonObject& json = jsonBuffer.createObject();
	String text;

	json["luminosity"] = analogRead(SENSOR);

	json.printTo(text);
	Serial.println(text);

	delay(1000);
}
