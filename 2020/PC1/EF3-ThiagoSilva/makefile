all: rm principal clear run

principal: turma.o
	gcc principal.c turma.o alunos.o -o principal

turma.o: alunos.o
	gcc -c turma.c

alunos.o:
	gcc -c alunos.c

rm: rmo rmain
	
rmo:
	rm *.o
	
rmain:
	rm principal
	
run:
	./principal
	
clear:
	clear
	
	
