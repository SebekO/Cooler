int temp_chceck()
{
  if (digit1_tmp > w_temp[0])
    return 0;
  if (digit2_tmp > w_temp[1])
    //włacz wentylator
    return 0;
  if (digit3_tmp >= w_temp[2])
    return 0;
  if (digit4_tmp > w_temp[3])
    return 0;
  return 1;
}
