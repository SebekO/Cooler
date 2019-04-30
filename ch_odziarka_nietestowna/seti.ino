void seti()
{
  float var_set_tmp = 0;
  but = 0;
  but1 = 0;
  if(point != 123)
  {
    myScreen.background(255, 255, 255); // clear the screen
    myScreen.text("SET I", 50, 1);
    myScreen.text("I WANT:", 40, 30);
    myScreen.setTextSize(3);
    myScreen.stroke(red, gre, blu);
    myScreen.text(printout3, 40, 60);
    myScreen.text("A", 128, 60);
    myScreen.stroke(0, 0, 0);
    myScreen.setTextSize(2);
    myScreen.text("-", 0, 110);
    myScreen.text("OK", 75, 110);
    myScreen.text("+", 150, 110);
  }
  point = 123;
  while(!(digitalRead(downPin)))
  {
    if((digitalRead(goPin)))
    go();
    if((digitalRead(downPin)))
    down();
    if((digitalRead(backPin)))
    back();
    
    var_set = digit3 - (but1*0.1);
    if(var_set != var_set_tmp)
    {
    myScreen.setTextSize(3);
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout3, 40, 60);
    myScreen.stroke(red, gre, blu);
    String elapsedVar = String(var_set);
    elapsedVar.toCharArray(printout3,5);
    myScreen.text(printout3, 40, 60);
    myScreen.stroke(0, 0, 0);
    myScreen.setTextSize(2);
    }
    var_set_tmp = var_set;
  }
}
