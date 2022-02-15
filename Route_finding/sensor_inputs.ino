//reads the analog input of the sensors and saves their state
void read_Analog()
{
  int i;
  for (i=0; i<5; i++)
  {
    AnalogValue[i] = analogRead(AnalogPin[i]);
  }
}

int readDistanceSensor()
{
  return analogRead( distanceSensorPin );
}
