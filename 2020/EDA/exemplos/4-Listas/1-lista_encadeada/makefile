all: rm build run

build: lista_encadeada
	gcc main.c alloc.o lista_encadeada.o lista_duplamente_encadeada.o -o setup

lista_encadeada: lista_duplamente_encadeada
	gcc -c lista_encadeada.c

lista_duplamente_encadeada: alloc
	gcc -c lista_duplamente_encadeada.c
	
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
