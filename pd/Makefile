HERE=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))
CODEGEN=../../pd2dsy/pd2dsy.py --board petal
TARGETS=amp delay sine chorus passthru

all: $(TARGETS)

amp:
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd

chorus: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd

delay: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd

passthru: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd

sine: build
	- rm -rf build/$@
	$(CODEGEN) --out_dir $(HERE)/build/$@ $(HERE)/$@.pd


clean:
	- rm -rf build amp

build:
	- mkdir build

conda:
	conda create -n daisy python=2 pip
