CFLAGS=-Wall -Wextra -pedantic -m32
AFLAGS=-f elf32
LDFLAGS=-m elf_i386
OBJS=kernel.o libme.o

all: link clean

%.o: %.c $(DEPS)
	gcc $(CFLAGS) $< -c -o $@
%.o: %.asm
	nasm $(AFLAGS) $< -o $@

link: grub.o $(OBJS)
	ld -T link.ld $(LDFLAGS) -o kernel.bin grub.o $(OBJS)

run:
	qemu-system-i386 -kernel kernel.bin

clean:
	rm -f *.o
