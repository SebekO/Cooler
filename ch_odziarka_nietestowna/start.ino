int start()
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
  if(err == 1)
  {
    myScreen.text("ERROR DEVICE!", 0, 20);
    return 1;
  }
  
  //zmiana granic
  w_temp[0] = 25; w_temp[1] = 25; w_temp[2] = 0; w_temp[3] = 25;
  //sprawdzanie temp
  if(temp_chceck())
  {
    return 1;
  }
  myScreen.text("1...", 0, 40);
  //włączenie pompy
  
  //zmiana granic
  w_temp[0] = 20; w_temp[2] = 5; w_temp[3] = 25;
  //sprawdzanie temp
  if(temp_chceck())
  {
    return 1;
  }
  myScreen.text("1...2...", 0, 40);
  
  //właczenie d peltiera na 25%
  for (POT0_Dn = 0; POT0_Dn < 63; POT0_Dn++)
  {
    DigitalPotWrite(POT0_SEL , 255 - POT0_Dn);
    delay(10);
  }
  myScreen.text("123", 0, 40);
  
  //zmiana granic
  w_temp[0] = 30; w_temp[2] = 5; w_temp[3] = 5;
  //sprawdzanie temp
  if(temp_chceck())
  {
    return 1;
  }
  myScreen.text("1...2...3...", 0, 40);

  //właczenie m peltiera na 15%
  for (POT1_Dn = 0; POT1_Dn < 38; POT1_Dn++)
  {
    DigitalPotWrite(POT1_SEL , 255 - POT1_Dn);
    delay(10);
  }

  //właczenie wentylatora
  
  //zmiana granic
  w_temp[0] = 30; w_temp[2] = 5; w_temp[3] = 5;
  //sprawdzanie temp
  if(temp_chceck())
  {
    return 1;
  }
  myScreen.text("1...2...3...4...", 0, 40);
  
  // właczenie d peltiera na 75%
  
  //sprawdzanie temp
  w_temp[0] = 30; w_temp[2] = 5; w_temp[3] = 5;
  
  if(temp_chceck())
  {
    return 1;
  }
  myScreen.text("1...2...3...4...5", 0, 40);

  
    //przykład
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
  myScreen.text("INIT... DONE", 0, 20);
  delay(5000);
  return 1;
}




void mDelay( int ms) {
  mDelay(1);
  while( ms-- ) {
    delay(1);
    
    mstick++;
    if( mstick > 79 ) mstick=0;
    Serial.println(mstick);
  }
}
