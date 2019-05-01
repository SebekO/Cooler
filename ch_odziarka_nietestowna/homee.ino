void homee()
{
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
    myScreen.text(printout4, 85, 80);
    myScreen.text(s, 138, 80);
    myScreen.text("C", 149, 80);
    myScreen.text("ERRROR:", 0, 100);
    String elapsedVar = String(err);
    elapsedVar.toCharArray(printout,2);
    myScreen.text(printout, 85, 100);
    myScreen.text(g, 150, 110);
  }
  point = 0; //ustawnie wskażnika na pulpicie menu
  while(!(digitalRead(goPin)))
  {
    get_values();
    if((digitalRead(goPin)))
    go();
  }
}
