all: rm build run

build: xmlparser
	gcc main.c xmlParser.o fileOperations.o htmlBuilder.o -o setup

xmlparser: fileoperations
	gcc -c xmlParser.c

fileoperations: htmlBuilder
	gcc -c fileOperations.c

htmlBuilder:
	gcc -c htmlBuilder.c

clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
