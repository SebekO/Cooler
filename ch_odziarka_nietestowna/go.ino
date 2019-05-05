void go()
{
  if(point == 0)
  menu_tft();
  if(point == 1)
  {
    if(but == 0)
    {
      if(start())
        home_tft();
    }
    if(but == 1)
      settings_tft();
    if(but == 2)
      dev();
    if(but == 3)
      plot_tft();
  }
  if(point == 12)
  {
    if(but == 0)
      setb();
    if(but == 1)
      setr();
    if(but == 2)
      seti();
    if(but == 3)
      rest();
  }
  if(point == 121 or point == 122 or point == 123)
  {
    but1--;
    delay(100);
  }
}
