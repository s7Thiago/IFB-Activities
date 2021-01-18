#include "autenticador.h"

int main (void) {
	int isPasswordValid = 0;
	int loopCount = 0;
	
	do{
	
	char input[MAX];
	
	if(loopCount < 1)
	printf("Senha > ");
	
	scanf("%s", input);
	
	isPasswordValid = validaSenha(input);
	loopCount++;
	
	}while(isPasswordValid != 1);
	
	return 0;
}

