#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

unsigned long lastCheck = 0;
const unsigned long checkInterval = 50; // check every 50 ms

int lastStable = -1;   // last stabilized value
int candidate = -1;    // candidate reading
int tolerance = 2;     // ±2 mm tolerance

void setup() {
  Serial.begin(9600);
  Wire.begin();

  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  // High accuracy mode
  sensor.setMeasurementTimingBudget(200000);
}

void loop() {
  unsigned long now = millis();

  if (now - lastCheck >= checkInterval) {
    lastCheck = now;

    int reading = sensor.readRangeSingleMillimeters();
    if (sensor.timeoutOccurred()) return;

    // If candidate not set, initialize
    if (candidate == -1) {
      candidate = reading;
      return;
    }

    // If reading is within tolerance of candidate, accept as stable
    if (abs(reading - candidate) <= tolerance) {
      if (reading != lastStable) {
        lastStable = reading;
        Serial.print("Stabilized Distance: ");
        Serial.print(lastStable);
        Serial.println(" mm");
      }
    } else {
      // Reset candidate if reading drifts too far
      candidate = reading;
    }
  }
}
