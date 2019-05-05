void plot_tft()
{
  but = 0;
  if(point != 14) //sprawdzanie polozenia
  {
    myScreen.background(255, 255, 255);
    myScreen.text("PLOT", 40, 1);
    myScreen.stroke(red, gre, blu);
    myScreen.text("1.TEMP B", 0, 20);
    myScreen.stroke(0, 0, 0);
    myScreen.text("2.TEMP R", 0, 40);
    myScreen.text("3.HALL I", 0, 60);
    myScreen.text("4.TEMP P", 0, 80);
    myScreen.text(h, 0, 110);
    myScreen.text(d, 75, 110);
    myScreen.text(g, 150, 110);
    delay(100);
  }
  point = 14;
  while(!(digitalRead(backPin)) or !(digitalRead(goPin)))
  {
    if((digitalRead(goPin)))
    get_plot();
    if((digitalRead(downPin)))
    down();
    if((digitalRead(backPin)))
    back();
  }
}
