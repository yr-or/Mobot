void gotoPosition()
{
  // position refers to current position
  switch ( position )
  {
    case 0:
    //check if the programmed path requires a 180 degree turn in order to execute correctly
    //based on the current direction the mobot is facing
      if ( (destination == 1 || destination == 2 || destination == 3) && facing == LEFT  ) { turn180(); }
      else if ( destination == 4 && facing == RIGHT ) { turn180(); }
      switch ( destination )
      {
        case 1:
          ignore_lines = 1;
          junction_turn = LEFT;
          followLine();
          facing = LEFT;
          break;
        case 2:
          ignore_lines = 2;
          followLine();
          facing = LEFT;
          break;
        case 3:
          ignore_lines=3;
          followLine();
          facing = LEFT;
          break;
        case 4:
          ignore_lines = 0;
          followLine();
          facing = LEFT;
          break;
        case 5:
          int end_destination = destination;
          destination = 1;
          gotoPosition();
          destination = end_destination;
          goToFive();
          break;
      }
      break;

    case 1:
      if ( (destination == 0 || destination == 2) && facing == LEFT ) { turn180();}
      else if ( (destination == 3 || destination == 4 || destination == 5) && facing == RIGHT ) { turn180(); }
      switch ( destination )
      {
        case 0:
          junction_turn = RIGHT;
          followLine();
          facing = LEFT;
          break;
        case 2:
          junction_turn = LEFT;
          followLine();
          facing = LEFT;
          break;
        case 3:
          junction_turn = RIGHT;
          followLine();
          facing = RIGHT;
          break;
        case 4:
          junction_turn = LEFT;
          followLine();
          facing = RIGHT;
          break;
        case 5:
          goToFive();
      }
      break;

    case 2:
      if ( (destination == 1 || destination == 4 || destination == 0) && facing == LEFT ) { turn180(); }
      else if ( destination == 3 && facing == RIGHT ) { turn180(); }
      switch ( destination )
      {
        case 0:
          ignore_lines = 1; 
          followLine();
          facing = LEFT;
          break;
        case 1:
          junction_turn = RIGHT;
          followLine();
          facing = LEFT;
          break;
        case 3:
          followLine();
          facing = LEFT;
          break;
        case 4:
          ignore_lines = 2; 
          followLine();
          facing = LEFT;
          break;
        case 5:
          int end_destination = destination;
          destination = 1;
          gotoPosition();
          destination = end_destination;
          goToFive();
          break;
      }
      break;

      case 3:
        if ( destination == 4 && facing == RIGHT ) { turn180(); }
        else if ( (destination == 2 || destination == 1 || destination == 0) && facing == LEFT ) { turn180(); }
        switch ( destination )
        {
          case 0:
            ignore_lines = 2; 
            followLine();
            facing = LEFT;
            break;
          case 1:
            junction_turn = RIGHT;
            ignore_lines = 1; 
            followLine();
            facing = LEFT;
            break;
          case 2:
            followLine();
            facing = RIGHT;
            break;
          case 4:
            ignore_lines = 1; 
            followLine();
            facing = RIGHT;
            break;
          case 5:
            int end_destination = destination;
            destination = 1;
            gotoPosition();
            destination = end_destination;
            goToFive();
            break;
        }
        break;

      case 4:
        if ( destination == 3 && facing == RIGHT ) { turn180(); }
        else if ( (destination == 2 || destination == 1 || destination == 0) && facing == LEFT ) { turn180(); }
        switch ( destination )
        {
          case 0:
            followLine();
            facing = RIGHT;
            break;
          case 1:
            junction_turn=LEFT;
            ignore_lines=1;
            followLine();
            facing = LEFT;
            break;
          case 2:
            ignore_lines=2;
            followLine();
            facing = LEFT;
            break;
          case 3:
            ignore_lines=1;
            followLine();
            facing = RIGHT;
            break;
          case 5:
            int end_destination = destination;
            destination = 1;
            gotoPosition();
            destination = end_destination;
            goToFive();
            break;
        }
        break;
  }
}

void goToFive()
{
  while(!hitLine){
 if (AnalogValue[0] < calibratedBlack && AnalogValue[1] < calibratedBlack && AnalogValue[2] < calibratedBlack && AnalogValue[3] < calibratedBlack&& AnalogValue[4] < calibratedBlack) 
    {
     hitLine=true;
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
 while (true)
  {
    if (i > 5)
    {
      i = 0;
    }
    i++;
    int val = readDistanceSensor();
    sensorArray[i] = val;
  
    total = 0;
    for (int j=0; j<5; j++)
    {
      total += sensorArray[j];
    }
    
    if ( total > 3000 )
    {
      Stop();
    }
    else
    {
      forward();
    }
  }
}
