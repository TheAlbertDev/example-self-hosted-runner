#ifndef Arduino_H__
#define Arduino_H__

#define OUTPUT 0x1
#define LOW 0x0
#define HIGH 0x1

void pinMode(uint32_t ulPin, uint32_t ulMode);
void digitalWrite(uint32_t ulPin, uint32_t ulVal);

#endif /* Arduino_H__ */