all: rm build clear run

build: turma.o
	gcc principal.c turma.o alunos.o -o setup

turma.o: alunos.o
	gcc -c turma.c

alunos.o:
	gcc -c alunos.c

rm: rmo rmain

cls: rm clear
	
rmo:
	rm *.o
	
rmain:
	rm setup
	
run:
	./setup
	
clear:
	clear
