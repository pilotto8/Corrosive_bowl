void showTime(){
    if ((millis() - start_mill) / (TIMEOUT / 8) != previous_led){
        byte bit_sequence = 0;
        previous_led = (millis() - start_mill) / (TIMEOUT / 8);
        for (byte i; i < 8; i++){
          bit_sequence <<= 1;
            if (i <= 7 - previous_led){
                bit_sequence++;
            }
        }
        uploadLeds(bit_sequence);
    }
}

void uploadLeds(byte bit_sequence){
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, bit_sequence);
    digitalWrite(LATCH, HIGH);
}

void waveLeds(){
    byte bit_sequence = B10000000;
    for (byte i = 0; i < 8; i++, bit_sequence >>= 1){
        uploadLeds(bit_sequence);
        delay(30);
    }
    bit_sequence = B00000001;
    for (byte i = 0; i < 9; i++, bit_sequence <<= 1){
        uploadLeds(bit_sequence);
        delay(30);
    }
}