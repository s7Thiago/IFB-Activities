#include "autenticador.h"

int main (void) {
	int loopCount = 0;
	int isPassValid = 0;

	do{
		char password[20];
	
		if(loopCount < 1) printf("Digite a senha > ");
		else printf("\n\nSenha mal formada!\nDigite a senha novamente > ");
	
		scanf("%s", password);
		
		loopCount++;
		isPassValid = validaSenha(password);
	
	
	} while(isPassValid != 1);
	
	return 0;
}
