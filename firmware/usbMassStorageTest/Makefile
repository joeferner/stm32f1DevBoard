
# sudo chmod a+wrx /dev/maple && sudo chmod a+wrx /dev/ttyACM0

LIBDIR = ../libs
OUTDIR = ./build

USER_MODULES="./libraries/sdcard ./libraries/usbMassStorage"

all: libmaple sdcard usbMassStorage source
	-cd $(OUTDIR) && export USER_MODULES=$(USER_MODULES) && make

clean:
	-rm -rf $(OUTDIR)

outdir:
	-mkdir -p $(OUTDIR)

libmaple:
	-rsync -a $(LIBDIR)/libmaple/ $(OUTDIR)
	-cp $(LIBDIR)/libmaple.patch $(OUTDIR)
	-cd $(OUTDIR) && patch -p0 -f < libmaple.patch

sdcard:
	-rsync -a --exclude=.git $(LIBDIR)/sdcard/ $(OUTDIR)/libraries/sdcard

usbMassStorage:
	-rsync -a --exclude=.git $(LIBDIR)/usbMassStorage/ $(OUTDIR)/libraries/usbMassStorage

source:
	-rsync -a --exclude=build --exclude=nbproject --exclude=Makefile . $(OUTDIR)

install: all
	-export USER_MODULES=$(USER_MODULES) && \
	cd $(OUTDIR) && \
	make && \
	sudo make install