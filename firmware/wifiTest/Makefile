
# sudo chmod a+wrx /dev/maple && sudo chmod a+wrx /dev/ttyACM0

LIBDIR = ../libs
OUTDIR = ./build

USER_MODULES="./libraries/sdfat ./libraries/usbMassStorage ./libraries/mrf24w"

all: libmaple sdfat usbMassStorage mrf24w source
	-cd $(OUTDIR) && \
	 export GLOBAL_CFLAGS="-DDEBUG_SDFAT=Serial1" && \
	 export USER_MODULES=$(USER_MODULES) && \
	 make BOARD=maple_mini MEMORY_TARGET=jtag

clean:
	-rm -rf $(OUTDIR)

outdir:
	-mkdir -p $(OUTDIR)

libmaple:
	-rsync -a $(LIBDIR)/libmaple/ $(OUTDIR)

sdfat:
	-rsync -a --exclude=.git $(LIBDIR)/sdfat/maple-sdfat/ $(OUTDIR)/libraries/sdfat

usbMassStorage:
	-rsync -a --exclude=.git $(LIBDIR)/usbMassStorage/ $(OUTDIR)/libraries/usbMassStorage

mrf24w:
	-rsync -a --exclude=.git $(LIBDIR)/mrf24w/ $(OUTDIR)/libraries/mrf24w

source:
	-rsync -a --exclude=build --exclude=nbproject --exclude=Makefile . $(OUTDIR)

install: all
	cd $(OUTDIR) && \
	sudo make install
