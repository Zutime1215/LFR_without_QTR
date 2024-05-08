#include <QTRSensors.h>
QTRSensors qtr; 
const uint8_t sensorCount = 6;
uint16_t sensorValues[sensorCount];

int threshold[] = {850, 850, 850, 850, 850, 850};
// int base[] = {1, 2, 4, 8, 16, 32};
int sensorPosition[] = {0, 1000, 2000, 3000, 4000, 5000};

float Kp = 1; 
float Kd = 0;
float Ki = 0;
float P=0;
float I=0;
float D=0;

int sensor, detectedSensor, s[6];
float position=0;
int lastError = 0;
char turn = 's';

const uint8_t maxSpeedLeft = 150;
const uint8_t maxSpeedRight = 150;
const uint8_t baseSpeedLeft = 100;
const uint8_t baseSpeedRight = 100;
int turnSpeed = 150;

int leftForward = 5;  //INB
int leftBackward = 4; //INA
int rightForward = 6;  //INC
int rightBackward = 7;  //IND
int leftSpeedPin = 10;
int rightSpeedPin = 11;
int switchPin = 9;

bool onoff = false;
bool firstTime = true;

void setup() 
{
  Serial.begin(9600);
  pinMode(switchPin, INPUT);

  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);

  pinMode(13, OUTPUT);
  delay(1000);
}



void loop() {
  if (Serial.available())
  {
    while(Serial.available() == 0);
    valueRead();
  }
  if (onoff == true)  
  {
    robotControl();
  }
  else if(onoff == false)
  {
    Move(0,0);
  }

  // robotControl();
  // Move(200, 200);
}