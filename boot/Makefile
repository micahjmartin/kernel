AFLAGS=-f elf32
OBJS=bootloader.o

all: $(OBJS)

%.o: %.asm
	nasm $(AFLAGS) $< -o $@
clean:
	rm -f *.o
