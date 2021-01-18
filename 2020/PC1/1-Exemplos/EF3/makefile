all: rm principal clear run

principal: compila_turma
	gcc principal.c turma.o alunos.o -o programa

compila_turma: compila_alunos
	gcc -c turma.c
	
compila_alunos:
	gcc -c alunos.c
	
run:
	./programa
	
rm: rmo rmain

rmo:
	rm *.o
	
rmain:
	rm programa

clear:
	clear
