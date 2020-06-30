/*

Created by:
Sebastian Owarzany
Technical Physics
Faculty of Physics and Applied Computer Science
AGH University of Science and Technology
https://github.com/SebekO
*/
#include <Wire.h>
#include "Adafruit_MCP23008.h"
#include "board_settings.h"

Adafruit_MCP23008 mcp;
OneWire oneWire(oneWireBus);
OneWire oneWire1(oneWireBus1);
DallasTemperature sensors(&oneWire);
DallasTemperature sensors1(&oneWire1);

void setup()
{
  sensors.begin();
  sensors1.begin();
  mcp.begin(); 

  for(int i=0; i<n; i++)
  {
    mcp.pinMode(i, OUTPUT);
    mcp.digitalWrite(i, HIGH);
  }
  pinMode(status_dev_pin, INPUT);
  pinMode(status_own_pin, OUTPUT);
  pinMode(reset_dev_pin, OUTPUT);
  digitalWrite(status_own_pin, HIGH);
  digitalWrite(reset_dev_pin, HIGH);
  check_dev();
}

void loop()
{
  temp();
  check_dev();
}

void temp()
{
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  sensors1.requestTemperatures(); 
  float temperatureC1 = sensors1.getTempCByIndex(0);
  if (temperatureC < T_min || temperatureC1 < T_min || temperatureC > T_err || temperatureC1 >T_err){
    Serial.println(temperatureC);
    Serial.println(temperatureC1);
    Serial.println("Error reading temperature!");
    check_own();
  }
  else{  
    if (temperatureC > 50 || temperatureC1 > 50) {
      Serial.println(F("Error reading temperature! or temp: "));
      Serial.println(temperatureC);
      Serial.println(temperatureC1);
      for (int i = 0; i < n; i++) {
        mcp.digitalWrite(i, HIGH);
      }
    }
    else{
      if( temperatureC > 30 || temperatureC1 > 30){
        Serial.println(temperatureC);
        Serial.println(temperatureC1);
        mcp.digitalWrite(7, HIGH);
      }
      else{
        Serial.println(temperatureC);
        Serial.println(temperatureC1);
        mcp.digitalWrite(7, HIGH);
      }
    }
  }
}

void check_dev()
{
  if( digitalRead(status_dev_pin) == LOW && digitalRead(relay[0]) == HIGH ){
    Serial.println("restart uC za 3...");
    delay(1000);
    Serial.println("restart uC za 2...");
    delay(1000);
    Serial.println("restart uC za 1...");
    delay(1000);
    Serial.println("restarting uC...");
    delay(1000);
    for (int i = 0; i < n; i++) {
      mcp.digitalWrite(i, LOW);
    }
    digitalWrite(reset_dev_pin, LOW);
    delay(1000);
    digitalWrite(reset_dev_pin, HIGH);
    delay(5000);
    for (int i = 0; i < n; i++) {
      mcp.digitalWrite(i, HIGH);
    }
  }
  else{
  Serial.println("uC status: OK");
  }
}
