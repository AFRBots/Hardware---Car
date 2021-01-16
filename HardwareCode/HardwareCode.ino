#include <QMC5883LCompass.h>

//wheels pins forward,backward pair must be oposites(high/low)
const int rightForward = 5;
const int leftForward = 9;
const int rightBack = 4;
const int leftBack = 10;

//proximity sensor
const int trigPin = 12;
const int echoPin = 13;

//compass
QMC5883LCompass compass;

//*********Main************************************************************************************************
void setup() {
  //bluetooth
  Serial.begin(9600);
  //wheels
  pinMode(rightForward, OUTPUT);
  pinMode(rightBack, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBack, OUTPUT);
  //proximity sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //compass
  compass.init();
}

void loop() {

    compass.read();
    
    Serial.println(compass.getAzimuth());
    delay(500);

}
//***Movement***************************************************************************************************
void moveForward(){
  digitalWrite(rightForward, HIGH);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightBack, LOW);
  digitalWrite(leftBack, LOW);
}
void moveBack(){
  digitalWrite(rightForward, LOW);
  digitalWrite(leftForward, LOW);
  digitalWrite(rightBack, HIGH);
  digitalWrite(leftBack, HIGH);
}
void moveRight(){
  digitalWrite(rightForward, LOW);
  digitalWrite(leftForward, HIGH);
  digitalWrite(rightBack, HIGH);
  digitalWrite(leftBack, LOW);
}
void moveLeft(){
  digitalWrite(rightForward, HIGH);
  digitalWrite(leftForward, LOW);
  digitalWrite(rightBack, LOW);
  digitalWrite(leftBack, HIGH);
}
//************Proximity*******************************************************************************************
int getDistance(){
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int duration = pulseIn(echoPin, HIGH);
  return (duration * 0.034 / 2);
}
