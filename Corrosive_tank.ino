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
    switch (state){
        case (ready):{
            if (checkZero() == 0){
                if (position < 50 && direction == 0){
                    direction = 1;
                }
                else if (position > 50 && direction == 1){
                    direction = 0;
                }
                servoHandle();
            }
            while (!digitalRead(BUTTON)){
                start_mill = millis();
                state = running;
                Serial.println("Starting");
            }
            break;
        }
        case (running):{
            servoHandle();
            if (checkZero() && millis() - start_mill >= TIMEOUT){
                state = finished;
            }
            break;
        }
        case (finished):{
            while (!digitalRead(BUTTON)){
                state = ready;
            }
            break;
        }
    }
}