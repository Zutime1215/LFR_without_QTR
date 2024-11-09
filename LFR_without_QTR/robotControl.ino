void robotControl() {
  readSensor();

  if (detectedSensor == 0) {
    if (turn != 's') {
      if (turn == 'r') {
        Move(turnSpeed, -turnSpeed);
      } else {
        Move(-turnSpeed, turnSpeed);
      }
      while (!s[2] && !s[3]) { readSensor(); }
      turn = 's';
    }
  }

  else if ( (detectedSensor == 1 || detectedSensor == 2) && (s[2] || s[3]) ) {
    int err = 2500 - position;
    PIDcontrol(err);
  }

  else if (detectedSensor >= 3 && detectedSensor <= 5) {
    if ( (s[2]+s[3]) && !s[0] && s[5] ) { turn = 'r'; }
    if ( (s[2]+s[3]) && s[0] && !s[5] ) { turn = 'l'; }
  }

  else if (detectedSensor == 6) {
    delay(200);
    readSensor();
    if (detectedSensor == 6) {
      Move(0, 0);
      while (detectedSensor == 6) readSensor(); 
    }

    else if (detectedSensor == 0) {
      turn = 'r';
    }
  }
}

void PIDcontrol(int error) {
  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  motorSpeed = P*Kp + I*Ki + D*Kd;
   
  motorSpeedLeft = baseSpeedLeft + motorSpeed;
  motorSpeedRight = baseSpeedRight - motorSpeed;

  // Serial.print(motorSpeedLeft);
  // Serial.print(" ");
  // Serial.print(motorSpeedRight);
  // Serial.println();

  Move(motorSpeedLeft, motorSpeedRight);  
}
