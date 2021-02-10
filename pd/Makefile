HERE=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))
GEN=../../pd2dsy/pd2dsy.py --board petal
TARGETS=sine chorus passthru

all: $(TARGETS)

amp: build
	- rm -rf build/$@
	$(GEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd

chorus: build
	- rm -rf build/$@
	$(GEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd

passthru: build
	- rm -rf build/$@
	$(GEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd

sine: build
	- rm -rf build/$@
	$(GEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd
	
clean:
	- rm -rf build

build:
	- mkdir build

conda:
	conda create -n daisy python=2 pip
