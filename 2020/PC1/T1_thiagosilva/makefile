all: rm build run

build: produto
	gcc main.c produto.o crud.o -o setup

produto: crud
	gcc -c produto.c
	

crud:
	gcc -c crud.c
	
clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
