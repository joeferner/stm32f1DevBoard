
LIBDIR = ../libs
OUTDIR = ./build

all: libmaple source
	-cd $(OUTDIR) && make

clean:
	-rm -rf $(OUTDIR)

outdir:
	-mkdir -p $(OUTDIR)

libmaple:
	-rsync -a $(LIBDIR)/libmaple/ $(OUTDIR)

source:
	-rsync -a --exclude=build --exclude=nbproject --exclude=Makefile . $(OUTDIR)

install: all
	-cd $(OUTDIR) && sudo make install && sudo chmod a+wrx /dev/maple && sudo chmod a+wrx /dev/ttyACM0
