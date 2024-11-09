// void tuning()
// {
//   Serial.begin(9600);

//   qtr.setTypeAnalog();
//   qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, sensorCount);

//   Serial.println("Start Calibration..");
//   digitalWrite(LED_BUILTIN, HIGH); 
//   for (uint16_t i = 0; i < 400; i++)
//   {
//     qtr.calibrate();
//   }
//   digitalWrite(LED_BUILTIN, LOW);
//   Serial.println("Stop Calibration..");

//   Serial.begin(9600);
//   for (uint8_t i = 0; i < sensorCount; i++)
//   {
//     Serial.print(qtr.calibrationOn.minimum[i]);
//     Serial.print(' ');
//   }
//   Serial.println();

//   // print the calibration maximum values measured when emitters were on
//   for (uint8_t i = 0; i < sensorCount; i++)
//   {
//     Serial.print(qtr.calibrationOn.maximum[i]);
//     Serial.print(' ');
//   }
//   Serial.println();

//   //Calibrate value
//   Serial.println("Threshold Value");
//   for (uint8_t i = 0; i < sensorCount; i++)
//   {
//     Serial.print( (qtr.calibrationOn.maximum[i] + qtr.calibrationOn.minimum[i])/2 );
//     Serial.print(' ');
//   }
//   Serial.println();

//   Serial.println();
//   delay(1000);

// }