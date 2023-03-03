void servoHandle(){
    sin_angle += angular_velocity * (direction ? 1 : -1);
    if (sin_angle >= 3.10){
        direction = 1;
    }
    else if (sin_angle <= 0){
        direction = 0;
    }
    position = sin(sin_angle) * (top_limit - bottom_limit) + bottom_limit;
    oscillator.write(position);
}