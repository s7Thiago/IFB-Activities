all: rm build run

build: lista_encadeada
	gcc main.c alloc.o lista_encadeada.o pilha.o -o setup

lista_encadeada: pilha
	gcc -c lista_encadeada.c

pilha: alloc
	gcc -c pilha.c
	
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
