void readSensor() 
{
  sensor = 0;
  detectedSensor = 0;
  int sum = 0;

  for(int i=0; i<sensorCount; i++) 
  {
    s[i] = analogRead(i);
    ( s[i] > threshold[i] ) ? s[i] = 1 : s[i] = 0; 
    sum  += (s[i]*sensorPosition[i]);
    // sensor +=  (s[i]*base[i]);
    detectedSensor += s[i];
  }
  if(detectedSensor)
    position = (sum*1.0)/(detectedSensor*1.0);
    //Serial.println(position);
}
