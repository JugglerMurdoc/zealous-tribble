CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=read

all: $(EXEC)

read: global.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: global.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
