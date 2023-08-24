#include <Servo.h>
Servo oscillator;
#define LED_INTENSITY 200

//PIN
#define DATA 6
#define CLOCK 5
#define LATCH 4
#define SERVO 9
#define BUTTON 2
#define BUZZ 3
#define OE 10

//Servo
#define FUNCTION 0

#if FUNCTION == 0
#define X_INF 0
#define X_SUP 3.14
#else if FUNCTION == 1
#define X_INF -1
#define X_SUP 1
#endif

#define point_zero 65
#define max_angle 7
const byte bottom_limit = point_zero - max_angle;
const byte top_limit = point_zero + max_angle;
#define angular_velocity 0.007
bool direction;
double x_pos = (X_SUP - X_INF) /2;
double position = point_zero + 10;

//Main
byte state = 0;
enum states{
   ready,
   running,
   finished
};


//Timer
#define TIMEOUT 600000
unsigned long int start_mill;
byte previous_led;
unsigned long int previous_mill;


//Button
bool button_state = 0;
bool button_pulse = 0;
unsigned long int button_mill;

//Buzzer
unsigned long int alarm_mill;
