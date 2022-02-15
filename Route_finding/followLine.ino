// used to follow the white line, turning and stopping at stations
void followLine() 
{
  while ( !hitLine )
  {
    read_Analog();
    // If all sensors are active
    if (AnalogValue[0] < calibratedBlack && AnalogValue[1] < calibratedBlack && AnalogValue[2] < calibratedBlack && AnalogValue[3] < calibratedBlack&& AnalogValue[4] < calibratedBlack) 
    {
      if ( ignore_lines < 1 && junction_turn == NULL )
      {
        halt();
        hitLine = TRUE;
        break;
      }
      
      else if ( ignore_lines == 0 && junction_turn == LEFT )
      {
        left_turn();
        junction_turn = NULL;
      }
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
    else if (AnalogValue[1] < calibratedBlack && AnalogValue[3] > calibratedBlack) {
      left();
      left__turn = 1;
    }
    else if (AnalogValue[3] < calibratedBlack && AnalogValue[1] > calibratedBlack) {
      right();
      left__turn = 0;
    }
    
    else if(AnalogValue[3] < calibratedBlack && AnalogValue[4]<calibratedBlack){
      right_turn();
    }
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
