#include "Arduino.h"
#include "CppUTestExt/MockSupport.h"

void pinMode(uint32_t ulPin, uint32_t ulMode) {
  mock()
      .actualCall("pinMode")
      .withParameter("ulPin", ulPin)
      .withParameter("ulMode", ulMode);
  return;
}
void digitalWrite(uint32_t ulPin, uint32_t ulVal) {
  mock()
      .actualCall("digitalWrite")
      .withParameter("ulPin", ulPin)
      .withParameter("ulVal", ulVal);
  return;
}