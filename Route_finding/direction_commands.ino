void halt() {
  analogWrite(motor1PWM, 0);
  analogWrite(motor2PWM, 0);
  
  unsigned long int time = millis();
  while ( millis()<time+1000 )
  {
    continue;
  }
  
  return;
}

void Stop() {
  while (true)
  {
    analogWrite(motor1PWM, 0);
    analogWrite(motor2PWM, 0);
  }
}

void forward() {
  digitalWrite(motor1Phase, LOW);     //forward
  analogWrite(motor1PWM, highMotorLeft);  // set speed of motor
  digitalWrite(motor2Phase, LOW);     //forward
  analogWrite(motor2PWM, highMotorRight);  // set speed of motor
}

// Turn left 90deg
void left_turn() {
  // Go forward a bit first
  unsigned long int time = millis();
  while ( (millis()<time+100)  )
  {
    continue;
  }
  digitalWrite(motor1Phase, HIGH); //forward
  analogWrite(motor1PWM, highMotor_turn); // set speed of motor
  digitalWrite(motor2Phase, LOW); // reverse
  analogWrite(motor2PWM, highMotor_turn); // set speed of motor
  time = millis();
  while ( millis()<time+326 )
  {
    continue;
  }
  while (true)
  {
    read_Analog();
    if (AnalogValue[2] < 600)
    {
      break;
    }
  }
}

void right_turn() {
  // Go forward a bit first
  unsigned long int time = millis();
  while ( (millis()<time+100) )
  {
    continue;
  }
  digitalWrite(motor1Phase, LOW); //reverse
  analogWrite(motor1PWM, highMotor_turn); // set speed of motor
  digitalWrite(motor2Phase, HIGH); // forward
  analogWrite(motor2PWM, highMotor_turn); // set speed of motor
  time = millis();
  while ( millis()<time+326 )
  {
    continue;
  }
  while (true)
  {
    read_Analog();
    if (AnalogValue[2] < 600)
    {
      break;
    }
  }
}

//used to curve left with the track
void right() {
  digitalWrite(motor1Phase, LOW);
  analogWrite(motor1PWM, lowMotor_turn);
  digitalWrite(motor2Phase, LOW);
  analogWrite(motor2PWM, highMotor_turn);
}
//used to curve right with the track
void left() {
  digitalWrite(motor1Phase, LOW);
  analogWrite(motor1PWM, highMotor_turn);
  digitalWrite(motor2Phase, LOW);
  analogWrite(motor2PWM, lowMotor_turn);
}


void turn180()
{
  // 750 millis good number for turn
  digitalWrite(motor1Phase, LOW);
  analogWrite(motor1PWM, highMotor_turn); // set speed of motor
  digitalWrite(motor2Phase, HIGH); // forward
  analogWrite(motor2PWM, highMotor_turn); // set speed of motor
  unsigned long time = millis();
  while ( (millis() < time+400) ){
    continue;
  }
  while (true)
  {
    read_Analog();
    if (AnalogValue[2] < 600)
    {
      break;
    }
  }
  
  if (facing == LEFT){
    facing = RIGHT;
  }
  else if (facing == RIGHT){
    facing = LEFT;
  }
}
