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
  
  //sprawdzanie temp
  w_temp[0] = 25; w_temp[1] = 25; w_temp[2] = 0; w_temp[3] = 25;
  if(temp_chceck())
  {
    myScreen.text("ERROR TEMP 1", 0, 40);
    delay(5000);
    menu();
  }
  
  //włączenie pompy
  
  //sprawdzanie temp
  w_temp[0] = 20; w_temp[2] = 5; w_temp[3] = 25;
  if(temp_chceck())
  {
    myScreen.text("ERROR TEMP 4", 0, 40);
    delay(5000);
    menu();
  }
  
  //właczenie d peltiera na 25%
  for (POT0_Dn = 0; POT0_Dn < 63; POT0_Dn++)
  {
    DigitalPotWrite(POT0_SEL , 255 - POT0_Dn);
    delay(10);
  }
  
  //sprawdzanie temp i pradu
  w_temp[0] = 30; w_temp[2] = 5; w_temp[3] = 5;
  if(temp_chceck())
  {
    myScreen.text("ERROR TEMP 2", 0, 40);
    delay(5000);
    menu();
  }
  
  //właczenie m peltiera na 15%
  for (POT1_Dn = 0; POT1_Dn < 38; POT1_Dn++)
  {
    DigitalPotWrite(POT1_SEL , 255 - POT1_Dn);
    delay(10);
  }
  
  //właczenie wentylatora
  
  //sprawdzanie temp
  w_temp[0] = 30; w_temp[2] = 5; w_temp[3] = 5;
  if(temp_chceck())
  {
    myScreen.text("ERROR TEMP 3", 0, 40);
    delay(5000);
    menu();
  }
  
  // właczenie d peltiera na 75%
  
  //sprawdzanie temp
  w_temp[0] = 30; w_temp[2] = 5; w_temp[3] = 5;
  if(temp_chceck())
  {
    myScreen.text("ERROR TEMP 4", 0, 40);
    delay(5000);
    menu();
  }

    
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
