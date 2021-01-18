all: rm build run

build: bublesort
	gcc main.c bublesort.o -o setup

bublesort:
	gcc -c bublesort.c
	
clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
