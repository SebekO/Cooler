void go()
{
  if(point == 0)
  menu();
  else if(point == 1)
  {
    if(but == 0)
      start();
    else if(but == 1)
      settings();
    else if(but == 2)
      dev();
    else if(but == 3)
      logs();
  }
  else if(point == 12)
  {
    if(but == 0)
      setb();
    else if(but == 1)
      setr();
    else if(but == 2)
      seti();
    else if(but == 3)
      rest();
  }
}
