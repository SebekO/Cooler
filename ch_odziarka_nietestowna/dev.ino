void dev()
{
  if(point != 13)
  {
  myScreen.background(255, 255, 255);
  myScreen.text("DEVICE", 3, 1);
  myScreen.text("1.THERM B:", 0, 20);
  myScreen.text("2.THERM R:", 0, 40);
  myScreen.text("3.HALL:", 0, 60);
  myScreen.text(h, 0, 110);
  point = 13;
  delay(100);
  }
  if(digit1 != 0)
  {
    myScreen.text("OK", 120, 20);
  }
  else
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text("OK", 120, 20);
    myScreen.stroke(0, 0, 0);
    myScreen.text("NOK", 120, 20);
  }
  if(digit2 != 0)
  {
    myScreen.text("OK", 120, 40);
  }
  else
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text("OK", 120, 40);
    myScreen.stroke(0, 0, 0);
    myScreen.text("NOK", 120, 40);
  }
  if(digit3 != 0)
  {
    myScreen.text("OK", 83, 60);
  }
  else
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text("OK", 83, 60);
    myScreen.stroke(0, 0, 0);
    myScreen.text("NOK", 83, 60);
  }
}
