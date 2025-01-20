# Makefile for sample programs

CC=gcc
CFLAGS := -Wall -Wstrict-prototypes -O2 -m64 -I../../../include64

aiio.so: 7230test.o
	gcc -shared -o aiio.so 7230test.o -lpci_dask64 -fPIC

7230test.o: 7230test.c
	gcc -c $(CFLAGS) 7230test.c

clean:
	rm -f 7230test *.o *~
