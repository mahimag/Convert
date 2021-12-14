CC=gcc
CFLAGS=-I. -g
DEPS =
OBJ = convert.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

default: $(OBJ)
	$(CC) -o convert $^ $(CFLAGS)

clean:
	rm -f *.o *.out

run: default
	./convert
