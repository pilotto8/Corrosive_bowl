void servoHandle(){
    cos_angle += angular_velocity * (direction ? -1 : 1);
    if (cos_angle >= 3.14){
        direction = 1;
    }
    else if (cos_angle <= 0){
        direction = 0;
    }
    position = (cos(cos_angle) + 1) * (top_limit - bottom_limit) / 2 + bottom_limit;
    Serial.println(position);
    oscillator.write(position);
}

bool checkZero(){
    if (position * 10 - (position * 10 - (int)(position * 10)) == point_zero * 10){
        return 1;
    }
    else {
        return 0;
    }
}