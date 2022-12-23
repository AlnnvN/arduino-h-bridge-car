# arduino-h-bridge-car
Prototype of a small car based on Arduino using an H-bridge circuit

![image](https://user-images.githubusercontent.com/108158031/209056017-cb77dc8e-21b0-4d8d-98eb-ebe480b516d1.png)

It expects the following Arduino pin schema:

Digital (H-bridge):

5 - PWM, Analog Output - H-brige, Activate 1 & 2 (intensity of 1st motor, both ways)
6 - Digital Output - H-bridge, Input 1 (Throttle)
7 - Digital Output - H-bridge, Input 2 (Reverse)

11 - PWM, Analog Output - H-brige, Activate 3 & 4 (intensity of 2nd motor, both ways)
12 - Digital Output - H-bridge, Input 3 (Throttle)
13 - Digital Output - H-bridge, Input 4 (Reverse)


Analog:

(Controller input - it's now using 4 buttons to control directions, but the input method can be exchanged)

Pins are set for INPUT_PULLUP - if it reads 0, it's pressed.

A0 - Throttle Button
A1 - Reverse Button
A2 - Turn Left Button
A3 - Turn Right Button
A4 - Potentiometer - set for normal INPUT (sets the car speed)


All the pin modes can be changed in in their respective class methods
