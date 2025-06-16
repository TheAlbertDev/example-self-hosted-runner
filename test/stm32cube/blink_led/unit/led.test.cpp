#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <stdexcept>
#include <stdio.h>

extern "C" {
#include "led.h"
#include "main.h"
}

TEST_GROUP(LED__management){};

TEST(LED__management, Turn__on) {
  mock()
      .expectOneCall("HAL_GPIO_WritePin")
      .withParameter("GPIOx", LD2_GPIO_Port)
      .withParameter("GPIO_Pin", LD2_Pin)
      .withParameter("PinState", GPIO_PIN_SET);

  LED_turn_on();

  mock().checkExpectations();
  mock().clear();
}

TEST(LED__management, Turn__off) {
  mock()
      .expectOneCall("HAL_GPIO_WritePin")
      .withParameter("GPIOx", LD2_GPIO_Port)
      .withParameter("GPIO_Pin", LD2_Pin)
      .withParameter("PinState", GPIO_PIN_RESET);

  LED_turn_off();

  mock().checkExpectations();
  mock().clear();
}