
OUTDIR = ./build

CC = arm-none-eabi-g++
LD = arm-none-eabi-g++
CP = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump

CFLAGS = -I. -I../uip/uip/ -c -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -fno-exceptions
LFLAGS  = \
  -L/opt/arm-linaro-eabi-4.6/arm-none-eabi/lib/thumb/cortex-m3/ \
  -L/opt/arm-linaro-eabi-4.6/lib/gcc/arm-none-eabi/4.6.2/thumb/cortex-m3/ \
  -lgcc -lc \
  -T../stm32.ld -nostartfiles
CPFLAGS = -Obinary
ODFLAGS = -S

_UIP_OBJ = timer.o uip.o
UIP_OBJ = $(patsubst %,$(OUTDIR)/uip/%,$(_UIP_OBJ))

_OBJ = main.o stack.o g2100.o clock-arch.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ))

all: copy

clean:
	-rm -rf $(OUTDIR)

copy: main.elf
	$(CP) $(CPFLAGS) $(OUTDIR)/main.elf $(OUTDIR)/main.bin
	$(OD) $(ODFLAGS) $(OUTDIR)/main.elf > $(OUTDIR)/main.list

main.elf: $(OBJ) $(UIP_OBJ)
	$(LD) $(LFLAGS) -o $(OUTDIR)/main.elf $(OBJ) $(UIP_OBJ)

outdir:
	-mkdir -p $(OUTDIR)
	-mkdir -p $(OUTDIR)/uip

$(OUTDIR)/%.o: %.cpp outdir
	$(CC) $(CFLAGS) $< -o $@

$(OUTDIR)/%.o: %.c outdir
	$(CC) $(CFLAGS) $< -o $@

$(OUTDIR)/uip/%.o: ../uip/uip/%.c outdir
	$(CC) $(CFLAGS) $< -o $@
	
flash: all
	stm32flash -w $(OUTDIR)/main.bin -v -g 0x0 /dev/ttyS0
