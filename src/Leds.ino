void showTime(){
    if ((millis() - start_mill) / 8 != previous_led){
        byte bit_sequence = 0;
        previous_led = (millis() - start_mill) / 8;
        for (byte i; i < 8; i++){
            if (7 - i <= previous_led){
                bit_sequence++;
            }
            bit_sequence <<= 1;
        }
        uploadLeds(bit_sequence);
    }
}

void uploadLeds(byte bit_sequence){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, bit_sequence);
    digitalWrite(LATCH, HIGH);
}