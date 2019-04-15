void homee()
{
  if(point != 0)
  {
    myScreen.background(255, 255, 255); // clear the screen
    myScreen.stroke(0, 0, 0);
    myScreen.text("STATUS", 40, 1);
    myScreen.text("TEMP B[C]:", 0, 20);
    myScreen.text("TEMP R[C]:", 0, 40);
    myScreen.text("I[A]:", 0, 60);
    myScreen.text("ERRROR:", 0, 80);
    myScreen.text(g, 150, 110);
    myScreen.text(printout, 120, 20);
  }
  v = analogRead(analogPin);
  if(v1 != v and point == 0)
  {
    myScreen.stroke(255, 255, 255);
    myScreen.text(printout, 120, 20);
    String elapsedTime = String(v);
    elapsedTime.toCharArray(printout,4);
    myScreen.stroke(0, 0 ,0);
    myScreen.text(printout, 120, 20);  
  }
  v1 = analogRead(analogPin);
  point = 0;
}
