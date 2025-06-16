#include "Arduino.h"

void LED_config(void) {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void LED_turn_on(void) {
  digitalWrite(13, HIGH);
}

void LED_turn_off(void) {
  digitalWrite(13, LOW);
}