void dev_check(bool tryb)
{
  err = 0;
  if(tryb)
  {
    
     if(!(digit1 > -18))
    {
      err = 1; 
    }
    if(!(digit2 > -18))
    {
      err = 1; 
    }
    if(!(digit3 > 0))
    {
      err = 1; 
    }
    if(!(digit4 > -18))
    {
      err = 1; 
    }
  }
  else
  {
    if(digit1 > -18 or digit1 < 99)
    {
      myScreen.text("OK", 120, 20);
    }
    else
    {
      myScreen.stroke(255, 255, 255);
      myScreen.text("OK", 120, 20);
      myScreen.stroke(0, 0, 0);
      myScreen.text("NOK", 120, 20);
      err = 1;  
    }
    if(digit2 > -18 or digit2 < 99)
    {
      myScreen.text("OK", 120, 40);
    }
    else
    {
      myScreen.stroke(255, 255, 255);
      myScreen.text("OK", 120, 40);
      myScreen.stroke(0, 0, 0);
      myScreen.text("NOK", 120, 40);
      err = 1;
    }
    if(digit3 > 0 or digit3 < 20)
    {
      myScreen.text("OK", 83, 60);
    }
    else
    {
      myScreen.stroke(255, 255, 255);
      myScreen.text("OK", 83, 60);
      myScreen.stroke(0, 0, 0);
      myScreen.text("NOK", 83, 60);
      err = 1;
    }
    if(digit4 > -18 or digit4 < 99)
    {
      myScreen.text("OK", 120, 80);
    }
    else
    {
      myScreen.stroke(255, 255, 255);
      myScreen.text("OK", 120, 80);
      myScreen.stroke(0, 0, 0);
      myScreen.text("NOK", 120, 80);
      err = 1;
    }
  }
}
