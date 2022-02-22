
//calibrate used to find the total value of the analog sensors

int calibrate(){
  read_Analog();
  int AnalogTotal=0;
  AnalogTotal += AnalogValue[0] + AnalogValue[4];
  return AnalogTotal;
}

//sets the calibrated value, with tolerance used to ensure the sensors operate correctly
int calibrate_black_line(){
  calibratedBlack=(calibrate()/2)-100;
}
