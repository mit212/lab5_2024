#include "pinout.h"
#include <Arduino.h> 

// https://www.adafruit.com/product/367
// https://learn.adafruit.com/adafruit-arduino-lesson-6-digital-inputs?view=all#arduino-code

# define PRINT_DELAY 50

void setup() {
    Serial.begin();
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(BUTTON_PIN) == LOW) {
        Serial.println("LOW (pressed)");
    }
    else {
        Serial.println("HIGH (not pressed)");
    }
    delay(PRINT_DELAY);
}