#define n 7

void check_dev();
void temp();
void check_own();

int analog[4] = { A0, A1, A2, A3 }; //Temp: pw, pw, ui, pan
int relay[n] = { 5, 6, 7, 8, 9, 10, 11}; //relay: 5V, 32A, 10A,  24V, fan1, fan2, pump
int status_ui_pin = 1; //D8
int reset_ui_pin = 2; //D4
int status_pw_pin = 0; //D7
int status_T_pin = 3; //D7
int status_pin = 4;
int T_min = 0;
int T_err = 80;
float temperatureC[4];
bool t_status;
