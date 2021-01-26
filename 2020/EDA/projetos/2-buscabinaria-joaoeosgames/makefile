all: rm build run

build: search
	gcc main.c util.o game.o search.o -o setup

search: game
	gcc -c search.c
	
game: util
	gcc -c game.c
	
util:
	gcc -c util.c
	
clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
