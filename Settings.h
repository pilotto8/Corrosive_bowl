#include <Servo.h>
Servo oscillator;
#define LED_INTENSITY 200

//PIN
#define LED_PWM 2
#define DATA 6
#define CLOCK 5
#define LATCH 4
#define SERVO 9

//Servo
#define point_zero 82
#define max_angle 15
const byte bottom_limit = point_zero - max_angle;
const byte top_limit = point_zero + max_angle;
#define angular_velocity 0.0005
bool direction;
double sin_angle = 1.57;
double position = 1.0;