all: rm build run

build: pilha_lista
	gcc main.c alloc.o pilha_lista.o -o setup

pilha_lista: alloc
	gcc -c pilha_lista.c

	
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
