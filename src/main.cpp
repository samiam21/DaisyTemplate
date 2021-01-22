#include "../include/PedalConfig.h"

// Effect switching parameters
// volatile EffectType selectedEffectType = UNSET;
// IEffect *currentEffect;

int main(void)
{
    // Declare a variable to store the state we want to set for the LED.
    bool led_state;
    led_state = true;

    // Configure and Initialize the Daisy Seed
    hw.Configure();
    hw.Init();

    // Initialize debug printing
    initDebugPrint(true);
    debugPrintln("Starting DaisyPedal...");

    // Update the block size and sample rate to minimize noise
    hw.SetAudioBlockSize(BLOCKSIZE);
    hw.SetAudioSampleRate(DAISY_SAMPLE_RATE);

    // Loop forever
    for (;;)
    {
        // Set the onboard LED
        hw.SetLed(led_state);
        debugPrintln((led_state) ? "on" : "off");

        // Toggle the LED state for the next time around.
        led_state = !led_state;

        // Wait 500ms
        System::Delay(1500);
    }
}