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
#define X_INF 0.0
#define X_SUP 3.14
#else if (FUNCTION == 1 || FUNCTION == 2)
#define X_INF -1.0
#define X_SUP 1.0
#endif

#define point_zero 6
#define max_angle 9
const int bottom_limit = point_zero - max_angle;
const int top_limit = point_zero + max_angle;
#define angular_velocity 0.008
bool direction;
double x_pos = (X_SUP - X_INF) / 2.0;
double position = point_zero + 10.0;

//Main
byte state = 0;
enum states{
   ready,
   running,
   paused,
   finished
};


//Timer
#define TIMEOUT 600000
unsigned long int start_mill;
byte previous_led;
unsigned long int previous_mill;
unsigned long int paused_mill;


//Button
bool button_state = 0;
bool button_pulse = 0;
unsigned long int button_mill;

//Buzzer
unsigned long int alarm_mill;
