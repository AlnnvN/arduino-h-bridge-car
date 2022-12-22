#include "car.h"

Car car;
int speed;

int throttleBtnPin = A0;
int reverseBtnPin = A1;
int leftBtnPin = A2;
int rightBtnPin = A3;
int potentiometerPin = A4;

void setup()
{
  //Serial.begin(9600);
  
  //PINS SETUP
  //H-bridge
  car.getMotor1().setEnablePin(5);
  car.getMotor1().setThrottlePin(6);
  car.getMotor1().setReversePin(7);
  
  car.getMotor2().setEnablePin(11);
  car.getMotor2().setThrottlePin(12);
  car.getMotor2().setReversePin(13);
  
  //Controller
  pinMode(throttleBtnPin,INPUT_PULLUP);
  pinMode(reverseBtnPin,INPUT_PULLUP);
  pinMode(leftBtnPin,INPUT_PULLUP);
  pinMode(rightBtnPin,INPUT_PULLUP);
  pinMode(potentiometerPin,INPUT);
}

void loop()
{
  //SPEED INTENSITY
  //uses a potentiometer for intensity input
  speed = map(analogRead(potentiometerPin),0,1023,0,255); //used to analogWrite
  
  //CHECKS FOR BUTTON INPUT FOR ANALOG UPDATE
  //pins set for INPUT_PULLUP - if it reads 0, it's pressed.
  if(analogRead(throttleBtnPin)<200){ //throttle input
    car.throttle(speed);
  }
  else if(analogRead(reverseBtnPin)<200){ //reverse input
  	car.reverse(speed);
  }
  else if(analogRead(leftBtnPin)<200){ //left input
  	car.turnLeft(speed);
  }
  else if(analogRead(rightBtnPin)<200){ //right input,
  	car.turnRight(speed);
  }
  else{
    car.stop();
  }

  delay(100);
}