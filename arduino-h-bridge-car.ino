#include "car.h"

Controller controller;

Car car;
int speed;

void setup()
{
  //Serial.begin(9600);
  
  //PINS SETUP
  //H-bridge
  car.getMotor1().setEnablePin(5); //PWM, Analog Output - H-brige, Activate 1 & 2 (1st motor, both ways)
  car.getMotor1().setThrottlePin(6); //Digital Output - H-bridge, Input 1 
  car.getMotor1().setReversePin(7); //Digital Output - H-bridge, Input 2 
  
  car.getMotor2().setEnablePin(11); //PWM, Analog Output - H-brige, Activate 3 & 4 (2nd motor, both ways)
  car.getMotor2().setThrottlePin(12); //Digital Output - H-bridge, Input 3
  car.getMotor2().setReversePin(13); //Digital Output - H-bridge, Input 4
  
  //Controller - Analog Input
  controller.setThrottleBtnPin(A0); //INPUT_PULLUP
  controller.setReverseBtnPin(A1); //INPUT_PULLUP
  controller.setLeftBtnPin(A2); //INPUT_PULLUP
  controller.setRightBtnPin(A3); //INPUT_PULLUP
  controller.setPotentiometerPin(A4);

}

void loop()
{
  //SPEED INTENSITY
  //uses a potentiometer for intensity input
  speed = map(analogRead(controller.getPotentiometerPin()),0,1023,0,255); //used for analogWrite
  
  //CHECKS FOR BUTTON INPUT FOR ANALOG UPDATE
  //pins set for INPUT_PULLUP - if it reads 0, it's pressed.
  if(analogRead(controller.getThrottleBtnPin())<200){ //Checks for throttle input
    car.throttle(speed);
  }
  else if(analogRead(controller.getReverseBtnPin())<200){ //Checks for reverse input
  	car.reverse(speed);
  }
  else if(analogRead(controller.getLeftBtnPin())<200){ //Checks for left input
  	car.turnLeft(speed);
  }
  else if(analogRead(controller.getRightBtnPin())<200){ //Checks for right input
  	car.turnRight(speed);
  }
  else{
    car.stop();
  }

  delay(100);
}