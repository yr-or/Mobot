//calibrate used to find the total value of the analog sensors
int calibrate(){
  read_Analog();
  int AnalogTotal=0;
  for(int i = 0; i<5; i++){
    AnalogTotal+=AnalogValue[i];
  }
  return AnalogTotal;
}
//sets the calibrated value, with tolerance used to ensure the sensors operate correctly
void calibrate_black_line(){
  calibratedBlack=(calibrate()/5)-100;
}
