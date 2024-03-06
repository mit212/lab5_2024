#include <Arduino.h>
#include "pinout.h"
#include "MotorDriver.h"

#define DELAY 200 // Delay between motor movements in milliseconds

// Create an instance of the MotorDriver class
MotorDriver motor2(DIR2, PWM2, 0);
double potReading;
double potReadingScaled;
double maxPotReading = 4095.0;

void setup() {
    // Initialize serial communication
    Serial.begin();

    // Setup the motor driver
    motor2.setup();

    // Setup pot
    pinMode(POT_PIN, INPUT);
}

void loop() {
    // TODO: Change this code such that uses another sensor instead of potentiometers
    potReading = analogRead(POT_PIN);
    potReadingScaled = potReading/maxPotReading;
    motor2.drive(potReadingScaled);

    delay(DELAY);
}