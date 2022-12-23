#include "car.h"

int Controller::getThrottleBtnPin(){
    return this->throttleBtnPin;
}
void Controller::setThrottleBtnPin(int throttleBtnPin){
    this->throttleBtnPin = throttleBtnPin;
    pinMode(this->throttleBtnPin,INPUT_PULLUP);
    return;
}

int Controller::getReverseBtnPin(){
    return this->reverseBtnPin;
}
void Controller::setReverseBtnPin(int reverseBtnPin){
    this->reverseBtnPin = reverseBtnPin;
    pinMode(this->reverseBtnPin,INPUT_PULLUP);
    return;
}

int Controller::getLeftBtnPin(){
    return this->leftBtnPin;
}
void Controller::setLeftBtnPin(int leftBtnPin){
    this->leftBtnPin = leftBtnPin;
    pinMode(this->leftBtnPin,INPUT_PULLUP);
    return;
}

int Controller::getRightBtnPin(){
    return this->rightBtnPin;
}
void Controller::setRightBtnPin(int rightBtnPin){
    this->rightBtnPin = rightBtnPin;
    pinMode(this->rightBtnPin,INPUT_PULLUP);
    return;
}

int Controller::getPotentiometerPin(){
    return this->potentiometerPin;
}
void Controller::setPotentiometerPin(int potentiometerPin){
    this->potentiometerPin = potentiometerPin;
    pinMode(this->potentiometerPin,INPUT);
    return;