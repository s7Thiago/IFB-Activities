all: rm build run

build: insertionsort
	gcc main.c insertionsort.o -o setup

insertionsort:
	gcc -c insertionsort.c
	
clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
