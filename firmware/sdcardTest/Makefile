
# sudo chmod a+wrx /dev/maple && sudo chmod a+wrx /dev/ttyACM0

LIBDIR = ../libs
OUTDIR = ./build

USER_MODULES=./libraries/sdcard

all: libmaple sdcard source
	-cd $(OUTDIR) && export USER_MODULES=$(USER_MODULES) && make

clean:
	-rm -rf $(OUTDIR)

outdir:
	-mkdir -p $(OUTDIR)

libmaple:
	-rsync -a $(LIBDIR)/libmaple/ $(OUTDIR)

sdcard:
	-rsync -a $(LIBDIR)/sdcard/ $(OUTDIR)/libraries/sdcard

source:
	-rsync -a --exclude=build --exclude=nbproject --exclude=Makefile . $(OUTDIR)

install: all
	-export USER_MODULES=$(USER_MODULES) && \
	cd $(OUTDIR) && \
	make && \
	sudo make install