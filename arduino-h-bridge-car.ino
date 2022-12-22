#include "car.h"

Motor motor1;
Motor motor2;
int throttleStatus;
int reverseStatus;

int throttleBtnPin = A0;
int reverseBtnPin = A1;
int leftBtnPin = A2;
int rightBtnPin = A3;
int potenciometroPin = A4;

void setup()
{
  //Serial.begin(9600);
  
  motor1.setEnablePin(5);
  motor1.setThrottlePin(6);
  motor1.setReversePin(7);
  
  motor2.setEnablePin(11);
  motor2.setThrottlePin(12);
  motor2.setReversePin(13);
  
  pinMode(throttleBtnPin,INPUT_PULLUP);
  pinMode(reverseBtnPin,INPUT_PULLUP);
  pinMode(leftBtnPin,INPUT_PULLUP);
  pinMode(rightBtnPin,INPUT_PULLUP);
  pinMode(potenciometroPin,INPUT);
}

int potenciometro;

void loop()
{
  potenciometro = analogRead(potenciometroPin);
  int carPower = map(potenciometro,0,1023,0,255);
  
  if(analogRead(throttleBtnPin)<200){//throttle
    analogWrite(motor1.getEnablePin(),carPower);
    analogWrite(motor2.getEnablePin(),carPower);
    throttleStatus = HIGH;
    reverseStatus = LOW;
  }
  else if(analogRead(reverseBtnPin)<200){//reverse
  	analogWrite(motor1.getEnablePin(),carPower);
  	analogWrite(motor2.getEnablePin(),carPower);
    reverseStatus = HIGH;
    throttleStatus = LOW;
  }
  else if(analogRead(leftBtnPin)<200){//left
  	analogWrite(motor1.getEnablePin(),carPower);
  	analogWrite(motor2.getEnablePin(),carPower*0.4);
    throttleStatus = HIGH;
    reverseStatus = LOW;
  }
  else if(analogRead(rightBtnPin)<200){//right
  	analogWrite(motor1.getEnablePin(),carPower*0.4);
  	analogWrite(motor2.getEnablePin(),carPower);
    throttleStatus = HIGH;
    reverseStatus = LOW;
  }
  else{//stop
    analogWrite(motor1.getEnablePin(),0);
  	analogWrite(motor2.getEnablePin(),0);
  	throttleStatus = LOW;
    reverseStatus = LOW;
  }
  //Serial.println(carPower);
  digitalWrite(motor1.getThrottlePin(),throttleStatus);
  digitalWrite(motor1.getReversePin(),reverseStatus);
  digitalWrite(motor2.getThrottlePin(),throttleStatus);
  digitalWrite(motor2.getReversePin(),reverseStatus);
  
  delay(100);
}