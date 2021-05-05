
Examples in Pure Data
=====================
Building Pd patches requires Python 2. Also, you'll need to
install extra packages for Python:

   pip install enum jinja2

The process of getting a Pd patch onto the Terrarium
has two steps: first generating C code from the Pd patch,
then compiling the C code and installing the binary.

Clone this version of Electrosmith's `pd2dsy` beside this repo
(Folders "pd2dsy" and "Terrarium" should be next to each other):

    git clone --branch dev https://github.com/rhaleblian/pd2dsy

and set it up according to its README.

Coming back here, run

    make

to generate the C code for all the examples. If you want to
generate code for one example only, eg `waveform`:

    make waveform

Now build the .bin file from C code and push it to the Seed.
For the `waveform` example:

    cd build/waveform/build
    make
    make program-dfu

The last line copies the .bin file to the Seed, so have
it plugged into your computer via USB.
Remember, put the Seed into DFU programming mode first.


amp.pd
------
A naive amplifier/preamplifier. Knob 1 controls output.

passthru.pd
-----------
Doesn't alter the signal, just sends input to output.

tremolo.pd
----------
Amplitude modulation of the input. No knobs!

waveform.pd
-------
Outputs middle C. Knob 6 (lower-right) controls output level.
Turn knob 6 down before running, the output is loud.


FAQ
===
Q: what does this fork of `pd2dsy` do?

It allows for `pd2dsy` to be run from different directories, so the Pd examples can be stored here.

