Support for programming the PedalPCB Terrarium, with examples from
PedalPCB forum members @tcpoint and @sonic-explorer.

Use of macOS or Linux is assumed.  Using WSL in Windows may work.


C Examples
----------

Clone Electrosmith's `DaisyExamples` repo next to this one and build it according to its instructions.  This repo will use the resulting `DaisySP` and `libdaisy` libraries.

In this repo,

    make

.bin files will appear in the `build` directory for each example.

To program the Seed with any of the examples, taking for instance 'distortion',
press the reset sequence on the Seed, then

    cd c/distortion
    make program-dfu 

