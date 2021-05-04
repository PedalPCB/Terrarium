// Hook to reboot into bootloader for DFU upload.
#include <daisy_seed.h>
#include "stm32h7xx_hal.h"

daisy::DaisySeed hw;
daisy::Switch button1;

void setup() {
    // Configure and initialize button
    button1.Init(hw.GetPin(28), 10);
}

void RebootToBootloader()
{
    // Initialize Boot Pin
    dsy_gpio_pin bootpin = {DSY_GPIOG, 3};
    dsy_gpio pin;
    pin.mode = DSY_GPIO_MODE_OUTPUT_PP;
    pin.pin = bootpin;
    dsy_gpio_init(&pin);

    // Pull Pin HIGH
    dsy_gpio_write(&pin, 1);

	// wait a few ms for cap to charge
	hw.DelayMs(10);

    // Software Reset
	HAL_NVIC_SystemReset();
}

int main(void) {
    // Reset to upload

    button1.Debounce();
    if (button1.Pressed())
    {
        RebootToBootloader();
    }

    // wait 1 ms
    hw.DelayMs(1);
}
