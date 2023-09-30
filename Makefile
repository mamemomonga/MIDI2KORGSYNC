AR_PROGRAMMER=

include ./config.mk

upload: build/$(AR_SKETCH).ino.hex
	arduino-cli upload -b $(AR_FQBN) -p $(AR_PORT) $(AR_PROGRAMMER) --input-dir "$(CURDIR)/build"

compile: build/$(AR_SKETCH).ino.hex

serial:
	screen $(AR_PORT)

clean:
	rm -rf build

build/$(AR_SKETCH).ino.hex: $(AR_SKETCH)/$(AR_SKETCH).ino
	arduino-cli compile -b $(AR_FQBN) --build-path "$(CURDIR)/build" $(AR_SKETCH)

.PHONY: upload compile serial clean
