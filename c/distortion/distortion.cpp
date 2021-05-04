

//Ported distortion petal example to terrarium. Version 1.3.1
// V1.3.x is adding tone control from sonic_explorer's RhythmDelay
#include "daisysp.h"
#include "daisy_petal.h"
#include "terrarium.h"

using namespace daisysp;
using namespace daisy;
using namespace terrarium;

// Declare a local daisy_petal for hardware access
static DaisyPetal petal;

static Tone toneLP; // this is for a Tone object, Tone is just a low-pass filter
static ATone toneHP; // this is for a ATone object, ATone is just a high-pass filter
// static Balance bal; // this is for a Balance object, which will correct for volume drop from the filters
float tone_val =0.0f;

float hardClip(float in)
{
    in = in > 1.f ? 1.f : in;
    in = in < -1.f ? -1.f : in;
    return in;
}

float softClip(float in)
{
    if (in > 0)
        return 1 - expf(-in);
    return -1 + expf(in);
}

Parameter toneParam;

// These are the cutoff freqs for the high and low pass filters
float tone_freqHP;
float tone_freqLP;

// Use the LED object
Led led1, led2;

bool bypassHard, bypassSoft;

static void AudioCallback(float **in, float **out, size_t size)
{
    petal.UpdateAnalogControls();
    petal.DebounceControls();
    toneHP.SetFreq(tone_freqHP);
    toneLP.SetFreq(tone_freqLP);
    led1.Update();
    led2.Update();

    // use a pot for a tone control - toneParam sweeps from -1 to 1
    tone_val = toneParam.Process();
    if (tone_val<0.0f){ // left half of pot HP off, LP on
    tone_freqHP = 0;
        tone_freqLP = 5000.0f*(powf(10,2*tone_val))+100.f;//This is a more complex function just to make the taper nice and smooth, the filter turned on too fast when linear
    }
    else{// right half of pot HP on, LP off
    tone_freqHP = 5000.0f*powf(10,2.f*tone_val-2);//This is a more complex function just to make the taper nice and smooth, the filter turned on too fast when linear
    tone_freqLP = 1000000.0f;// just something very high so the filter is not killing any actual guitar sound
    }

    float Pregain = petal.knob[Terrarium::KNOB_1].Process() * 10 + 1.2;
    float Gain = petal.knob[Terrarium::KNOB_2].Process() * 100 + 1.2;
    float drywet = petal.knob[Terrarium::KNOB_3].Process();

    if (petal.switches[Terrarium::FOOTSWITCH_1].RisingEdge())
    {
        bypassSoft = !bypassSoft;
        led1.Set(bypassSoft ? 0.0f : 1.0f);
    }

    if (petal.switches[Terrarium::FOOTSWITCH_2].RisingEdge())
    {
        bypassHard = !bypassHard;
        led2.Set(bypassHard ? 0.0f : 1.0f);
    }

  
    for(size_t i = 0; i < size; i ++)
    {
        for (int chn = 0; chn < 2; chn++)
        {
            in[chn][i] *= Pregain;
            float wet = in[chn][i];

            if (!bypassSoft || !bypassHard)
            {
                wet *= Gain;
            }

            if (!bypassSoft)
            {
                wet = softClip(wet);
            }
  
            if (!bypassHard)
            {
                wet = hardClip(wet);
                wet = toneHP.Process(wet);
                wet = toneLP.Process(wet);
            }

            
    
      
            out[chn][i] = wet * drywet + in[chn][i] * (1 - drywet);
        }
    }

}

void InitLeds(void)
{
    //Initialize the leds - these are using LED objects
    led1.Init(petal.seed.GetPin(Terrarium::LED_1),false);
    led2.Init(petal.seed.GetPin(Terrarium::LED_2),false);
    // The 'Terrarium::LED_1' (and similar for the knobs) references the terrarium.h which defines which GPIO pins
    //     are associated with which knobs, switches, & LEDs

}

void InitTone(float samplerate)
{
   // Initialize the Tone object
    toneHP.Init(samplerate);
    toneLP.Init(samplerate);
    toneParam.Init(petal.knob[Terrarium::KNOB_4], -1.0f, 1.0f, Parameter::LINEAR); // This knob value will be converted later in ProcessControls to a frequency for the High/Low Pass filter
}

int main(void)
{
    float samplerate;
    petal.Init();
    samplerate = petal.AudioSampleRate();

    bypassHard = bypassSoft = true;

    // Initialize the leds
    InitLeds();

    // Initialize the Tone object
    InitTone(samplerate);

    // start callback
    petal.StartAdc();
    petal.StartAudio(AudioCallback);

    while(1) {}
}


