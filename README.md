Terrarium
=========
Support for programming the PedalPCB Terrarium, with examples from
PedalPCB forum members @tcpoint, @sonic-explorer and @plate-of-shrimp.

Examples in C
-------------
Clone Electrosmith's `DaisyExamples` repo next to this one and build it according to its instructions.
We will use the resulting `DaisySP` and `libdaisy` libraries.

In this repo,

    cd c
    make

.bin files will appear in the `build` directory for each example.

To program the Seed with any of the examples, let's say `distortion`,
press the reset sequence on the Seed, then

    cd c/distortion
    make program-dfu 


Examples in Pure Data
---------------------
Building Pd patches requires Python 2.

Clone this version of `pd2dsy` beside this repo:

    git clone --branch dev https://github.com/rhaleblian/pd2dsy

and set it up according to its README.
Coming back here, run

    cd pd
    make

to build all the examples. The binaries will be in

    build/{patchname}/build

and installation will look like eg

    cd build/sine/build
    make program-dfu


Examples in Max
---------------
Install Oopsy before opening patches.
Set the device in the patch to 'petal' and remember to put the Seed into DFU programming mode first.

`cmaj.maxpat` is a generator producing an extended Cmaj7 chord. It's a knob tester.
Knobs 1-5 control gain for each tone and Knob 6 controls master gain.


Cleaning Up
-----------
    make clean

will remove all `build` dirs.
