#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  // Accuracy settings
  sensor.setMeasurementTimingBudget(200000); // High accuracy
}

void loop() {
  // Check if user typed something in Serial Monitor
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // read until Enter
    command.trim(); // remove spaces/newlines

    if (command.equalsIgnoreCase("record")) { // type record on the Serial Monitor
      // Take a single measurement
      uint16_t distance = sensor.readRangeSingleMillimeters();

      if (sensor.timeoutOccurred()) {
        Serial.println("TIMEOUT");
      } else {
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" mm");
      }
    }
  }

  // Small delay to avoid busy-waiting
  delay(50);
}
