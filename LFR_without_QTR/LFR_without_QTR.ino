// #include <QTRSensors.h>
// QTRSensors qtr; 

const uint8_t sensorCount = 6;

// int threshold[] = {600, 600, 600, 600, 600, 600};
int threshold = 550;
int sensorPosition[] = {0, 1000, 2000, 3000, 4000, 5000};

float Kp = 0.7, Kd = 0, Ki = 0; 
float P=0, I=0, D=0;

int sensor, detectedSensor, s[6];
float position=0;
int lastError = 0;
char turn = 's';

int motorSpeedLeft, motorSpeedRight;
int motorSpeed;

const uint8_t maxSpeedLeft = 180;
const uint8_t maxSpeedRight = 180;
const uint8_t baseSpeedLeft = 100;
const uint8_t baseSpeedRight = 100;
int turnSpeed = 130;

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
  // if (Serial.available())
  // {
  //   while(Serial.available() == 0);
  //   valueRead();
  // }
  // if (onoff == true)  
  // {
  //   robotControl();
  // }
  // else if(onoff == false)
  // {
  //   Move(0,0);
  // }


  // readSensor();

  robotControl();
}