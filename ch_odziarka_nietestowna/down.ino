void down()
{
  if(point == 0)
    return;
  if(point == 121 or point == 122 or point == 123)
  {
   settings();
  }
  if(point == 1)
  {
    if(but == 0)
    {
      myScreen.text("1.START", 0, 20);
      myScreen.stroke(red, gre, blu);
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    if(but == 1)
    {
      myScreen.text("1.START", 0, 20);
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.stroke(red, gre, blu);
      myScreen.text("3.DEVICE", 0, 60);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    if(but == 2)
    {
      myScreen.text("1.START", 0, 20);
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.text("3.DEVICE", 0, 60);
      myScreen.stroke(red, gre, blu);
      myScreen.text("4.LOGS", 0, 80);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    if(but == 3)
    {
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.text("3.DEVICE", 0, 60);
      myScreen.text("4.LOGS", 0, 80);
      myScreen.stroke(red, gre, blu);
      myScreen.text("1.START", 0, 20);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but = 0;
    }
  }
  if(point == 12)
  {
    if(but == 0)
    {
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.stroke(red, gre, blu);
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    if(but == 1)
    {
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.stroke(red, gre, blu);
      myScreen.text("3.SET I", 0, 60);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    if(but == 2)
    {
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.text("3.SET I", 0, 60);
      myScreen.stroke(red, gre, blu);
      myScreen.text("4.RE-DEFAULT", 0, 80);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    if(but == 3)
    {
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.text("4.RE-DEFAULT", 0, 80);
      myScreen.text("3.SET I", 0, 60);
      myScreen.stroke(red, gre, blu);
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but = 0;
    }
  }
  return;
}
