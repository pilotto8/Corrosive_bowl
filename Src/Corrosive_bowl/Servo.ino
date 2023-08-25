void servoHandle(){
    if (micros() - previous_mill >= 700){
        previous_mill = micros();
        x_pos += angular_velocity * (direction ? -1 : 1);
        if (x_pos >= X_SUP){
            direction = 1;
        }
        else if (x_pos <= X_INF){
            direction = 0;
        }
        position = (function() + 1) * (top_limit - bottom_limit) / 2 + bottom_limit;
        //Serial.println(position);
        oscillator.write(position);
    }
}

double function(){
    #if FUNCTION == 0
        return (double)cos(x_pos);
    #else if FUNCTION == 1
        if (x_pos < 0){
            return -sqrt(-x_pos);
        }
        return sqrt(x_pos);
    #endif
}