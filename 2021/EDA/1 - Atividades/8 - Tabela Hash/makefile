all: rm build run

build: tabela_hash
	gcc main.c tabela_hash.o -o setup

tabela_hash:
	gcc -c tabela_hash.c

clear:
	clear

rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o

rmain:
	rm setup
