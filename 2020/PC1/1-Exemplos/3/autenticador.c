#include "autenticador.h"

char msgErro[50] = "\n\nSenha mal formada!\nDigite a senha novamente > ";

int contarMaiusculas(char* input){
	int qtde = 0;
	for (int i = 0; i < strlen(input); i++){
		if(input[i] >= 'A' && input[i] <= 'Z') {
			qtde++;
		}
	}
	
	return qtde;	
}

int contarMinusculas(char* input){
	int qtde = 0;
	for (int i = 0; i < strlen(input); i++){
		if(input[i] >= 'a' && input[i] <= 'z') {
			qtde++;
		}
	}
	
	return qtde;	
}

int contarNumeros(char* input){
	int qtde = 0;
	for (int i = 0; i < strlen(input); i++){
		if(input[i] >= '0' && input[i] <= '9') {
			qtde++;
		}
	}
	
	return qtde;	
}

int validaSenha(char input[20]){
	if(strlen(input) >= 8){
		if(contarMaiusculas(input) > 0){
			if(contarMinusculas(input) > 0){
				if(contarNumeros(input)){
				printf("\n\nSenha cadastrada com sucesso!\n\n");
					return 1;
				} else printf("%s", msgErro);
			} else printf("%s", msgErro);
		} else printf("%s", msgErro);
	} else printf("%s", msgErro);
	
	return 0;
}























