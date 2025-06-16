#ifndef Main_H__
#define Main_H__

#include <stdint.h>

#define GPIO_PIN_RESET 0x0
#define GPIO_PIN_SET 0x1
#define LD2_Pin 0x0020
#define LD2_GPIO_Port ((GPIO_TypeDef*)0x40020000)

typedef uint32_t GPIO_TypeDef;
typedef uint32_t GPIO_PinState;

void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
                       GPIO_PinState PinState);

#endif /* Main_H__ */