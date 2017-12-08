CFLAGS=-Wall -Wextra -pedantic -m32
AFLAGS=-f elf32
LDFLAGS=-m elf_i386
DIRS := boot src
all: make_all objs link clean

make_all: 
	+$(MAKE) -C boot
	+$(MAKE) -C src

objs:
	$(eval OBJS := $(foreach d,$(DIRS),$(wildcard $(d)/*.o)))

link:
	ld -T boot/link.ld $(LDFLAGS) -o bin/kernel.bin $(OBJS)

run:
	qemu-system-i386 -kernel bin/kernel.bin

clean:
	+$(MAKE) -C boot clean
	+$(MAKE) -C src clean

