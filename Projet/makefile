CC=gcc
CFLAGS=-W -Wall -ansi
LDFLAGS=
EXEC=read

all: $(EXEC)

read: global.o main.o trace_line.o tracer.o 
	$(CC) -lm -o $@ $^ $(LDFLAGS)

main.o: global.h trace_line.h tracer.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
