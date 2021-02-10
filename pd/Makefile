
TARGETS=sine chorus passthru
GEN=../../pd2dsy/pd2dsy.py --board petal

all: $(TARGETS)

amp: build
	- rm -rf build/$@
	$(GEN) --out_dir $(PWD)/build/$@ $(PWD)/$@.pd

chorus: build
	- rm -rf build/$@
	$(GEN) --out_dir $(PWD)/build/$@ $(PWD)/$@.pd

passthru: build
	- rm -rf build/$@
	$(GEN) --out_dir $(PWD)/build/$@ $(PWD)/$@.pd

sine: build
	- rm -rf build/$@
	$(GEN) --out_dir $(PWD)/build/$@ $(PWD)/$@.pd
	
clean:
	- rm -rf build

build:
	- mkdir build

conda:
	conda create -n daisy python=2 pip

