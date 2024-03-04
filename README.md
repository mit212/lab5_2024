# Lab 5: Sensors

2.12/2.120 Intro to Robotics  
Spring 2024[^1]

- [1 Validate Hardware Setup](#1-validate-hardware-setup)
  - [1.1 Validate Microcontroller](#11-validate-microcontroller)
  - [1.2 Validate Motors](#12-validate-motors)
  - [1.3 Validate Encoders](#13-validate-encoders)
  - [1.4 Validate Joystick](#14-validate-joystick)
- [2 Wiring and Reading Sensors](#2-wiring-and-reading-sensors)
  - [2.1 Button](#21-button)
  - [2.2 Potentiometer](#22-potentiometer)
  - [2.3 Time-of-Flight](#23-time-of-flight)
  - [2.4 IMU](#24-imu)
- [X Feedback Form](#x-feedback-form)

## 1 Validate Hardware Setup
Estimated time of completion: 10 min

Like in the previous labs, we first want to make sure the parts work individually! Faulty wiring or hardware can be very difficult to debug in complex systems.

### 1.1 Validate Microcontroller

**Make sure that motor power is turned off any time you are uploading code to your microcontroller.** The arm has a tendency to spin around and hit itself if motor power is on during upload. As a reminder, motor power should only be on when you expect the motors to move. Otherwise, please keep motor power off. 

<details> <summary> <i> How to know if the motor power is on? </i> </summary>

The yellow LED on the motor driver indicates whether motor power is on or off.
</details>

Clone this repository and run `robot/blink_test.cpp`. You should see the onboard LED change colors! 

<details> <summary> <i> Forget how to clone? </i> </summary>

Please refer to the [instructions from Lab 1](
https://github.com/mit212/lab1_2024?tab=readme-ov-file#31-git-clone).

</details>

### 1.2 Validate Motors

Orient the arm straight up, in default starting position. Run `test_code/motor_drive_test.cpp` to validate your motor setup. You should see both motors oscillating back and forth. Remember, motor 1 is attached to the base and motor 2 is attached to the second link. 

### 1.3 Validate Encoders

Run `test_code/encoder_test.cpp` to validate your encoder setup. Open the Serial Monitor to see the output and confirm that both the direction and the magnitude make sense!

### 1.4 Validate Joystick

Run `test_code/joystick_test.cpp` to validate your joystick setup. You should be able to see joystick readings within the range `[-1, 1]`.


## 2 Wiring and Reading Sensors

### 2.1 Button

### 2.2 Potentiometer

### 2.3 Time-of-Flight

### 2.4 IMU


## X Feedback Form

Before you leave, please fill out https://tinyurl.com/212-feedback. 

| :white_check_mark: CHECKOFF X :white_check_mark:   |
|:---------------------------------------------------|
| Show the feedback form completion screen to a TA or LA. |

[^1]: Version 1 - 2024: Joseph Ntaimo, Jinger Chong, Josh Sohn
