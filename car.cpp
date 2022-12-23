#include "car.h"

Motor *Car::getMotor1(){
    return &this->motor1;
}

Motor *Car::getMotor2(){
    return &this->motor2;
}

int Car::getThrottleStatus(){
    return this->throttleStatus;
}
void Car::setThrottleStatus(int throttleStatus){
    this->throttleStatus = throttleStatus;
    return;
}

int Car::getReverseStatus(){
    return this->reverseStatus;
}
void Car::setReverseStatus(int reverseStatus){
    this->reverseStatus = reverseStatus;
    return;
}

void Car::updateMotorDirection(){
    digitalWrite(this->getMotor1()->getThrottlePin(),this->getThrottleStatus());
    digitalWrite(this->getMotor1()->getReversePin(),this->getReverseStatus());
    digitalWrite(this->getMotor2()->getThrottlePin(),this->getThrottleStatus());
    digitalWrite(this->getMotor2()->getReversePin(),this->getReverseStatus());
    return;
}

void Car::throttle(int speed){
    analogWrite(this->getMotor1()->getEnablePin(),speed);
    analogWrite(this->getMotor2()->getEnablePin(),speed);
  	Serial.println(this->getMotor1()->getEnablePin());  
  	this->setThrottleStatus(HIGH);
    this->setReverseStatus(LOW);
    this->updateMotorDirection();
    return;
}

void Car::reverse(int speed){
    analogWrite(this->getMotor1()->getEnablePin(),speed);
  	analogWrite(this->getMotor2()->getEnablePin(),speed);
    this->setThrottleStatus(LOW);
    this->setReverseStatus(HIGH);
    this->updateMotorDirection();
    return;
}

void Car::turnLeft(int speed){
    analogWrite(this->getMotor1()->getEnablePin(),speed);
  	analogWrite(this->getMotor2()->getEnablePin(),speed*0.4);
    this->setThrottleStatus(HIGH);
    this->setReverseStatus(LOW);
    this->updateMotorDirection();
    return;
}

void Car::turnRight(int speed){
    analogWrite(this->getMotor1()->getEnablePin(),speed*0.4);
  	analogWrite(this->getMotor2()->getEnablePin(),speed);
    this->setThrottleStatus(HIGH);
    this->setReverseStatus(LOW);
    this->updateMotorDirection();
    return;
}

void Car::stop(){
    analogWrite(this->getMotor1()->getEnablePin(),0);
  	analogWrite(this->getMotor2()->getEnablePin(),0);
    this->setThrottleStatus(LOW);
    this->setReverseStatus(LOW);
    this->updateMotorDirection();
    return;
}