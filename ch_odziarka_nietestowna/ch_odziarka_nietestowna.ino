/*

  Created 09.05.2019 by:
  Sebastian Owarzany
  Technical Physics
  Faculty of Physics and Applied Computer Science
  AGH University of Science and Technology
  https://github.com/SebekO
  
*/

#include <TFT.h>
#include <SPI.h>

//ustawienia:
#define CS   10 //pin wyswietlacza
#define DC   9 //pin wyswietlacza
#define RESET  8 //pin wyswietlacza
#define txtsize 2 //rozmiar wyswietlanego tekstu
#define N 80 //ilosc punktów do wykresu
#define load 50 //czas pomiedzy zmianami potencjometru przy załączaniu peltierow

const int CS_PIN = 3; //pin SPI potencjometru cyfrowego
const int PUMP_PIN = 0; //pin sterowania przekaźnikiem dla pompy
const int FAN_PIN = 1; //pin sterowania przekaźnikiem dla wentylatora

const int analogPin0 = A0; //czujnik temp B
const int analogPin2 = A1; //czujnik temp R
const int analogPin3 = A2; //czujnik halla
const int analogPin4 = A3; ///czujnik temp dP

const int red = 255, gre = 0, blu = 255; //kolor czcionki wybranego elementu
const int goPin = 6; //przycisk akceptacji
const int downPin = 5; //przycisk wyboru
const int backPin = 2; //przycisk powrotu


//deklaracja:
float digit1_tmp = 0;  //pomocniczna zmienna
float digit1 = 0; //termopara blok wodny
float digit2_tmp = 0; //pomocniczna zmienna
float digit2 = 0; //termopara radiator
float digit3_tmp = 0; //pomocniczna zmienna
float digit3 = 0; //czujnik halla
float digit4_tmp = 0; //pomocniczna zmienna
float digit4 = 0; //termopara duzy peltier
float var_set = 0; //zmienna dla ustawien

int err = 0; //stan urządzenia
int err_tmp = 2; //pomocniczna zmienna
char printout[2]; //tablica do przechowywania stanu urzadzenia

char printout1[5]; //tablica do przechowywania odczytu
char printout2[5]; //tablica do przechowywania odczytu
char printout3[5]; //tablica do przechowywania odczytu
char printout4[5]; //tablica do przechowywania odczytu
int w_temp[3]; //tablica do przechowywania zadanych wartosci temp

char h[] = "  "; //znak specjalny dla strzalki w lewo
char d[] = "  "; //znak specjalny dla strzalki w dol
char g[] = "  "; //znak specjalny dla strzalk i w gore
char s[] = "  "; //znak specjalny dla stopnie
int point = 0; //aktualne menu programu
int but = 0; //aktualny stan przycisku wyboru
int but1 = 0; //aktualny stan przycisku akceptacji/powrotu
int mstick = 0; //dla iteratora

int t_digit1[N] = {0}; //tablica na dane do wykresu wartowsci digital
int t_digit2[N] = {0}; //tablica na dane do wykresu wartowsci digita2
int t_digit3[N] = {0}; //tablica na dane do wykresu wartowsci digita3
int t_digit4[N] = {0}; //tablica na dane do wykresu wartowsci digita4

//potentiometer select byte
const int POT0_SEL = 0x11; //adres duzego peltiera
const int POT1_SEL = 0x12; //adres malego peltiera
const int BOTH_POT_SEL = 0x13; //adres obu peltierow

//shutdown the device to put it into power-saving mode.
//In this mode, terminal A is open-circuited and the B and W terminals are shorted together.
//send new command and value to exit shutdowm mode.
const int POT0_SHUTDOWN = 0x21;
const int POT1_SHUTDOWN = 0x22;
const int BOTH_POT_SHUTDOWN = 0x23;

//resistance value byte (0 - 255)
//The wiper is reset to the mid-scale position upon power-up, i.e. POT0_Dn = POT1_Dn = 128
int POT0_Dn = 256; //wartosc oprou dla pwm duzego peltiera
int POT1_Dn = 256; //wartosc oprou dla pwm duzego peltiera
int BOTH_POT_Dn = 256; //wartosc oprou dla pwm obu peltierow

//prototypy funkcji:
void back();
void down();
void go();
void home_tft();
void menu_tft();
void settings_tft();
void dev();
void setb();
void setr();
void seti();
void rest() {};
void dev_check(bool);
void get_values();
void get_plot();
void DigitalPotTransfer(int cmd, int value);

int temp_chceck();
int start();

TFT myScreen = TFT(CS, DC, RESET); //zmienna dla ekranu

void setup()
{
  //deklaracja wyjsc:
  pinMode(goPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(backPin, INPUT_PULLUP);
  pinMode(CS_PIN, OUTPUT); //potencjomentr
  SPI.begin(); //inicjalizacja SPI:
  //deklaracja strzalek:
  h[0] = 27;
  d[0] = 25;
  g[0] = 26;
  s[0] = 247; //stopnie
  //ustawienia ekranu:
  myScreen.begin(); //wlacz
  myScreen.setTextSize(txtsize); //ustaw czcionke
  myScreen.background(255, 255, 255); //ustaw kolor tla
  //inicjalizacja ekranu startowego:
  myScreen.stroke(0, 0, 0); //ustaw kolor liter
  myScreen.text("STATUS", 40, 1);
  myScreen.text("TEMP B:", 0, 20);
  myScreen.text(s, 138, 20);
  myScreen.text("C", 149, 20);
  myScreen.text("TEMP R:", 0, 40);
  myScreen.text(s, 138, 40);
  myScreen.text("C", 149, 40);
  myScreen.text("HALL I:", 0, 60);
  myScreen.text("A", 138, 60);
  myScreen.text("TEMP P:", 0, 80);
  myScreen.text(s, 138, 80);
  myScreen.text("C", 149, 80);
  myScreen.text("ERRROR:", 0, 100);
  myScreen.text(g, 150, 110);
}
void loop()
{
  home_tft(); //funkcja puliptu menu
  if ((digitalRead(goPin)))
    go(); //funkcja przycisku akceptacji
}
float map(float x, float in_min, float in_max, float out_min, float out_max) {
  x = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  float value = (int)(x * 100 + .5);
  return (float)value / 100;
}

int map1(int x, int in_min, int in_max, int out_min, int out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
void DigitalPotWrite(int cmd, int val)
{
  // constrain input value within 0 - 255
  val = constrain(val, 0, 255);
  // set the CS pin to low to select the chip:
  digitalWrite(CS_PIN, LOW);
  // send the command and value via SPI:
  SPI.transfer(cmd);
  SPI.transfer(val);
  // Set the CS pin high to execute the command:
  digitalWrite(CS_PIN, HIGH);
}
