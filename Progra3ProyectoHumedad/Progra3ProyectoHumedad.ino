#include "MyLibrary.h"
Info hum;

void setup() {
  // put your setup code here, to run once:
  hum.Mode(3,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  hum.SensorTemp();
  hum.LEDS(3,2);
  hum.bomba();
}
