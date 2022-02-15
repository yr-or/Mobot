// used to follow the white line, turning and stopping at stations
void followLine() 
{
  while ( !hitLine )
  {
    read_Analog();
    // If all sensors are active
    if (AnalogValue[0] < calibratedBlack && AnalogValue[1] < calibratedBlack && AnalogValue[2] < calibratedBlack && AnalogValue[3] < calibratedBlack&& AnalogValue[4] < calibratedBlack) 
    {
      //if not told to skip a junction and there is no programmed turn 
      if ( ignore_lines < 1 && junction_turn == NULL )
      {
        halt();
        hitLine = TRUE;
        break;
      }
      //if not told to skip a junction and there is a programmed left turn
      else if ( ignore_lines == 0 && junction_turn == LEFT )
      {
        left_turn();
        junction_turn = NULL;
      }
      // if not told to skip a junction and there is a programmed right turn
      else if ( ignore_lines == 0 && junction_turn == RIGHT )
      {
        right_turn();
        junction_turn = NULL;
      }
      else 
      {
        ignore_lines--;
        forward();
        delay(200);
      }
    }
    // Just middle sensor active
    else if (AnalogValue[2] < calibratedBlack){
      forward();
    }
    //middle left sensor active and middle right sensor inactive
    else if (AnalogValue[1] < calibratedBlack && AnalogValue[3] > calibratedBlack) {
      left();
      left__turn = 1;
    }
    // middle right sensor active and middle left sensor inactive
    else if (AnalogValue[3] < calibratedBlack && AnalogValue[1] > calibratedBlack) {
      right();
      left__turn = 0;
    }
    // middle right and rightmost sensors active
    else if(AnalogValue[3] < calibratedBlack && AnalogValue[4]<calibratedBlack){
      right_turn();
    }
    // middle left and leftmost sensors active
    else if(AnalogValue[0] < calibratedBlack && AnalogValue[1]<calibratedBlack){
      left_turn();
    }
    
    // If none are active, curve in opposite direction to previous turn
    else {
      if (left__turn == 1) {
        right();
      }
      else {
        left();
      }
    }
  }
  return;
}
