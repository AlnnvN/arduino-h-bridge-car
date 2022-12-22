#ifndef CAR_H
#define CAR_H
#include "Arduino.h"

class Motor{
  int enablePin;
  int throttlePin;
  int reversePin;

  public:
  void setEnablePin(int enablePin);
  int getEnablePin();

  void setThrottlePin(int throttlePin);
  int getThrottlePin();

  void setReversePin(int reversePin);
  int getReversePin();
};

class Car{
  int throttleStatus;
  int reverseStatus;

  Motor motor1;
  Motor motor2;

  public:
  void throttle(int speed);
  void reverse(int speed);
  void turnLeft(int speed); 
  void turnRight(int speed);
  void stop();
  void updateMotorDirection();

  int getThrottleStatus();
  void setThrottleStatus(int throttleStatus);

  int getReverseStatus();
  void setReverseStatus(int reverseStatus);
  
  Motor getMotor1();
  Motor getMotor2();
};

class Controller{
  int throttleBtnPin;
  int reverseBtnPin;
  int leftBtnPin;
  int rightBtnPin;
  int potentiometerPin;

  public:
  
  int getThrottleBtnPin();
  void setThrottleBtnPin(int throttleBtnPin);

  int getReverseBtnPin();
  void setReverseBtnPin(int reverseBtnPin);

  int getLeftBtnPin();
  void setLeftBtnPin(int leftBtnPin);

  int getRightBtnPin();
  void setRightBtnPin(int rightBtnPin);

  int getPotentiometerPin();
  void setPotentiometerPin(int potentiometerPin);
};

#endif