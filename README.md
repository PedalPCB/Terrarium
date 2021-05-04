Terrarium
=========
Support for programming the PedalPCB Terrarium,
with examples from PedalPCB forum members
@tcpoint, @sonic-explorer and @plate-of-shrimp.

Examples in C
-------------
See the README in the c/ directory.


Examples in Pure Data
---------------------
See the README in the pd/ directory.


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


FAQ
---
Q: what does this fork of `pd2dsy` do?

It allows for `pd2dsy` to be run from different directories, so the Pd examples can be stored here.

