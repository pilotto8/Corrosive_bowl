#include "Settings.h"

void setup(){
    pinMode(SERVO,OUTPUT);
    pinMode(DATA,OUTPUT);
    pinMode(CLOCK,OUTPUT);
    pinMode(LATCH,OUTPUT);
    pinMode(LED_PWM,OUTPUT);
    pinMode(BUTTON,INPUT_PULLUP);
    analogWrite(LATCH, LED_INTENSITY);
    oscillator.attach(SERVO);
    //oscillator.write(point_zero);

    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, 1);
    digitalWrite(LATCH, HIGH);

    Serial.begin(115200);
}

void loop(){
    checkButton();
    switch (state){
        case (ready):{
            if ((int)(position * 10) != point_zero * 10){
                if (position < point_zero && direction == 0){
                    direction = 1;
                }
                else if (position > point_zero && direction == 1){
                    direction = 0;
                }
                servoHandle();
            }
            if (buttonTrigg()){
                start_mill = millis();
                state = running;
            }
            break;
        }
        case (running):{
            servoHandle();
            showTime();
            if ((int)(position * 10) == point_zero * 10){
                if (millis() - start_mill >= TIMEOUT){
                    state = finished;
                }
                else if (buttonTrigg()){
                    state = ready;
                }
            }
            break;
        }
        case (finished):{
            if (buttonTrigg()){
                state = ready;
            }
            break;
        }
    }
}