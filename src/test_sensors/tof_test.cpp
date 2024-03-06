#include <Adafruit_VL53L0X.h>
// #include <Wire.h>
// #include <Adafruit_VL6180X.h>

// https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/arduino-code
// https://github.com/adafruit/Adafruit_VL53L0X/blob/master/examples/vl53l0x/vl53l0x.ino

// https://learn.adafruit.com/adafruit-vl6180x-time-of-flight-micro-lidar-distance-sensor-breakout/wiring-and-test
// https://github.com/adafruit/Adafruit_VL6180X/blob/master/examples/vl6180x/vl6180x.ino

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
    
  delay(100);
}

// Adafruit_VL6180X vl = Adafruit_VL6180X();

// void setup() {
//   Serial.begin(115200);

//   // wait for serial port to open on native usb devices
//   while (!Serial) {
//     delay(1);
//   }
  
//   Serial.println("Adafruit VL6180x test!");
//   if (! vl.begin()) {
//     Serial.println("Failed to find sensor");
//     while (1);
//   }
//   Serial.println("Sensor found!");
// }

// void loop() {
//   float lux = vl.readLux(VL6180X_ALS_GAIN_5);

//   Serial.print("Lux: "); Serial.println(lux);
  
//   uint8_t range = vl.readRange();
//   uint8_t status = vl.readRangeStatus();

//   if (status == VL6180X_ERROR_NONE) {
//     Serial.print("Range: "); Serial.println(range);
//   }

//   // Some error occurred, print it out!
  
//   if  ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
//     Serial.println("System error");
//   }
//   else if (status == VL6180X_ERROR_ECEFAIL) {
//     Serial.println("ECE failure");
//   }
//   else if (status == VL6180X_ERROR_NOCONVERGE) {
//     Serial.println("No convergence");
//   }
//   else if (status == VL6180X_ERROR_RANGEIGNORE) {
//     Serial.println("Ignoring range");
//   }
//   else if (status == VL6180X_ERROR_SNR) {
//     Serial.println("Signal/Noise error");
//   }
//   else if (status == VL6180X_ERROR_RAWUFLOW) {
//     Serial.println("Raw reading underflow");
//   }
//   else if (status == VL6180X_ERROR_RAWOFLOW) {
//     Serial.println("Raw reading overflow");
//   }
//   else if (status == VL6180X_ERROR_RANGEUFLOW) {
//     Serial.println("Range reading underflow");
//   }
//   else if (status == VL6180X_ERROR_RANGEOFLOW) {
//     Serial.println("Range reading overflow");
//   }
//   delay(50);
// }