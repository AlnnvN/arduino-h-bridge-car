#include "car.h"

void Motor::setEnablePin(int enablePin){
    this->enablePin = enablePin;
    pinMode(this->enablePin, OUTPUT);
    return;
  }

  int Motor::getEnablePin(){
    Serial.println(this->enablePin);
    return this->enablePin;
  }

  void Motor::setThrottlePin(int throttlePin){
    this->throttlePin = throttlePin;
    pinMode(this->throttlePin, OUTPUT);
    return;
  }
  int Motor::getThrottlePin(){
    return this->throttlePin;  
  }

  void Motor::setReversePin(int reversePin){
    this->reversePin = reversePin;
    pinMode(this->reversePin, OUTPUT);
    return;
  }
  int Motor::getReversePin(){
    return this->reversePin;