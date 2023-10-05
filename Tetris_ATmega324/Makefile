all: main.hex

main.elf: main.c nokia5110.c tetris.c
	avr-g++ -mmcu=atmega324p -DF_CPU=16000000 -Wall -Os -o $@ $^

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size main.elf

clean:
	rm -rf main.elf main.hex

.PHONY: all clean

