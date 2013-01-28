PREFIX := arm-none-eabi-

.PHONY: all clean

all: build/blink.bin

build/blink.o: mkdirs blink.c
	$(PREFIX)gcc -mcpu=cortex-m3 -mthumb -c -fno-common -O0 -g blink.c -nostartfiles -o build/blink.o

build/blink.out: build/blink.o stm32f103vet6.ld
	$(PREFIX)ld -T stm32f103vet6.ld -o build/blink.out build/blink.o

build/blink.bin: build/blink.out
	$(PREFIX)objcopy -O binary build/blink.out build/blink.bin
	$(PREFIX)objdump -S build/blink.out > build/blink.list

mkdirs:
	mkdir -p build

clean:
	rm -rf build

