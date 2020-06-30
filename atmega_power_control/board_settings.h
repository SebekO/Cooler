#define n 8

void check_dev();
void temp();
void check_own();

const int oneWireBus = 2; //PD2
const int oneWireBus1 = 3; //PD3

//mpc pin {0, 1, 2, 3, 4, 5, 6, 7} - {15V 32A, 15V 10A, 5V, x, x, x, fan}

int status_dev_pin = 5; //PD5
int reset_dev_pin = 2; //D4
int status_own_pin = 4; //PD4
int T_min = 0;
int T_err = 80;
int timer = 0;
