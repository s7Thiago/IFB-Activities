all: rm build run

build: utils
	gcc main.c utils.o hybrid_merge_sort.o insertion_sort.o -o setup

utils: hybrid_method
	gcc -c utils.c
	
hybrid_method: insertion
	gcc -c hybrid_merge_sort.c
	
insertion:
	gcc -c insertion_sort.c
	
	
clear:
	clear
	
rm: rmo rmain

run: clear
	./setup

rmo:
	rm *.o
	
rmain:
	rm setup
