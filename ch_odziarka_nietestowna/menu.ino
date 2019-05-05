void menu()
{
  but = 0;
  if(point != 1)
  {
    myScreen.background(255, 255, 255);
    myScreen.text("MENU", 55, 1);
    myScreen.stroke(red, gre, blu);
    myScreen.text("1.START", 0, 20);
    myScreen.stroke(0, 0, 0);
    myScreen.text("2.SETTINGS", 0, 40);
    myScreen.text("3.DEVICE", 0, 60);
    myScreen.text("4.LOGS", 0, 80);
    myScreen.text(h, 0, 110);
    myScreen.text(d, 75, 110);
    myScreen.text(g, 150, 110);
    delay(100);
  }
  point = 1;
  while(!(digitalRead(backPin)) or !(digitalRead(goPin)))
  {
    if((digitalRead(goPin)))
    go();
    if((digitalRead(downPin)))
    down();
    if((digitalRead(backPin)))
    back();
  }
}
