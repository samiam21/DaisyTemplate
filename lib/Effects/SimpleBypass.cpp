#include "SimpleBypass.h"

void SimpleBypass::Setup()
{
}

void SimpleBypass::AudioCallback(float **in, float **out, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        out[AUDIO_OUT_CH][i] = in[AUDIO_IN_CH][i] * boostLevel;
    }
}

void SimpleBypass::Cleanup()
{
}

void SimpleBypass::Loop()
{
}

char *SimpleBypass::GetEffectName()
{
    return "Simple Bypass Test";
}