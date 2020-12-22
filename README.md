Support for programming the PedalPCB Terrarium, with examples from
PedalPCB forum members @tcpoint and @sonic-explorer.

Use of macOS or Linux is assumed.  Using WSL in Windows may work.


Building Examples
-----------------

Clone Electrosmith's `DaisyExamples` repo next to this one and build it according to its instructions.  This repo will use the resulting `DaisySP` and `libdaisy` libraries.

In this repo,

    make

.bin files will appear in the `build` directory for each example.


Sending Examples to the Seed
----------------------------

Examples are installed to Seed just as the examples in the DaisyExamples repo are.  In and of the example directories,

    make program-dfu

to send the .bin file to the Seed.
Remember that you need to press buttons on the Seed to ready it to receive.
