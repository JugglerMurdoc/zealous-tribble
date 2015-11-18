CC=gcc
CFLAGS=-W -Wall -ansi -g
LDFLAGS=
EXEC=read

all: $(EXEC)

read: global.o main.o trace_line.o tracer.o trace_ids.o
	$(CC) -lm -o $@ $^ $(LDFLAGS)

main.o: global.h trace_line.h tracer.h trace_ids.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
