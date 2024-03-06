#include "pinout.h"
#include <Arduino.h> 

// https://www.adafruit.com/product/1789
// https://learn.adafruit.com/make-it-change-potentiometers/arduino

# define PRINT_DELAY 50

void setup() {
    Serial.begin();
    pinMode(POT_PIN, INPUT);
}

void loop() {
    Serial.println(analogRead(POT_PIN));
    delay(PRINT_DELAY);
}