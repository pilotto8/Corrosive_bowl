#include <Servo.h>
Servo oscillator;
#define LED_INTENSITY 200

//PIN
#define LED_PWM 2
#define DATA 6
#define CLOCK 5
#define LATCH 4
#define SERVO 9
#define BUTTON 2

//Servo
#define point_zero 65
#define max_angle 30
const byte bottom_limit = point_zero - max_angle;
const byte top_limit = point_zero + max_angle;
#define angular_velocity 0.002
bool direction;
double cos_angle = 1.57;
double position = point_zero + 10;

//Main
 byte state = 0;
 enum states{
    ready,
    running,
    finished
 };


 //Timer
 #define TIMEOUT 10000
 unsigned long int start_mill = 0;