void checkButton(){
    if (!digitalRead(BUTTON)){
        if (mill() - button_mill >= 30){
            if (!button_state){
                button_state = 1;
                button_pulse = 1;
            }
        }
    }
    else {
        button_mill = millis();
        if (button_state){
            button_state = 0;
            button_pulse = 0;
        }
    }
}

bool buttonTrigg(){
    if (button_pulse){
        button_pulse = 0;
        return true;
    }
    return false;
}