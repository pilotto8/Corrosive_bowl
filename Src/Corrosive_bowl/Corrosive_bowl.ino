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
    
    waveLeds();

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
                uploadLeds(B11111111);
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
                while((int)(position * 10) != point_zero * 10){servoHandle();}
                paused_mill = millis();
                state = paused;
            }
            break;
        }
        case (paused):{
            if (buttonTrigg()){
                start_mill += millis() - paused_mill;
                state = running;
            }
            else if (millis() - button_mill >= 500){
                uploadLeds(B00000000);
                alarm();
                state = ready;
            }
            break;
        }
        case (finished):{
            if (buttonTrigg()){
                uploadLeds(B00000000);
                state = ready;
            }
            else if (millis() - alarm_mill > 2000){
                alarm();
                alarm_mill = millis();
                uploadLeds(B00000000);
                previous_led = B00000000;
            }
            else if (millis() - alarm_mill > 1000 && previous_led == 0){
                uploadLeds(B11111111);
                previous_led = B11111111;
            }
            break;
        }
    }
}