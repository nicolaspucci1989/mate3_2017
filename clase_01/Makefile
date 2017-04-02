CC = gcc
CFLAGS = -Wall

clase01: main.o funciones.o
	$(CC) $(CFLAGS) -o clase01 main.o funciones.o

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

funciones.o: funciones.c header.h
	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm *.exe *.o
