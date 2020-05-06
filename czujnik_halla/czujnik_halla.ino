/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  float sr = 0;
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  voltage = map(voltage, 2.00, 2.58, 10, 0);
  for(int i = 0; i < 500; i++)
  {
    sensorValue = analogRead(A0);
    voltage = sensorValue * (5.0 / 1023.0);
    voltage = map(voltage, 1.7, 2.58, 20, 0);
     sr += voltage;
  }
  Serial.println(sr/500);
  Serial.println("-----------------------");
  delay(2000);
}
float map(float x, float in_min, float in_max, int out_min, int out_max) {
  x = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  float value = (int)(x * 100 + .5); 
  return (float)value / 100; 
}
