#include "Button.h"

void Button::Init(dsy_gpio_pin pin)
{
    // Set the button pin for the class
    buttonPin = pin;

    // Configure the button pin with the specific mode
    button.Init(pin, 1000, Switch::Type::TYPE_MOMENTARY, Switch::Polarity::POLARITY_NORMAL, Switch::Pull::PULL_UP);
}

void Button::Init(dsy_gpio_pin pin, DaisySeed *hardware)
{
    // Set the hardware pointer for debug printing
    hw = hardware;
    isDebugPrintingEnabled = true;

    // Initialize the button
    Init(pin);
}

bool Button::IsPressed(bool debounce)
{
    bool ret = false;

    // Read the button
    bool reading = button.RawState();

    // Check for debounce command
    if (debounce)
    {
        // Debounce the button and check for it pressed
        uint32_t millis = System::GetNow();
        if (millis - lastButtonPress > buttonDebounce)
        {
            // Update last pressed time and set the return
            lastButtonPress = millis;
            ret = reading;
        }
    }
    else
    {
        // Check if the button is pressed
        ret = reading;
    }

    return ret;
}