all: rm build run

build: xmlparser
	gcc main.c xmlParser.o fileOperations.o -o setup

xmlparser: fileoperations
	gcc -c xmlParser.c

fileoperations:
	gcc -c fileOperations.c

clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
