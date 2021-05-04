
Examples in Pure Data
---------------------
Building Pd patches requires Python 2.

This process has two steps: first generating C code from the Pd patch,
then compiling the C code and installing the binary.

Clone this version of Electrosmith's `pd2dsy` beside this repo:

    git clone --branch dev https://github.com/rhaleblian/pd2dsy

and set it up according to its README.

Coming back here, run

    make

to generate the C code for all the examples.

Now build the binary from C code and push it to the Daisy Seed.
For the `sine` example:

    cd build/sine/build
    make program-dfu

Remember, put the Seed into DFU programming mode first.


FAQ
---
Q: what does this fork of `pd2dsy` do?

It allows for `pd2dsy` to be run from different directories, so the Pd examples can be stored here.

