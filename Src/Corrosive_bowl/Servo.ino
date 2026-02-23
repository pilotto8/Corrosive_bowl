void servoHandle() {
  if (micros() - previous_mill >= 700) {
    previous_mill = micros();
    x_pos += angular_velocity * (direction ? -1.0 : 1.0);
    if (x_pos >= X_SUP) {
      direction = 1;
    } else if (x_pos <= X_INF) {
      direction = 0;
    }
    position = function(x_pos) * (double)(top_limit - bottom_limit) / 2.0 + (double)bottom_limit;
    //Serial.println(position);
    oscillator.write((int)position);
  }
}

double function(double x) {
#if FUNCTION == 0
  return (double)cos(x) + 1.0;
#elif FUNCTION == 1
  if (x_pos < 0) {
    return -sqrt(-x) + 1.0;
  }
  return sqrt(x) + 1.0;
#elif FUNCTION == 2
 return x;
#endif
}