PASSOS PARA COMPILAR MANUALMETE:

PASSO 1 (Compilar separadamente os códigos ".c"):
	gcc -c arquivo1.c
	gcc -c arquivo2.c
	
PASSO 2 (Unir os objetos gerados):
	gcc arquivo1.o arquivi2.o <nome_executavel>
	
	exemplo:
		gcc main.o calc.o run
		
PASSO 3 (Executar o programa):
	basta digitar o segunte comando para executar o arquivo gerado pelo comando anterior:
		./<nome_executavel>
		
		exemplo:
			./run
