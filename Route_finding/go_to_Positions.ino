void gotoPosition()
{
  switch ( position )
  {
    case 0:
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
