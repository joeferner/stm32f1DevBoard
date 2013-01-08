
OUTDIR = ./build

CC = arm-none-eabi-g++
LD = arm-none-eabi-g++
CP = arm-none-eabi-objcopy
OD = arm-none-eabi-objdump

CFLAGS = -DSTM32F103x -DSTM32_SYSCLK=72000000 -DSTM32_FPCLK2=72000000 -I. -I../lib/ -I../lib/uip/uip/ -I../lib/sdcard/ -c -fno-common -O0 -g -mcpu=cortex-m3 -mthumb -fno-exceptions
LFLAGS  = \
  -L/opt/arm-linaro-eabi-4.6/arm-none-eabi/lib/thumb/cortex-m3/ \
  -L/opt/arm-linaro-eabi-4.6/lib/gcc/arm-none-eabi/4.6.2/thumb/cortex-m3/ \
  -lgcc -lc \
  -T../stm32.ld -nostartfiles
CPFLAGS = -Obinary
ODFLAGS = -S

_LIB_OBJ = spi.o usart.o delay.o gpio.o
LIB_OBJ = $(patsubst %,$(OUTDIR)/lib/%,$(_LIB_OBJ))

_UIP_OBJ = timer.o uip.o
UIP_OBJ = $(patsubst %,$(OUTDIR)/lib/uip/%,$(_UIP_OBJ))

_SDCARD_OBJ = sdcard.o
SDCARD_OBJ = $(patsubst %,$(OUTDIR)/lib/sdcard/%,$(_SDCARD_OBJ))

_OBJ = main.o
OBJ = $(patsubst %,$(OUTDIR)/%,$(_OBJ))

all: copy

clean:
	-rm -rf $(OUTDIR)

copy: main.elf
	$(CP) $(CPFLAGS) $(OUTDIR)/main.elf $(OUTDIR)/main.bin
	$(OD) $(ODFLAGS) $(OUTDIR)/main.elf > $(OUTDIR)/main.list

main.elf: $(OBJ) $(LIB_OBJ) $(SDCARD_OBJ)
	$(LD) $(LFLAGS) -o $(OUTDIR)/main.elf $(OBJ) $(LIB_OBJ) $(SDCARD_OBJ)

outdir:
	-mkdir -p $(OUTDIR)
	-mkdir -p $(OUTDIR)/lib
	-mkdir -p $(OUTDIR)/lib/uip
	-mkdir -p $(OUTDIR)/lib/sdcard

$(OUTDIR)/%.o: %.cpp outdir
	$(CC) $(CFLAGS) $< -o $@

$(OUTDIR)/%.o: %.c outdir
	$(CC) $(CFLAGS) $< -o $@

$(OUTDIR)/lib/%.o: ../lib/%.c outdir
	$(CC) $(CFLAGS) $< -o $@

$(OUTDIR)/lib/uip/%.o: ../lib/uip/uip/%.c outdir
	$(CC) $(CFLAGS) $< -o $@

$(OUTDIR)/lib/sdcard/%.o: ../lib/sdcard/%.c outdir
	$(CC) $(CFLAGS) $< -o $@
	
flash: all
	stm32flash -w $(OUTDIR)/main.bin -v -g 0x0 /dev/ttyS0

