
# sudo chmod a+wrx /dev/maple && sudo chmod a+wrx /dev/ttyACM0

LIBDIR = ../libs
OUTDIR = ./build

USER_MODULES="./libraries/sdcard"

all: libmaple sdcard usbMassStorage source
	-cd $(OUTDIR) && export USER_MODULES=$(USER_MODULES) && make

clean:
	-rm -rf $(OUTDIR)

outdir:
	-mkdir -p $(OUTDIR)

libmaple:
	-cp -R $(LIBDIR)/libmaple/ $(OUTDIR)

sdcard:
	-cp -R $(LIBDIR)/sdcard/ $(OUTDIR)/libraries/sdcard

usbMassStorage:
	-cp -R $(LIBDIR)/usbMassStorage/ $(OUTDIR)/libraries/usbMassStorage

source:
	-cp -R . $(OUTDIR)

install: all
	-export USER_MODULES=$(USER_MODULES) && \
	cd $(OUTDIR) && \
	make && \
	sudo make install