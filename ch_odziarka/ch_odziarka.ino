#include <TFT.h> 
#include <SPI.h>

char printout[4];

int analogPin = A3;

#define CS   10
#define DC   9
#define RESET  8
#define txtsize 2
int v1 = 0;
int v = 0;
char h[] = "  ";
char d[] = "  ";
char g[] = "  ";

int col = 255;

int goPin = 7;
int downPin = 6;
int backPin = 5;
int point = 0;
int but = 0;

void back();
void down();
void go();
void homee();
void menu();
void settings();
void start();
void dev();
void setb(){};
void setr(){};
void seti(){};
void rest(){};

TFT myScreen = TFT(CS, DC, RESET);
void setup()
{
  pinMode(goPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(backPin, INPUT_PULLUP);
  h[0] = 27;
  d[0] = 25;
  g[0] = 26;
  myScreen.setTextSize(txtsize);
  myScreen.begin();  
  myScreen.background(255, 255, 255); // clear the screen
  myScreen.stroke(0, 0, 0);
  myScreen.text("STATUS", 40, 1);
  myScreen.text("TEMP B[C]:", 0, 20);
  myScreen.text("TEMP R[C]:", 0, 40);
  myScreen.text("I[A]:", 0, 60);
  myScreen.text("ERRROR:", 0, 80);
  myScreen.text(g, 150, 110);

}
void loop()
{
  homee();
  if((digitalRead(goPin)))
  go();
  if((digitalRead(downPin)))
  down();
  if((digitalRead(backPin)))
  back();
}
