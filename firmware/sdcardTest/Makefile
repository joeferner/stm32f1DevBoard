
LIBDIR = ../libs
OUTDIR = ./build

all: libmaple source

clean:
	-rm -rf $(OUTDIR)

outdir:
	-mkdir -p $(OUTDIR)

libmaple:
	-rsync -av $(LIBDIR)/libmaple $(OUTDIR)

source:
	-rsync -av --exclude=$(OUTDIR) . $(OUTDIR)