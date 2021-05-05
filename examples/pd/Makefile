HERE=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))
CODEGEN=python2 ../../../pd2dsy/pd2dsy.py --board petal
TARGETS=amp passthru tremolo waveform

all: $(TARGETS)

amp: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd
	make -C build/$@

passthru: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd
	make -C build/$@

tremolo: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd
	make -C build/$@

waveform: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd
	make -C build/$@

clean:
	- rm -rf build

build:
	- mkdir build

