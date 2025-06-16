#include "led.h"

void setup() { LED_config(); }

void loop() {
  LED_turn_on();
  delay(1000);
  LED_turn_off();
  delay(1000);
}