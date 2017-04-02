CC = gcc
CFLAGS = -Wall

clase1: dominio_de_relacion.o funciones.o
	$(CC) $(CFLAGS) -o clase1 dominio_de_relacion.o funciones.o

dominio_de_relacion.o: dominio_de_relacion.c header.h
	$(CC) $(CFLAGS) -c dominio_de_relacion.c

funciones.o: funciones.c header.h
	$(CC) $(CFLAGS) -c funciones.c

clean:
	rm *.exe *.o
