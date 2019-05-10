void get_values()
{
  float sr = 0;
  int prob = 50;
  //odczyt z termopary B
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit1 = analogRead(analogPin0);
    digit1 = digit1 * (5.0 / 1023.0);
    digit1 = map(digit1, 0, 5, 0, 98.5);
    sr += digit1;
  }
  digit1 = sr/prob;
  if(digit1_tmp != digit1 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout1, 85, 20);
    String elapsedVar1 = String(digit1);
    elapsedVar1.toCharArray(printout1,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout1, 85, 20);
    t_digit1[mstick] = short(digit1); //tablica na dane do wykresu  
  }
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit1_tmp = analogRead(analogPin0);
    digit1_tmp = digit1_tmp * (5.0 / 1023.0);
    digit1_tmp = map(digit1_tmp, 0, 5, 0, 98.5);
    sr += digit1_tmp;
  }
  digit1_tmp = sr/prob;
  
  //odczyt z termopary R
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit2 = analogRead(analogPin2);
    digit2 = digit2 * (5.0 / 1023.0);
    digit2 = map(digit2, 0, 5, 0, 98.5);
    sr += digit2;
  }
  digit2 = sr/prob;
  if(digit2_tmp != digit2 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout2, 85, 40);
    String elapsedVar2 = String(digit2);
    elapsedVar2.toCharArray(printout2,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout2, 85, 40);  
    t_digit2[mstick] = short(digit2);
  }
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit2_tmp = analogRead(analogPin2);
    digit2_tmp = digit2_tmp * (5.0 / 1023.0);
    digit2_tmp = map(digit2_tmp, 0, 5, 0, 98.5);
    sr += digit2_tmp;
  }
  digit2_tmp = sr/prob;
  
  //odczyt z czujnika Halla
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit3 = analogRead(analogPin3);
    digit3 = digit3 * (5.0 / 1023.0);
    digit3 = map(digit3, 2.64, 3.45, 0, 20);
    sr += digit3;
  }
  digit3 = sr/prob;
  digit3 = digit3 - digit3*0.09;
  if(digit3_tmp != digit3 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout3, 85, 60);
    String elapsedVar3 = String(digit3);
    elapsedVar3.toCharArray(printout3,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout3, 85, 60); 
    t_digit3[mstick] = short(digit3);
  }
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit3_tmp = analogRead(analogPin3);
    digit3_tmp = digit3_tmp * (5.0 / 1023.0);
    digit3_tmp = map(digit3_tmp, 2.64, 3.45, 0, 20);
    sr += digit3_tmp;
  }
  digit3_tmp = sr/prob;
  
  //odczyt z termopary P
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit4 = analogRead(analogPin4);
    digit4 = digit4 * (5.0 / 1023.0);
    digit4 = map(digit4, 0, 5, -100, 94.7);
    sr += digit4;
  }
  digit4 = sr/prob;
  if(digit4_tmp != digit4 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout4, 85, 80);
    String elapsedVar1 = String(digit4);
    elapsedVar1.toCharArray(printout4,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout4, 85, 80);
    t_digit4[mstick] = short(digit4); //tablica na dane do wykresu  
  }
  sr = 0;
  for(int i = 0; i < prob; i++)
  {
    digit4_tmp = analogRead(analogPin4);
    digit4_tmp = digit4_tmp * (5.0 / 1023.0);
    digit4_tmp = map(digit4_tmp, 0, 5, -100, 94.7);
    sr += digit4_tmp;
  }
  digit4_tmp = sr/prob;
  
  dev_check(1);
  if(err_tmp != err and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout, 85, 100);
    String elapsedVar = String(err);
    elapsedVar.toCharArray(printout,2);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout, 85, 100);
  }
  err_tmp = err;
  mstick++;
  if(mstick >= N)
   mstick = 0;
}
