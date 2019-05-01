void dev()
{
  if(point != 13)
  {
  myScreen.background(255, 255, 255);
  myScreen.text("DEVICE", 3, 1);
  myScreen.text("1.THERM B:", 0, 20);
  myScreen.text("2.THERM R:", 0, 40);
  myScreen.text("3.HALL:", 0, 60);
  myScreen.text("4.THERM P:", 0, 80);
  myScreen.text(h, 0, 110);
  delay(100);
  }
  point = 13;
  while(!(digitalRead(backPin)))
  {
    dev_check();
    if((digitalRead(backPin)))
    back();
  }
}
