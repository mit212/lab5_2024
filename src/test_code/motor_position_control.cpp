#include <Arduino.h>
#include "PID.h"
#include "SimpleFilters.h"
#include "EncoderVelocity.h"
#include "pinout.h"
#include "util.h"
#include "MotorDriver.h"

#define Ti1 0.0183
#define Td1 0.0021
#define Kp1 9.36
#define alpha1 10
MotorDriver motor(DIR1, PWM1, 0);  
EncoderVelocity encoder(ENCODER_A_PIN, ENCODER_B_PIN, CPR_60_RPM, 0.2);
LeadLagFilter leadLag(alpha1, Td1, Ti1);
double setpoint = 0;
double position = 0;
double controlEffort = 0;

#define MAX_FREQ 10.0 //rad/s
#define MAX_AMPLITUDE M_PI/8 //rad
double freq = MAX_FREQ/2;
double amplitude = MAX_AMPLITUDE/4;


void setup() {
    motor.setup();
    Serial.begin(); 
}

void loop() {
    // Update sinusiodal setpoint at 2kHz
    EVERY_N_MICROS(500) {
        setpoint = amplitude*sin(freq*millis()/1000.0);
    }

    //update PID at 5khz
    EVERY_N_MICROS(200) {
        position = encoder.getPosition();
        controlEffort = Kp1*leadLag.calculate(setpoint-position);
        motor.drive(controlEffort);
    }


    // Print values at 50Hz
    EVERY_N_MILLIS(20) {
            Serial.printf("Setpoint (rad): %.2f, Position (rad): %.2f, Control Effort: %.2f\n",
                          setpoint, position, controlEffort);
        }
}