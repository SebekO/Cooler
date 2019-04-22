void homee()
{
  int i; //iterator dla tablicy
  int vmax = 5; //gorny zakres mapowania
  but = 0;
  if(point != 0) //sprawdzanie polozenia
  {
    myScreen.background(255, 255, 255); // clear the screen
    myScreen.stroke(0, 0, 0);
    myScreen.text("STATUS", 40, 1);
    myScreen.text("TEMP B:", 0, 20);
    myScreen.text(printout1, 85, 20);
    myScreen.text(s, 138, 20);
    myScreen.text("C", 149, 20);
    myScreen.text("TEMP R:", 0, 40);
    myScreen.text(printout2, 85, 40);
    myScreen.text(s, 138, 40);
    myScreen.text("C", 149, 40);
    myScreen.text("HALL I:", 0, 60);
    myScreen.text(printout3, 85, 60);
    myScreen.text("A", 138, 60);
    myScreen.text("TEMP P:", 0, 80);
    myScreen.text(s, 138, 80);
    myScreen.text("C", 149, 80);
    myScreen.text("ERRROR:", 0, 100);
    String elapsedVar = String(err);
    elapsedVar.toCharArray(printout,2);
    myScreen.text(printout, 85, 100);
    myScreen.text(g, 150, 110);
  }
  point = 0; //ustawnie wskażnika na pulpicie menu

  //odczyt z termopary B
  digit1 = analogRead(analogPin0);
  digit1 = map(digit1, 0, 1023 , 0, vmax);
  if(digit1_tmp != digit1 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout1, 85, 20);
    String elapsedVar1 = String(digit1);
    elapsedVar1.toCharArray(printout1,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout1, 85, 20);
    t_digit1[i] = digit1; //tablica na dane do wykresu  
  }
  digit1_tmp = analogRead(analogPin0);
  digit1_tmp = map(digit1_tmp, 0, 1023 , 0, vmax);
  
  //odczyt z termopary R
  digit2 = analogRead(analogPin2);
  digit2 = map(digit2, 0, 1023 , 0, vmax);
  if(digit2_tmp != digit2 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout2, 85, 40);
    String elapsedVar2 = String(digit2);
    elapsedVar2.toCharArray(printout2,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout2, 85, 40);  
    t_digit2[i] = digit2;
  }
  digit2_tmp = analogRead(analogPin2);
  digit2_tmp = map(digit2_tmp, 0, 1023 , 0, vmax);
  
  //odczyt z czujnika Halla
  digit3 = analogRead(analogPin5);
  digit3 = map(digit3, 0, 1023 , 0, vmax);
  if(digit3_tmp != digit3 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout3, 85, 60);
    String elapsedVar3 = String(digit3);
    elapsedVar3.toCharArray(printout3,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout3, 85, 60); 
    t_digit3[i] = digit3;
  }
  digit3_tmp = analogRead(analogPin5);
  digit3_tmp = map(digit3_tmp, 0, 1023 , 0, vmax);
  if(i == 1000)
    i = 0;


//odczyt z termopary P
  digit4 = analogRead(analogPin4);
  digit4 = map(digit4, 0, 1023 , 0, vmax);
  if(digit4_tmp != digit4 and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout4, 85, 20);
    String elapsedVar1 = String(digit4);
    elapsedVar1.toCharArray(printout4,5);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout4, 85, 20);
    t_digit4[i] = digit4; //tablica na dane do wykresu  
  }
  digit4_tmp = analogRead(analogPin4);
  digit4_tmp = map(digit4_tmp, 0, 1023 , 0, vmax);
  i++;
}
