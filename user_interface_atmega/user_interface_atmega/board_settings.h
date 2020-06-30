#define txtsize 2 //rozmiar wyswietlanego tekstu
#define CS   10 //pin wyswietlacza
#define DC   9 //pin wyswietlacza
#define RESET  8 //pin wyswietlacza
#define CS_PIN   7 //pin potencjometru

void pomiar();
void start_dev();
void stop_dev(); 
void DigitalPotTransfer(int cmd, int value);

TFT myScreen = TFT(CS, DC, RESET);

//potentiometer select byte
const int POT0_SEL = 0x11;
const int POT1_SEL = 0x12;
const int BOTH_POT_SEL = 0x13;

int start_button_pin = 4;
int set_button_pin = 5;
int stop_button_pin = 6;



int status_own_pin = 0;
int status_power_pin = 1;
int status_T_pin = 2;
int status_pin = 3;

int tc_O = A0;  //termocopule in object
int tc_B = A1; //termocopule in block

char s[] = "  "; //special char
int red = 255, gre = 0, blu = 255; //selected font color

float data_tc_O_tmp = 0;  //tmp int
float data_tc_O = 0; //
float data_tc_B_tmp = 0; //tmp int
float data_tc_B = 0; //termopara radiator
char printout1[5]; //tablica do przechowywania odczytu
char printout2[5]; //tablica do przechowywania odczytu
int screen_position = 1;
int POT0_Dn = 256;
int POT1_Dn = 256;
int BOTH_POT_Dn = 256;
int Tmin = -20;
int Tmax = 80; //gorny zakres mapowania
int load = 100;
