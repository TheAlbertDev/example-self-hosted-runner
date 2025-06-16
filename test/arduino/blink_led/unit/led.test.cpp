#include "led.h"
#include "Arduino.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <stdexcept>
#include <stdio.h>

TEST_GROUP(LED__management){};

TEST(LED__management, Pin__configuration) {
  mock()
      .expectOneCall("pinMode")
      .withParameter("ulPin", 13)
      .withParameter("ulMode", OUTPUT);
  mock()
      .expectOneCall("digitalWrite")
      .withParameter("ulPin", 13)
      .withParameter("ulVal", LOW);

  LED_config();

  mock().checkExpectations();
  mock().clear();
}

TEST(LED__management, Turn__on) {
  mock()
      .expectOneCall("digitalWrite")
      .withParameter("ulPin", 13)
      .withParameter("ulVal", HIGH);

  LED_turn_on();

  mock().checkExpectations();
  mock().clear();
}

TEST(LED__management, Turn__off) {
  mock()
      .expectOneCall("digitalWrite")
      .withParameter("ulPin", 13)
      .withParameter("ulVal", LOW);

  LED_turn_off();

  mock().checkExpectations();
  mock().clear();
}