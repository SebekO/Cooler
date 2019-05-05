void get_plot()
{
  point = 141;
  int xPos = 0;
  myScreen.background(255, 255, 255);
  myScreen.text(h, 0, 1);
  if(point == 141)
  {
    if(but == 0)
    {
      myScreen.text("TEMP B", 40, 1);
      for(int i = 0; i < N; i++)
      {
        int drawHeight = map1(t_digit1[i], -20, 100, 0, myScreen.height());
        myScreen.line(xPos, myScreen.height() - drawHeight, xPos, myScreen.height());
        if (xPos >= 160)
        {
          xPos = 0;
          myScreen.background(255, 255, 255);
        }
        else
        {
          // increment the horizontal position:
          xPos = xPos + 2;
        }
        delay(16);
      }
    }
    if(but == 1)
    {
      myScreen.text("TEMP R", 40, 1);
      for(int i = 0; i < N; i++)
      {
        int drawHeight = map1(t_digit2[i], -20, 100, 0, myScreen.height());
        myScreen.line(xPos, myScreen.height() - drawHeight, xPos, myScreen.height());
        if (xPos >= 160)
        {
          xPos = 0;
          myScreen.background(255, 255, 255);
        }
        else
        {
          // increment the horizontal position:
          xPos = xPos + 2;
        }
        delay(16);
      }
    }
    if(but == 2)
    {
      myScreen.text("HALL I", 40, 1);
      for(int i = 0; i < N; i++)
      {
        int drawHeight = map1(t_digit3[i], -20, 100, 0, myScreen.height());
        myScreen.line(xPos, myScreen.height() - drawHeight, xPos, myScreen.height());
        if (xPos >= 160)
        {
          xPos = 0;
          myScreen.background(255, 255, 255);
        }
        else
        {
          // increment the horizontal position:
          xPos = xPos + 2;
        }
        delay(16);
      }
    }
    if(but == 3)
    {
      myScreen.text("TEMP P", 40, 1);
      for(int i = 0; i < N; i++)
      {
        int drawHeight = map1(t_digit4[i], -20, 100, 0, myScreen.height());
        myScreen.line(xPos, myScreen.height() - drawHeight, xPos, myScreen.height());
        if (xPos >= 160)
        {
          xPos = 0;
          myScreen.background(255, 255, 255);
        }
        else
        {
          // increment the horizontal position:
          xPos = xPos + 2;
        }
        delay(16);
      } 
    }
  }
}
