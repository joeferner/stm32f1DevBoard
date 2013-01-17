
# sudo chmod a+wrx /dev/maple && sudo chmod a+wrx /dev/ttyACM0

LIBDIR = ../libs
OUTDIR = ./build

USER_MODULES="./libraries/sdcard ./libraries/usbMassStorage"

all: libmaple sdcard usbMassStorage source
	-cd $(OUTDIR) && \
	 export GLOBAL_CFLAGS="-DDISABLE_SERIALUSB -DDEBUG_SDCARD=Serial1" && \
	 export USER_MODULES=$(USER_MODULES) && \
	 make

clean:
	-rm -rf $(OUTDIR)

outdir:
	-mkdir -p $(OUTDIR)

libmaple:
	-rsync -a $(LIBDIR)/libmaple/ $(OUTDIR)

sdcard:
	-rsync -a --exclude=.git $(LIBDIR)/sdcard/ $(OUTDIR)/libraries/sdcard

usbMassStorage:
	-rsync -a --exclude=.git $(LIBDIR)/usbMassStorage/ $(OUTDIR)/libraries/usbMassStorage

source:
	-rsync -a --exclude=build --exclude=nbproject --exclude=Makefile . $(OUTDIR)

install: all
	cd $(OUTDIR) && \
	sudo make install
