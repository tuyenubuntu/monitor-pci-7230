# Makefile for sample programs

CC=gcc
CFLAGS := -Wall -Wstrict-prototypes -O2 -m64 -I../../../include64

monitor7230.so: monitor.o
	$(CC) -shared -o monitor7230.so monitor.o -lpci_dask64 -fPIC

monitor.o: monitor.c
	$(CC) -c $(CFLAGS) monitor.c -o monitor.o

clean:
	rm -f monitor7230.so *.o *~
