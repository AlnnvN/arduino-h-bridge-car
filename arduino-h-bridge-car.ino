#include "car.h"

Controller controller;

Car car;
int speed;

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
  controller.setThrottleBtnPin(A0);
  controller.setReverseBtnPin(A1);
  controller.setLeftBtnPin(A2);
  controller.setRightBtnPin(A3);
  controller.setPotentiometerPin(A4);

}

void loop()
{
  //SPEED INTENSITY
  //uses a potentiometer for intensity input
  speed = map(analogRead(controller.getPotentiometerPin()),0,1023,0,255); //used for analogWrite
  
  //CHECKS FOR BUTTON INPUT FOR ANALOG UPDATE
  //pins set for INPUT_PULLUP - if it reads 0, it's pressed.
  if(analogRead(controller.getThrottleBtnPin())<200){ //throttle input
    car.throttle(speed);
  }
  else if(analogRead(controller.getReverseBtnPin())<200){ //reverse input
  	car.reverse(speed);
  }
  else if(analogRead(controller.getLeftBtnPin())<200){ //left input
  	car.turnLeft(speed);
  }
  else if(analogRead(controller.getRightBtnPin())<200){ //right input
  	car.turnRight(speed);
  }
  else{
    car.stop();
  }

  delay(100);
}