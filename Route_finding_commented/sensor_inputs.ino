
//reads the analog input of the sensors and saves their state
void read_Analog()
{
  int i;
  for (i=0; i<5; i++)
  {
    
    int total = 0;
    for (int j=0; j<5; j++) {
      total += analogRead(AnalogPin[i]);
    }
      AnalogValue[i] = total / 5;
      
      //AnalogValue[i] = analogRead(AnalogPin[i]);
  }
  
  
}

int readDistanceSensor()
{
  return analogRead( distanceSensorPin );
}
