void settings_tft()
{
  but = 0;
  if(point != 12)
  {
    myScreen.background(255, 255, 255);
    myScreen.text("SETTINGS", 40, 1);
    myScreen.stroke(red, gre, blu);
    myScreen.text("1.SET TEMP B", 0, 20);
    myScreen.stroke(0, 0, 0);
    myScreen.text("2.SET TEMP R", 0, 40);
    myScreen.text("3.SET I", 0, 60);
    myScreen.text("4.RE-DEFAULT", 0, 80);
    myScreen.text(h, 0, 110);
    myScreen.text(d, 75, 110);
    myScreen.text(g, 150, 110);
  }
  point = 12;
  delay(100);
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
