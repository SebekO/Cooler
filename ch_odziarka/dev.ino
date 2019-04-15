void dev()
{
  myScreen.background(255, 255, 255);
  myScreen.text("DEVICE", 3, 1);
  myScreen.text("1.THERMO B:", 0, 20);
  myScreen.text("2.THERMO R:", 0, 40);
  myScreen.text("3.HALL:", 0, 60);
  myScreen.text(h, 0, 110);
  point = 13;
  delay(100);
}
