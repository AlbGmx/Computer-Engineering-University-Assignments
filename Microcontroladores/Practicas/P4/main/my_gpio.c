#include "my_gpio.h"

gpioInitError_t my_gpio_init(gpioNum_t gpioNum, gpioMode_t gpioMode)
{
    return eGpioInitSuccess;
}

void my_gpio_write(gpioNum_t gpioNum, gpioLevel_t gpioLevel)
{
    return;
}

gpioLevel_t my_gpio_read(gpioNum_t gpioNum)
{
    return eMaxLevel; // invalid by default
}
