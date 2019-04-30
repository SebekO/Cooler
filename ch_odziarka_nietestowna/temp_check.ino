int temp_chceck()
{
  if (digit1_tmp >= w_temp[0])
  {
    myScreen.text("ERROR TEMP B", 0, 40);
    delay(5000);
    myScreen.background(255, 255, 255);
    return 1;
  }
  else if (digit2_tmp >= w_temp[1])
  {
    myScreen.text("ERROR TEMP R", 0, 40);
    delay(5000);
    myScreen.background(255, 255, 255);
    return 1;
  }
  else if (digit3_tmp >= w_temp[2])
  {
    myScreen.text("ERROR I", 0, 40);
    delay(5000);
    myScreen.background(255, 255, 255);
    return 1;
  }
  else if (digit4_tmp > w_temp[3])
  {
    myScreen.text("ERROR TEMP dP", 0, 40);
    delay(5000);
    myScreen.background(255, 255, 255);
    return 1;
  }
}
