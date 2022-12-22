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

#endif