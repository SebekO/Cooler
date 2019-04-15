void down()
{
  if(point == 0)
    return;
  else if(point == 1)
  {
    if(but == 0)
    {
      myScreen.text("1.START", 0, 20);
      myScreen.stroke(col, 0, col);
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    else if(but == 1)
    {
      myScreen.text("1.START", 0, 20);
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.stroke(col, 0, col);
      myScreen.text("3.DEVICE", 0, 60);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    else if(but == 2)
    {
      myScreen.text("1.START", 0, 20);
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.text("3.DEVICE", 0, 60);
      myScreen.stroke(col, 0, col);
      myScreen.text("4.LOGS", 0, 80);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    else if(but == 3)
    {
      myScreen.text("2.SETTINGS", 0, 40);
      myScreen.text("3.DEVICE", 0, 60);
      myScreen.text("4.LOGS", 0, 80);
      myScreen.stroke(col, 0, col);
      myScreen.text("1.START", 0, 20);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but = 0;
    }
  }
  else if(point == 12)
  {
    if(but == 0)
    {
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.stroke(col, 0, col);
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    else if(but == 1)
    {
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.stroke(col, 0, col);
      myScreen.text("3.SET I", 0, 60);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    else if(but == 2)
    {
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.text("3.SET I", 0, 60);
      myScreen.stroke(col, 0, col);
      myScreen.text("4.RE-DEFAULT", 0, 80);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but++;
    }
    else if(but == 3)
    {
      myScreen.text("2.SET TEMP R", 0, 40);
      myScreen.text("4.RE-DEFAULT", 0, 80);
      myScreen.text("3.SET I", 0, 60);
      myScreen.stroke(col, 0, col);
      myScreen.text("1.SET TEMP B", 0, 20);
      myScreen.stroke(0, 0, 0);
      delay(500);
      but = 0;
    }
  }
  return;
}
