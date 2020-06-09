#define txtsize 2 //rozmiar wyswietlanego tekstu
#define CS   10 //pin wyswietlacza
#define DC   9 //pin wyswietlacza
#define RESET  8 //pin wyswietlacza
#define CS_PIN   3 //pin potencjometru

void pomiar();
void start_dev();
void stop_dev(); 
void DigitalPotTransfer(int cmd, int value);

Adafruit_ADS1115 ads;
TFT myScreen = TFT(CS, DC, RESET);

//potentiometer select byte
const int POT0_SEL = 0x11;
const int POT1_SEL = 0x12;
const int BOTH_POT_SEL = 0x13;

int start_button_pin = 37;
int stop_button_pin = 38;

int start_signal_pin = 39;
int stop_signal_pin = 40;

int status_power_pin = 41;
int status_own_pin = 42;

char s[] = "  "; //znak specjalny dla stopnie,
int red = 255, gre = 0, blu = 255; //kolor czcionki wybranego elementu

float digit1_tmp = 0;  //pomocniczna zmienna
float digit1 = 0; //termopara blok wodny
float digit2_tmp = 0; //pomocniczna zmienna
float digit2 = 0; //termopara radiator
char printout1[5]; //tablica do przechowywania odczytu
char printout2[5]; //tablica do przechowywania odczytu
int screen_position = 1;
int POT0_Dn = 256;
int POT1_Dn = 256;
int BOTH_POT_Dn = 256;
int Tmin = -20;
int Tmax = 80; //gorny zakres mapowania
int load = 100;
