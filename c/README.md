
Examples in C
=============

Clone Electrosmith's `DaisySP` and `libDaisy` repos next to this one
and build them according to their instructions.

Come back here and

    make

.bin files will appear in the `build` directory for each example.

To program the Seed with any of the examples, let's say `distortion`,
press the reset sequence on the Seed, then

    cd c/distortion
    make program-dfu
