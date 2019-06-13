#include <Arduino.h>
#include <ArduinoJson.h>

void setup() {
	Serial.begin(9600);
}

void loop() {
	StaticJsonBuffer<200> jsonBuffer;
	JsonObject& json = jsonBuffer.createObject();
	String text;

	json["name"] = "Guilherme Bigois";
	json["age"] = 23;
	json["sex"] = "M";
	json["isAwake"] = true;

	json.printTo(text);
	Serial.print(text + "\n");

	delay(3000);
}
