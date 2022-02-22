//  waits at a line for a new instruction
void halt() {
  forward();
  delay(100);
  analogWrite(motor1PWM, 0);
  analogWrite(motor2PWM, 0);
  
  unsigned long int time = millis();
  while ( millis()<time+1000 )
  {
    continue;
  }
  
  return;
}
//at the wall stop the motors 
void Stop() {
  while (true)
  {
    analogWrite(motor1PWM, 0);
    analogWrite(motor2PWM, 0);
  }
}
// move forwards
void forward() {
  digitalWrite(motor1Phase, LOW);           //forward
  analogWrite(motor1PWM, highMotorLeft);    // set speed of motor
  digitalWrite(motor2Phase, LOW);           //forward
  analogWrite(motor2PWM, highMotorRight);   // set speed of motor
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
    if (AnalogValue[2] < calibratedBlack)
    {
      break;
    }
  }
}
//turn right 90 degrees
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
    if (AnalogValue[2] < calibratedBlack)
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

//turn 180 degrees on the spot
void turn180()
{
  // 750 millis good number for turn
  digitalWrite(motor1Phase, LOW);
  analogWrite(motor1PWM, highMotor_turn); // set speed of motor
  digitalWrite(motor2Phase, HIGH); // forward
  analogWrite(motor2PWM, highMotor_turn); // set speed of motor
  unsigned long time = millis();
  // turn for 600 millis
  while ( (millis() < time+600) ){
    continue;
  }
  while (true)
  {
    read_Analog();
    if (AnalogValue[2] < calibratedBlack)
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
