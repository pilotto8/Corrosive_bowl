void servoHandle(){
    x_pos += angular_velocity * (direction ? -1 : 1);
    if (x_pos >= X_SUP){
        direction = 1;
    }
    else if (x_pos <= X_INF){
        direction = 0;
    }
    position = function() * (top_limit - bottom_limit) / 2 + bottom_limit;
    Serial.println(position);
    oscillator.write(position);
}

double function(){
    #if FUNCTION == 0
        return cos(x_pos) + 1;
    #else if FUNCTION == 1
        if (x_pos < 0){
            return -sqrt(-x_pos);
        }
        return sqrt(x_pos);
    #endif
}
/*bool checkZero(){
    if (position * 10 - (position * 10 - (int)(position * 10)) == point_zero * 10){
        return 1;
    }
    return 0;
}*/