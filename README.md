# Lab 5: Sensors

2.12/2.120 Intro to Robotics  
Spring 2024[^1]

- [1 Microcontroller](#1-microcontroller)
  - [1.1 Validate Microcontroller](#11-validate-microcontroller)
  - [1.2 Microcontroller Pinout](#12-microcontroller-pinout)
- [2 Wiring and Reading Sensors](#2-wiring-and-reading-sensors)
  - [2.1 Potentiometer](#21-potentiometer)
    - [2.1.1 Wiring](#211-wiring)
    - [2.1.2 Coding](#212-coding)
  - [2.2 Button](#22-button)
    - [2.2.1 Wiring](#221-wiring)
    - [2.2.2 Coding](#222-coding)
  - [2.3 Time-of-Flight](#23-time-of-flight)
    - [2.3.1 Wiring](#231-wiring)
    - [2.3.2 Coding](#232-coding)
  - [2.4 IMU](#24-imu)
    - [2.4.1 Wiring](#241-wiring)
    - [2.4.2 Coding](#242-coding)
- [3 Sensor-controlled Motor](#3-sensor-controlled-motor)
  - [3.1 Validate Motors](#31-validate-motors)
  - [3.2 Validate Encoders](#32-validate-encoders)
  - [3.3 Sensor Integration](#33-sensor-integration)
- [4 Free Exploration](#4-free-exploration)
- [4.1 TFT Display](#41-tft-display)
  - [4.1.1 Wiring](#411-wiring)
  - [4.1.2 Coding](#412-coding)
  - [4.1.3 Sensor Integration](#413-sensor-integration)
- [4.2 Wireless Communication](#42-wireless-communication)
  - [4.2.1 Wiring](#421-wiring)
  - [4.2.1 Coding](#421-coding)
  - [4.2.2 Wireless Sensor-controlled Motor](#422-wireless-sensor-controlled-motor)
- [5 Feedback Form](#5-feedback-form)

## 1 Microcontroller
Estimated time of completion: 5 min

### 1.1 Validate Microcontroller

Clone this repository and run `robot/blink_test.cpp`. You should see the onboard LED change colors! 

<details> <summary> <i> Forget how to clone? </i> </summary>

Please refer to the [instructions from Lab 1](
https://github.com/mit212/lab1_2024?tab=readme-ov-file#31-git-clone).

</details>

### 1.2 Microcontroller Pinout

Refer to the pinout diagram [here](https://esp32s3.com/pros3.html#img1) when choosing pins for sensors, motors, and encoders. 

The pin numbers in code are usually defined either in `include/pinout.h` or through `#define` statements at the beginning of the test code. In this lab, you are free to use any pins as long as they are the right type and you update the code to match your chosen pins.

Feel free to clarify with staff if you are unsure what the labels mean! A printout of this diagram has also been provided to you.

## 2 Wiring and Reading Sensors
Estimated time of completion: 40 min

In this section, you will wire and code each sensor by following Adafruit tutorials. The instructions are intentionally vague to prepare you incase you use other sensors for the final project! Don't be afraid to ask the lab staff any questions you might have.

Please keep the sensors on the breadboard as you move through this section.

### 2.1 Potentiometer

#### 2.1.1 Wiring

Wire the potentiometer onto your breadboard. Refer to [this Adafruit page](https://learn.adafruit.com/make-it-change-potentiometers/connections) as an example.

#### 2.1.2 Coding

Fill in `test_sensors/pot_test.cpp` with test code to read your potentiometer. Refer to [this Adafruit page](https://learn.adafruit.com/make-it-change-potentiometers/arduino#display-to-serial-3001622) as an example.

### 2.2 Button

#### 2.2.1 Wiring

Wire the button onto your breadboard. Refer to [this Adafruit page](https://learn.adafruit.com/adafruit-arduino-lesson-6-digital-inputs/breadboard-layout) as an example. You only need one button. You can wire an LED as well, or use the built-in LED on the microcontroller.

#### 2.2.2 Coding

Fill in `test_sensors/button_test.cpp` with test code to read your button. For this lab, we will be using the `Bounce2` library to filter out undesired state changes (debouncing).
<!-- Refer to [this Adafruit page](https://learn.adafruit.com/adafruit-arduino-lesson-6-digital-inputs/arduino-code) as an example. -->

1. Import the `Bounce2` library in `platformio.ini`.

    <details>
    <summary><i>How do I import a library in platform.io?</i></summary>

    1. Go to `PIO Home/Libraries` (in VSCode) or to [PlatformIO Registry](https://registry.platformio.org/) and search for the library. For this example, the name of your library would be `Bounce2`.

        <details>
        <summary><i>How do I go to <code>PIO Home/Libraries</code> in VSCode?</i></summary>
        </details>

    2. Open the Installation tab and add the specified line (`#The exact version` in VSCode) to the lib_deps option of `[env:]` section. For this example, the full library name would be `thomasfredericks/Bounce2@^2.72`.

    </details>
2. Fill in `test_sensors/button_test.cpp` with test code to use your button to turn on the LED. 

    <details>
      <summary><i>Where can I find the demo code?</i></summary>

      1. Go to `PIO Home/Libraries` (in VSCode) or to [PlatformIO Registry](https://registry.platformio.org/) and search for the library. For this example, the name of your library would be `Bounce2`.

      2. Open the Examples tab, choose your preferred demo code. For this example, `bounce_basic` is sufficient. Copy the code into `src/test_sensors/button_test.cpp`.

    </details>

### 2.3 Time-of-Flight

#### 2.3.1 Wiring

Wire the ToF sensor onto your breadboard. We will be using the I2C protocol.

If you are using the VL6180X (green board), refer to [this Adafruit page](https://learn.adafruit.com/adafruit-vl6180x-time-of-flight-micro-lidar-distance-sensor-breakout/wiring-and-test#wiring-3060229) as an example.

If you are using the VL53L0X (black board), refer to [this Adafruit page](https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/arduino-code#step-2593375) as an example.

#### 2.3.2 Coding

Fill in `test_sensors/tof_test.cpp` with test code to read your time-of-flight sensor. Once again, you will have to import the ToF library and refer to the demo code.

If you are using the VL6180X (green board), refer to [this Adafruit page](https://learn.adafruit.com/adafruit-vl6180x-time-of-flight-micro-lidar-distance-sensor-breakout/wiring-and-test#install-adafruit-vl6180x-2980766) as an example. The name of this library is `Adafruit_VL6180X`, and the demo code is called `vl6180x
`.
If you are using the VL53L0X (black board), refer to [this Adafruit page](https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/arduino-code#download-adafruit-vl53l0x-2593377) as an example. The name of this library is `Adafruit_VL53L0X`, and the demo code is called `vl53l0x`.

### 2.4 IMU

#### 2.4.1 Wiring 

Wire the IMU onto your breadboard. Refer to [this Adafruit page](https://learn.adafruit.com/adafruit-9-dof-orientation-imu-fusion-breakout-bno085/arduino#spi-wiring-3072345) as an example. We will be using the SPI protocol.

#### 2.4.2 Coding

Fill in `test_sensors/imu_test.cpp` with test code to read your IMU. Refer to [this Adafruit page](https://learn.adafruit.com/adafruit-9-dof-orientation-imu-fusion-breakout-bno085/arduino#example-code-3072315) as an example. Make sure to uncomment the line `#define BNO08X_RESET 5`. The IMU library has already been imported in `platformio.ini`.

## 3 Sensor-controlled Motor 
Estimated time of completion: 15 min

### 3.1 Validate Motors

Push and hold either of the `M1A` and `M1B` buttons on the motor driver to see the wheel spin. Then, wire up the motor and run `test_code/motor_drive_test.cpp`. The wheel should spin in different directions with varied speeds.

### 3.2 Validate Encoders

Wire up the encoder and run `test_code/encoder_test.cpp`. Open the Serial Monitor and confirm that both the direction and the magnitude make sense.

### 3.3 Sensor Integration

We now want to use one of the sensors to dictate a variable involved in `test_code/motor_position_control.cpp`. For example, you can use the potentiometer reading to be `setpoint`. Running `test_code/motor_position_control.cpp` as is should make the motor oscillate back and forth.

Incorporate sensor reading code from the tests in the previous section into `test_code/motor_position_control.cpp`. You may have to map or convert your sensor reading into reasonable values for the variable you choose. 

You are free to use any sensor you want. You can even use multiple sensors! Consider sensor/s that you think will be useful for the final project. 

| :white_check_mark: CHECKOFF 1 :white_check_mark:   |
|:---------------------------------------------------|
| Demonstrate your new `test_code/motor_position_control.cpp` to a TA or LA. |

## 4 Free Exploration
Estimated time of completion: now until the end of lab

The next two subsections are purposefully open-ended to encourage exploration. You are welcome to do either, both, or something completely different! Again, consider doing something you think will be useful for the final project. You will demonstrate to the staff what you have made in the last 10-15 minutes of lab.

## 4.1 TFT Display

Up to now, we've conducted all our validation tests by printing to the Serial Monitor. This requires constant wired connection to your machine, which isn't always ideal. For example, you might want to troubleshoot sensors on your mobile robot as it is moving! In some cases, it is more convenient to instead use a TFT display.

### 4.1.1 Wiring

Ask the staff for a TFT display and wire it onto your breadboard using [this Adafruit page](https://learn.adafruit.com/adafruit-3-5-color-320x480-tft-touchscreen-breakout/spi-wiring-and-test) as reference. If your breadboard too crowded, you can ask the staff for another microcontroller and breadboard. Remember to validate the new microcontroller by first running `robot/blink_test.cpp`.

### 4.1.2 Coding

Import the `Adafruit_HX8357` library and copy the example code into `test_code/display_test.cpp`. Run `test_code/display_test.cpp` to show text and shapes on your display. 

### 4.1.3 Sensor Integration

Choose a sensor whose readings will be printed on the display. If you are using a new microcontroller and breadboard, rewire your chosen sensor on the new breadboard and revalidate it first using the test code you wrote in `test_sensors/`.

In `lab_code/display_sensor.cpp`, combine `test_code/display_test.cpp` and the test code you wrote in `test_sensors/` to print sensor readings to the display instead of the Serial Monitor. You may find the implementation of `testText()` in `test_code/display_test.cpp` helpful.

## 4.2 Wireless Communication

Upto now, we've only used wired communications. What happens if we want to control the mobile robot via joystick for the final project? Clearly, the joystick can't also be physically attached to the mobile robot. The microcontrollers we are using can communicate to each other via WiFi. 

### 4.2.1 Wiring

You first need to divide your setup into a *sender* and a *receiver*. In our case, the *sender* should be connected to your chosen sensor (and, optionally, the display), while the *receiver* should be connected to the motor. Ask the staff for any necessary parts and rewire your setup.

### 4.2.1 Coding

Run `get_mac.cpp` on the *receiver* to get the MAC address of the *receiver* microcontroller. Then, replace `broadcastAddress` in `wireless/esp_now_sender.cpp` to be that MAC address. Run `wireless/esp_now_sender.cpp` on the *sender* and `wireless/esp_now_receiver.cpp` on the *receiver*. Keep the *receiver* connected to your machine and open the Serial Monitor. 

Confirm that the data received, as printed on the Serial Monitor, is reasonable given the data sent. Hint: Refer to lines `60` to `63` in `wireless/esp_now_sender.cpp` to see what data is being sent.

### 4.2.2 Wireless Sensor-controlled Motor 

Modify `wireless/esp_now_sender.cpp` and `wireless/esp_now_receiver.cpp` so that the *sender* reads and sends sensor data, while the *receiver* parses this data and uses it to command the motor. Remember what you learned in previous labs about `struct`s to define a message type. You may need to incorporate code from `test_code/motor_position/control.cpp`.

If you get stuck, refer to this [tutorial](https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/) or ask the staff for help!

| :white_check_mark: CHECKOFF 2 :white_check_mark:   |
|:---------------------------------------------------|
| Show your chosen mini-project to a TA or LA. |

## 5 Feedback Form

Before you leave, please fill out https://tinyurl.com/212-feedback. 

| :white_check_mark: CHECKOFF 3 :white_check_mark:   |
|:---------------------------------------------------|
| Show the feedback form completion screen to a TA or LA. |

[^1]: Version 1 - 2024: Joseph Ntaimo, Jinger Chong, Josh Sohn
