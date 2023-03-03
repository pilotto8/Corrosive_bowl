#include "Settings.h"

void setup(){
    pinMode(SERVO,OUTPUT);
    pinMode(DATA,OUTPUT);
    pinMode(CLOCK,OUTPUT);
    pinMode(LATCH,OUTPUT);
    pinMode(LED_PWM,OUTPUT);
    analogWrite(LATCH, LED_INTENSITY);
    oscillator.attach(SERVO);
    //oscillator.write(point_zero);

    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, 1);
    digitalWrite(LATCH, HIGH);
}

void loop(){
    servoHandle();
}