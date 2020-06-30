/*
Created by:
Sebastian Owarzany
Technical Physics
Faculty of Physics and Applied Computer Science
AGH University of Science and Technology
https://github.com/SebekO
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "board_settings.h"

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  
  for (int i = 0; i < n; i++) {
    pinMode(relay[i], OUTPUT);
    digitalWrite(relay[i], HIGH);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(analog[i], INPUT);
  }
  pinMode(status_pw_pin, OUTPUT);
  pinMode(status_ui_pin, INPUT);
  pinMode(reset_ui_pin, OUTPUT);
  pinMode(status_T_pin, OUTPUT);
  pinMode(status_pin, INPUT);

  digitalWrite(status_pw_pin, HIGH);
  digitalWrite(reset_ui_pin, LOW);
  digitalWrite(status_T_pin, HIGH);
  check_dev();
}

void loop()
{
  temp();
  //check_dev();
  delay(1000);
}

void temp()
{
  for (int i = 0; i < 4; i++) {
    temperatureC[i] = map(analogRead(analog[i]), 0, 1024, -10, 90);
    lcd.setCursor(0,i);
    lcd.print("T");
    lcd.setCursor(1,i);
    lcd.print(i);
    lcd.setCursor(2,i);
    lcd.print(":");
    lcd.setCursor(3,i);
    lcd.print(temperatureC[i]);
    if(temperatureC[i] < T_min || temperatureC[i] > T_err){
      t_status = 1;
    }
  }
  
  lcd.setCursor(10,0);
  lcd.print("UI:");
  lcd.setCursor(13,0);
  lcd.print(digitalRead(status_ui_pin));
  lcd.setCursor(10,1);
  lcd.print("DEV:");
  lcd.setCursor(14,1);
  lcd.print(digitalRead(status_pin));
  
  if(t_status){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error temperature!");
    check_own();
  }
  else{  
    if (temperatureC[0] > 50 || temperatureC[1] > 50) {
      Serial.println(F("Error reading temperature! or temp: "));
      Serial.println(temperatureC[0]);
      Serial.println(temperatureC[1]);
      for (int i = 0; i < n; i++) {
        digitalWrite(relay[i], LOW);
      }
    }
    else{
      if( temperatureC[0] > 30 || temperatureC[1] > 30){
        Serial.println(temperatureC[0]);
      Serial.println(temperatureC[1]);
        digitalWrite(relay[4], HIGH);
      }
      else{
        Serial.println(temperatureC[0]);
      Serial.println(temperatureC[1]);
        digitalWrite(relay[4], LOW);
      }
    }
  }
}

void check_dev()
{
  if( digitalRead(status_ui_pin) == LOW && digitalRead(relay[0]) == HIGH ){
    Serial.println("restart uC in 3...");
    delay(1000);
    Serial.println("restart uC in 2...");
    delay(1000);
    Serial.println("restart uC in 1...");
    delay(1000);
    Serial.println("restarting uC...");
    delay(1000);
    for (int i = 0; i < n; i++) {
        digitalWrite(relay[i], LOW);
    }
    digitalWrite(reset_ui_pin, LOW);
    delay(1000);
    digitalWrite(reset_ui_pin, HIGH);
    delay(5000);
    for (int i = 0; i < n; i++) {
        digitalWrite(relay[i], HIGH);
    }
  }
  else{
  Serial.println("uC status: OK");
  }
}
void check_own()
{
  digitalWrite(status_T_pin, LOW);
  lcd.setCursor(0,1);
  lcd.print("restart in 3...");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("restart in 2...");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("restart in 1...");
  delay(1000);
  lcd.setCursor(0,2);
  lcd.print("restarting...");
  delay(1000);
  digitalWrite(relay[5], LOW);
  delay(1000);
  lcd.setCursor(0,3);
  lcd.print("...OK");
  t_status = 0;
  delay(1000);
  lcd.clear();
  
}
