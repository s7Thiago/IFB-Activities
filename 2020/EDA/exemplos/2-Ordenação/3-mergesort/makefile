all: rm build run

build: mergesort
	gcc main.c alloc.o mergesort.o -o setup

mergesort: alloc
	gcc -c mergesort.c
	
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
