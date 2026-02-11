/* NOTE: Adjust ranges based on reliable readings.
   Add a buffer of +600 ms on the G-code side. 
   In my tests, the average read time was ~400 ms, 
   so I placed M400 S1 in the === Filament Slot Communication === block. 
*/


#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

unsigned long lastCheck = 0;
const unsigned long checkInterval = 50;

int lastStable = -1;
int candidate = -1;
int stableCount = 0;
const int requiredStable = 3;

unsigned long candidateStartTime = 0;  // track when candidate was first seen

struct SlotRange {
  int min;
  int max;
};
SlotRange slots[] = {
  { 38, 43 },   // 1
  { 50, 55 },   // 2
  { 60, 65 },   // 3
  { 70, 75 },   // 4
  { 79, 84 },   // 5
  { 90, 95 },   // 6
  { 102, 107 }, // 7
  { 116, 121 }, // 8
  { 121, 139 }, // 9
  { 147, 155 }, // 10
  { 162, 168 }, // 11
  { 180, 185 }, // 12
  { 193, 198 }, // 13
  { 212, 217 }, // 14
  { 222, 231 }, // 15
  { 238, 249 }, // 16
  { 254, 259 }, // 17
  { 263, 270 }, // 18
  { 272, 280 }, // 19
  { 284, 289 }, // 20
  { 292, 298 }  // 21
};

const int slotCount = sizeof(slots) / sizeof(slots[0]);

int slotFromDistance(int dist) {
  for (int i = 0; i < slotCount; i++) {
    if (dist >= slots[i].min && dist <= slots[i].max) return i + 1;
  }
  return -1;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }
  sensor.setMeasurementTimingBudget(200000);
}

void loop() {
  unsigned long now = millis();
  if (now - lastCheck >= checkInterval) {
    lastCheck = now;

    int reading = sensor.readRangeSingleMillimeters();
    if (sensor.timeoutOccurred()) return;

    int slot = slotFromDistance(reading);

    if (slot == -1) {
      Serial.print("Distance: ");
      Serial.print(reading);
      Serial.println(" mm (Out of range)");
      candidate = -1;
      stableCount = 0;
      return;
    }

    if (candidate == -1) {
      candidate = slot;
      stableCount = 1;
      candidateStartTime = now;  // mark when candidate started
      return;
    }

    if (slot == candidate) {
      stableCount++;
      if (stableCount >= requiredStable && slot != lastStable) {
        lastStable = slot;
        unsigned long elapsed = now - candidateStartTime;  // calculate stabilization time
        Serial.print("Stabilized Distance: ");
        Serial.print(reading);
        Serial.print(" mm -> Slot ");
        Serial.print(lastStable);
        Serial.print(" (Elapsed: ");
        Serial.print(elapsed);
        Serial.println(" ms)");
      }
    } else {
      candidate = slot;
      stableCount = 1;
      candidateStartTime = now;  // reset start time for new candidate
    }
  }
}
