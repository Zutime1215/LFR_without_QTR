void readSensor() {
  sensor = 0;
  detectedSensor = 0;
  int sum = 0;

  for(int i=0; i<sensorCount; i++) {
    s[i] = analogRead(i);
    ( s[i] > threshold ) ? s[i] = 0 : s[i] = 1; 
    sum  += (s[i]*sensorPosition[i]);
    detectedSensor += s[i];
  }
  if(detectedSensor) {
    position = (sum*1.0)/(detectedSensor*1.0);
  }

// Print the s Array. s[0] = most left. s[5] = most right 
  // for (int i=0;i<6;i++) {
  //   Serial.print(s[i]);
  //   Serial.print(" ");
  // }
  // delay(100);
  // Serial.println();
}
