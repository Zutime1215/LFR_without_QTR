void robotControl()
{
  readSensor();

  int err = 2500 - position;
  // Serial.println(err);
  // if(err == 0)
  //     Move(baseSpeedLeft, baseSpeedRight);
  // else if(err == -500 || err == -1500 || err == -2500)
  //   Move(turnSpeed, -turnSpeed);
  // else if(err == 500 || err == 1500 || err == 2500)
  //   Move(-turnSpeed, turnSpeed);


  PIDcontrol(err);
}

void PIDcontrol(int error) 
{
  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  int motorSpeed = P*Kp + I*Ki + D*Kd;
  
  int motorSpeedLeft, motorSpeedRight; 
  motorSpeedLeft = baseSpeedLeft + motorSpeed;
  motorSpeedRight = baseSpeedRight - motorSpeed;
  
  Move(motorSpeedLeft, motorSpeedRight);  
}
