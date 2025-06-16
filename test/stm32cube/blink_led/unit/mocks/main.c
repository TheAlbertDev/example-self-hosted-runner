#include "main.h"
#include "CppUTestExt/MockSupport_c.h"

void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
                       GPIO_PinState PinState) {
  mock_c()->
      actualCall("HAL_GPIO_WritePin")
      ->withPointerParameters("GPIOx", GPIOx)
      ->withUnsignedIntParameters("GPIO_Pin", GPIO_Pin)
      ->withUnsignedLongIntParameters("PinState", PinState);
  return;
}