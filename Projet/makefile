CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=read

all: $(EXEC)

read: global.o main.o trace_line.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: global.h trace_line.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
