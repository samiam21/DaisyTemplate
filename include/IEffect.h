#ifndef IEFFECT_H
#define IEFFECT_H

class IEffect
{
public:
    virtual void Setup();
    virtual void Cleanup();
    virtual void AudioCallback(float **in, float **out, size_t size);
    virtual void Loop();
    virtual char *GetEffectName();
};

#endif