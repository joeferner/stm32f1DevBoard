
OUTDIR = ./build

CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
CP = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump

CFLAGS = -I. -c -fno-common -O0 -g -mcpu=cortex-m3 -mthumb
LFLAGS  = -Tstm32.ld -nostartfiles
CPFLAGS = -Obinary
ODFLAGS = -S

_OBJ = main.o 
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ))

all: copy

clean:
	-rm -rf $(OUTDIR)

copy: main.elf
	$(CP) $(CPFLAGS) $(OUTDIR)/main.elf $(OUTDIR)/main.bin
	$(OD) $(ODFLAGS) $(OUTDIR)/main.elf > $(OUTDIR)/main.list

main.elf: $(OBJ)
	$(LD) $(LFLAGS) -o $(OUTDIR)/main.elf $(OUTDIR)/main.o

outdir:
	-mkdir -p $(OUTDIR)

$(OUTDIR)/%.o: %.cpp outdir
	$(CC) $(CFLAGS) $< -o $@
  
flash: all
	stm32flash -w $(OUTDIR)/main.bin -v -g 0x0 /dev/ttyS0
