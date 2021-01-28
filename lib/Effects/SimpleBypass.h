#ifndef BYPASS_H
#define BYPASS_H

#include "daisy_seed.h"
#include "../../../include/IEffect.h"
#include "../../../include/PedalConfig.h"

/**********************************************
 * SimpleBypass Effect
 * 
 * SPST 1 - 
 * SPST 2 - 
 * SPST 3 - 
 * SPST 4 - 
 * 
 * SPDT 1 - 
 * SPDT 2 - 
 * 
 * Knob 1 - Volume Boost
 * Knob 2 - 
 * Knob 3 - 
 * Knob 4 - 
 * 
 * LED 1 - 
 * LED 2 - 
 * LED 3 - 
 * LED 4 - 
 **********************************************/

class SimpleBypass : public IEffect
{
public:
    void Setup(daisy::DaisySeed* hardware);
    void Cleanup();
    void AudioCallback(float **in, float **out, size_t size);
    void Loop();
    char *GetEffectName();

private:
    size_t numChannels;
    const int LED_MAX_VALUE = 256;
    const int LED_MIN_VALUE = 0;

    const float boostLevelMin = 30.0f;
    const float boostLevelMax = 60.0f;
    float boostLevel = 1.0f;
};

#endif