# Lab 5: Sensors

2.12/2.120 Intro to Robotics  
Spring 2024[^1]

- [Lab 5: Sensors](#lab-5-sensors)
  - [1 Validate Hardware Setup](#1-validate-hardware-setup)
    - [1.1 Validate Microcontroller](#11-validate-microcontroller)
    - [1.2 Validate Motors](#12-validate-motors)
    - [1.3 Validate Encoders](#13-validate-encoders)
  - [2 Wiring and Reading Sensors](#2-wiring-and-reading-sensors)
    - [2.1 Button](#21-button)
      - [2.1.1 Wiring](#211-wiring)
      - [2.1.2 Coding](#212-coding)
    - [2.2 Potentiometer](#22-potentiometer)
      - [2.2.1 Wiring](#221-wiring)
      - [2.2.2 Coding](#222-coding)
    - [2.3 Time-of-Flight](#23-time-of-flight)
      - [2.3.1 Wiring](#231-wiring)
      - [2.3.2 Coding](#232-coding)
    - [2.4 IMU](#24-imu)
      - [2.4.1 Wiring](#241-wiring)
      - [2.4.2 Coding](#242-coding)
  - [3 Motor Control](#3-motor-control)
  - [4 TFT Display](#4-tft-display)
    - [4.1 Validate Display](#41-validate-display)
    - [4.2 Validate Sensor](#42-validate-sensor)
    - [4.3 Display Sensor Readings](#43-display-sensor-readings)
  - [5 Make It Wireless](#5-make-it-wireless)
    - [5.1 Validate Wireless Connection](#51-validate-wireless-connection)
    - [5.2 Make it Move or Something?](#52-make-it-move-or-something)
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

## 2 Wiring and Reading Sensors
Estimated time of completion: 40 min

In this section, you will be in charge of wiring and coding each sensor using Adafruit tutorials. This section was purposefully left open-ended, so don't be afraid to ask the lab staff any questions you might have.

Please keep the sensors on the breadboard as you move through this section.

### 2.1 Button

#### 2.1.1 Wiring

Wire the button onto your breadboard. You should use this page as reference: https://learn.adafruit.com/adafruit-arduino-lesson-6-digital-inputs/breadboard-layout.

#### 2.1.2 Coding

Fill in `test_sensors/button_test.cpp` with test code to read your button. You should use this page as reference: https://learn.adafruit.com/adafruit-arduino-lesson-6-digital-inputs/arduino-code.

### 2.2 Potentiometer

#### 2.2.1 Wiring

Wire the potentiometer onto your breadboard. You should use this page as reference: https://learn.adafruit.com/make-it-change-potentiometers/connections.

#### 2.2.2 Coding

Fill in `test_sensors/pot_test.cpp` with test code to read your potentiometer. You should use this page as reference: https://learn.adafruit.com/make-it-change-potentiometers/arduino#display-to-serial-3001622.

### 2.3 Time-of-Flight

#### 2.3.1 Wiring

Wire the ToF sensor onto your breadboard. 

If you are using the VL6180X (green board), you should use this page as reference: https://learn.adafruit.com/adafruit-vl6180x-time-of-flight-micro-lidar-distance-sensor-breakout/wiring-and-test.

If you are using the VL53L0X (black board), you should use this page as reference: https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/arduino-code.

#### 2.3.2 Coding

Fill in `test_sensors/tof_test.cpp` with test code to read your time-of-flight sensor. Import the ToF library in `platformio.ini`. Hint: You do not need to specify a version of the library, but if you wish to do so, the current version is shown on the right side of the GitHub repository main page under "Releases".

If you are using the VL6180X (green board), you should use this page as reference: https://github.com/adafruit/Adafruit_VL6180X/blob/master/examples/vl6180x/vl6180x.ino.

If you are using the VL53L0X (black board), you should use this page as reference: https://github.com/adafruit/Adafruit_VL53L0X/blob/master/examples/vl53l0x/vl53l0x.ino.

### 2.4 IMU

#### 2.4.1 Wiring 

Wire the IMU onto your breadboard. You should use this page as reference: https://learn.adafruit.com/adafruit-9-dof-orientation-imu-fusion-breakout-bno085/arduino#spi-wiring-3072345. We will be using the SPI protocol.

#### 2.4.2 Coding

Fill in `test_sensors/imu_test.cpp` with test code to read your IMU. You should use this page as reference: https://learn.adafruit.com/adafruit-9-dof-orientation-imu-fusion-breakout-bno085/arduino#example-code-3072315. Make sure to uncomment the line `#define BNO08X_RESET 5`. The IMU library has already been imported in `platformio.ini`.

## 3 Motor Control
Estimated time of completion: 10 min

Complete the `TODO` in `test_code/motor_pot.cpp`. Right now, the motor is set to spin at a rate controlled by the potentiometer. Change it to whatever sensor you want!

## 4 TFT Display
Estimated time of completion: 15 min

Up to now, we've conducted all our validation tests by printing to the Serial Monitor. This requires constant wired connection to your machine, which isn't always ideal. For example, you might want to troubleshoot sensors on your mobile robot as it is moving! In some cases, it is more convenient to instead use a TFT display.

### 4.1 Validate Display

Ask the staff for a microcontroller with a pre-wired display and validate it by running `test_code/display_test.cpp`. Like you did in the previous sections, we got this test code from the Adafruit tutorial.

### 4.2 Validate Sensor

Rewire the sensor you chose in the [previous section](#3-motor-control) from your original microcontroller to this new microcontroller. Then, run the test code you wrote on the new microcontroller to print sensor readings to the Serial Monitor. Confirm that the values are reasonable.

### 4.3 Display Sensor Readings

In `lab_code/display_sensor.cpp`, combine `test_code/display_test.cpp` and the test code you wrote to print sensor readings to the display instead of the Serial Monitor. You may find the implementation of `testText()` in `test_code/display_test.cpp` helpful.

## 5 Make It Wireless
Estimated time of completion: 30 min

Since we have physically separated the sensor from the motor, we now want the two microcontrollers communicate wirelessly (via WiFi) to perform motor control. In our case, the *sender* is connected to the sensor and display, while the *receiver* is connected to the motor. 

### 5.1 Validate Wireless Connection

Run `get_mac.cpp` on the *receiver* to get the MAC address of the *receiver* microcontroller. Then, replace `broadcastAddress` in `wireless/esp_now_sender.cpp` to be that MAC address. Run `wireless/esp_now_sender.cpp` on the *sender* and `wireless/esp_now_receiver.cpp` on the *receiver*. Keep the *receiver* connected to your machine and open the Serial Monitor. 

Confirm that the data received, printed on the Serial Monitor, is reasonable given the data sent. Hint: Refer to lines `60` to `63` in `wireless/esp_now_sender.cpp`.

### 5.2 Make it Move or Something?


## X Feedback Form

Before you leave, please fill out https://tinyurl.com/212-feedback. 

| :white_check_mark: CHECKOFF X :white_check_mark:   |
|:---------------------------------------------------|
| Show the feedback form completion screen to a TA or LA. |

[^1]: Version 1 - 2024: Joseph Ntaimo, Jinger Chong, Josh Sohn
