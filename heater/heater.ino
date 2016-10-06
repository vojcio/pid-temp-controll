#include  <OneWire.h>
#include  <DallasTemperature.h>                                                        // Logging class
#include <Arduino.h>
#include "Calculate.h"

#define ONEWIREPIN 7
OneWire oneWire(ONEWIREPIN);                                              //start 1-wire
DallasTemperature sensor(&oneWire);                                       //construct sensors
float setPoint = 25;                                                      // our desired, initial temp
float temperature;
unsigned int interval = 1000;                                            // interval of calc computation
unsigned long previousMillis;
void setup() {
  Serial.begin(9600);
  sensor.begin();                           // start Dallas readings
  calc.begin(0, 100); // min and max output
}

void loop() {
  if(timeToWork()) {
    sensor.requestTemperatures();
    temperature = sensors.getTempCByIndex(0);
    Serial.print("Temp: "); Serial.print(temperature);
    Serial.print(" decision: "); if(toCold()) { startHeating(); }

    
    Serial.println("");
  }
}

bool timeToWork() {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) { //TODO:  check what will happen after 50 days 
    previousMillis = currentMillis;
    return true;
  } else return false;
}

bool toCold() {
  float error = setPoint - temp;
  if(error > isItCold) {
      return true;
  }
}

void startHeating() {
  
}

