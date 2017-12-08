CFLAGS=-Wall -Wextra -pedantic -m32
OBJS=kernel.o libme.o

all: $(OBJS)

%.o: %.c $(DEPS)
	gcc $(CFLAGS) $< -c -o $@

clean:
	rm -f *.o
