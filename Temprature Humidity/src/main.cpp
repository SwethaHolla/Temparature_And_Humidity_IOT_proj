#include<Arduino.h>
#include<Adafruit_Sensor.h>
#include "dht.h"


// WiFi Configuration

#define DHT22_PIN 5
//our sensor is DHT22 type
#define DHTTYPE DHT22
//create an instance of DHT sensor
DHT dht(DHT22_PIN, DHTTYPE);
String val = "";
void setup() {
Serial.begin(115200);
Serial.println("DHT22 sensor!");
//call begin to start sensor
dht.begin();
}
 
void loop() {
//use the functions which are supplied by library.
float h = dht.readHumidity();
// Read temperature as Celsius (the default)
float t = dht.readTemperature();
// Check if any reads failed and exit early (to try again).
if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from DHT sensor!");
return;
}
// print the result to Terminal
val = (String)h + "%"+(String)t;
Serial.println(val);
//we delay a little bit for next read
delay(500);
}