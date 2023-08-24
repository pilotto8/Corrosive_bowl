#include "Settings.h"

void setup(){
    pinMode(SERVO,OUTPUT);
    pinMode(DATA,OUTPUT);
    pinMode(CLOCK,OUTPUT);
    pinMode(LATCH,OUTPUT);
    pinMode(BUTTON,INPUT);
    pinMode(BUZZ, OUTPUT);
    oscillator.attach(SERVO);
    oscillator.write(point_zero);

    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, B11000011);
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
            }
            if (buttonTrigg()){
                 state = ready;
                 while((int)(position * 10) != point_zero * 10){servoHandle();}
            }
            break;
        }
        case (finished):{
            if (buttonTrigg()){
                state = ready;
            }
            else if (millis() - alarm_mill > 2000){
              alarm();
              alarm_mill = millis();
            }
            break;
        }
    }
}
