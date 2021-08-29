all: rm build run

build: fila_lista
	gcc main.c alloc.o fila_lista.o -o setup

fila_lista: alloc
	gcc -c fila_lista.c

	
alloc:
	gcc -c alloc.c
	
clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
