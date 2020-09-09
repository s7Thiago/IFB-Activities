all: rm main clear run

main: turma.o
	gcc principal.c turma.o alunos.o -o setup

turma.o: alunos.o
	gcc -c turma.c

alunos.o:
	gcc -c alunos.c

rm: rmo rmain
	
rmo:
	rm *.o
	
rmain:
	rm setup
	
run:
	./setup
	
clear:
	clear
	
	
