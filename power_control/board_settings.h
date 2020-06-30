#define n 4

void check_dev();
void temp();
void check_own();

const int oneWireBus = 12; //D6 -> A1
const int oneWireBus1 = 14; //D5 -> A0

int relay[n] = { 16, 5, 4, 0}; // D0, D1, D2, D3, 
int status_dev_pin = 15; //D8
int reset_dev_pin = 2; //D4
int status_own_pin = 13; //D7
int T_min = 0;
int T_err = 80;

int timer = 0;
