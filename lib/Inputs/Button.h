#ifndef BUTTON_H
#define BUTTON_H

#include "daisy_seed.h"
#include "../../include/PedalConfig.h"

using namespace daisy;

/**
 * Button class to handle reading a button value while debouncing it
 * This class will initialize the provided pin in the init function
 */
class Button
{
public:
    /**
     * Initialize the button
     */
    void Init(dsy_gpio_pin pin);

    /**
     * Initialize the button with print capabilities
     */
    void Init(dsy_gpio_pin pin, DaisySeed *hardware);

    /**
     * Checks if the button is pressed, accounting for debounce
     * @return Returns true if the button is pressed, false if not
     */
    bool IsPressed(bool debounce = true);

private:
    dsy_gpio_pin buttonPin;
    DaisySeed *hw;
    bool isDebugPrintingEnabled = false;

    const unsigned long buttonDebounce = 200;
    unsigned long lastButtonPress = 0;

    Switch button;
};

#endif