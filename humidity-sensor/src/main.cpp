#include <Arduino.h>
#include <ArduinoJson.h>
#include <DHT.h>

#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600);
	dht.begin();
}

void loop() {
	float humidity = dht.readHumidity();
	float temperature = dht.readTemperature();

	StaticJsonBuffer<200> jsonBuffer;
	JsonObject& json = jsonBuffer.createObject();
	String text;

	if (isnan(humidity) || isnan(temperature)) {
		json["success"] = false;
		json["message"] = "não foi possível ler a humidade/temporatura";
	} else {
		json["success"] = true;
		json["message"] = jsonBuffer.createObject();
		json["message"]["humidity"] = humidity;
		json["message"]["temperature"] = temperature;
	}

	json.printTo(text);
	Serial.println(text);

	delay(200);
}
