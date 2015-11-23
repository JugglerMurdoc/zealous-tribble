CC=gcc
CFLAGS=-W -Wall -ansi -g  -lm
LDFLAGS=
EXEC=read

all: $(EXEC)

read: global.o main.o trace_line.o tracer.o trace_ids.o links_tracer.o
	$(CC) -o $@ $^ $(LDFLAGS) -lm

main.o: global.h trace_line.h tracer.h trace_ids.h links_tracer.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
