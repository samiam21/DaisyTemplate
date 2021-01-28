#include "../include/PedalConfig.h"
#include "../include/IEffect.h"
#include "../include/EffectType.h"

// Effect switching parameters
volatile EffectType selectedEffectType = UNSET;
IEffect *currentEffect;

//Configure and initialize button
Switch button1;
Led led1;

int main(void)
{
    // Configure and Initialize the Daisy Seed
    hw.Configure();
    hw.Init();

    //Set button to pin 28, to be updated at a 1kHz  samplerate
    button1.Init(hw.GetPin(effectSPSTPin1), 1000, Switch::Type::TYPE_MOMENTARY, Switch::Polarity::POLARITY_NORMAL, Switch::Pull::PULL_UP);
    led1.Init(hw.GetPin(effectLedPin1), false);

    // Initialize debug printing (true = wait for COM connection before continuing)
    initDebugPrint(true);
    debugPrintln("Starting DaisyPedal...");

    // Update the block size and sample rate to minimize noise
    hw.SetAudioBlockSize(BLOCKSIZE);
    hw.SetAudioSampleRate(DAISY_SAMPLE_RATE);

    // Loop forever
    for (;;)
    {
        //Debounce the button
        button1.Debounce();

        led1.Set(button1.Pressed() ? 1.f : 0.f);
        led1.Update();

        //wait 1 ms
        System::Delay(1);
    }
}