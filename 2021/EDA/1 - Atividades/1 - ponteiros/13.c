/*
Elabore uma func¸ao que receba duas strings como parametros e verifique se a segunda
string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres
das strings.
*/

#include <stdio.h>
#include <string.h>

int aHaveB(char* a, char* b){
	int index = 0, sizeB = 0, sizeA = 0, contOcurrences = 0;

//	descobrindo o tamanho de b
	while(b[sizeB] != '\0')
		sizeB++;
		
//	descobrindo o tamanho de a
	while(a[sizeA] != '\0')
		sizeA++;
	
	
	for(int i = 0; i < sizeA; i++){
	
		char *aux = "\0", auxChar[2];
		for(int j = 0; j < sizeB; i++){
			auxChar[0] = a[j];
			auxChar[1] = '\0';
			strcpy(aux, auxChar);
		}
		
		if(strcmp(aux, b) > 0)
				contOcurrences++;
				
		auxChar[0] = '\0';
		auxChar[1] = '\0';
	}
	
	printf("ocurrences: %d\n\n", contOcurrences);
}


int main (void) {	
	
	char* a = "ifb2021";
	char* b = "ifb";
	
	aHaveB(a, b);

	return 0;
}
































