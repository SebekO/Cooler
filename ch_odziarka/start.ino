void start()
{
  but = 0;
  if(point != 11)
  {
    myScreen.background(255, 255, 255);
    myScreen.text("START", 50, 1);
    myScreen.text("INIT...", 0, 20);
    delay(100);
  }
  point = 11;
  for(POT0_Dn; POT0_Dn < 256; POT0_Dn++)
  {
    DigitalPotWrite(POT0_SEL, 255 - POT0_Dn);
    if(POT0_Dn%10 == 0)
    {
      POT1_Dn = POT1_Dn + 5;
      DigitalPotWrite(POT1_SEL, 255 - POT1_Dn);
    }
    delay(load);
  }
  DigitalPotWrite(BOTH_POT_SEL, BOTH_POT_Dn);
  DigitalPotWrite(POT0_SEL, POT0_Dn);
  DigitalPotWrite(POT1_SEL, POT1_Dn); 
}
