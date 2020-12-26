
// Terrarium LED example
#include "daisy_petal.h"
#include "daisysp.h"
#include "terrarium.h"

using namespace daisy;
using namespace daisysp;
using namespace terrarium;

DaisyPetal hw;

dsy_gpio led1;
dsy_gpio led2;

int main(void)
{
    hw.Init();

    led1.pin = hw.seed.GetPin(22);
    led1.mode = DSY_GPIO_MODE_OUTPUT_PP;
    led1.pull = DSY_GPIO_NOPULL;

    led2.pin = hw.seed.GetPin(23);
    led2.mode = DSY_GPIO_MODE_OUTPUT_PP;
    led2.pull = DSY_GPIO_NOPULL;

    dsy_gpio_init(&led1);
    dsy_gpio_init(&led2);

    dsy_gpio_write(&led1, true);

    for(;;)
    {
        dsy_gpio_toggle(&led1);
        dsy_gpio_toggle(&led2);
        dsy_system_delay(1000);
    }
}


