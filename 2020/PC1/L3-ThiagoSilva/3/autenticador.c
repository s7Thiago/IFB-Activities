#include "autenticador.h"

// Retorna 1 se a letra for maúscula, ou 0 se for minúscula
int letterCase(int letter) {
	if (letter >= 'A' && letter <= 'Z') {
      		return 1;
      	} else {
      		return 0;
    }
}

// Retorna 1 se o caractere for um número, ou 0 caso contrário
int isNumber(int character) {
	if (character >= '0' && character <= '9') {
      		return 1;
      	} else {
      		return 0;
    }
}

// Retorna a quantidade de letras maiúsculas numa string
int contar_maiusculas(char* target){
	int qtde = 0;
	for (int i = 0; i < strlen(target); i++){
		if(letterCase(target[i]) > 0) {
			qtde++;
		}
	}
	
	return qtde;
}

// Retorna a quantidade de letras minúsculas numa string
int contar_minusculas(char* target){
	int qtde = 0;
	for (int i = 0; i < strlen(target); i++){
		if(letterCase(target[i]) == 0) {
			qtde++;
		}
	}
	
	return qtde;
}

int contar_numeros(char* target) {
	int qtde = 0;
	for (int i = 0; i < strlen(target); i++){
		//printf("contar_numeros: %c ( %d )", target[i], isNumber(target[i]));
		if(isNumber(target[i]) > 0) {
			qtde++;
			//printf("<é número>");
		}
		
		//printf("\n");
	}
	
	return qtde;
}

int validaSenha(char* target){
	if(strlen(target) >= 8){
		if(contar_maiusculas(target) > 0) {
			if(contar_minusculas(target) > 0) {
				if (contar_numeros(target) > 0) {
					printf("\nSenha cadastrada com sucesso!\n");
					return 1;
				} //else printf("falha:  %s não tem números", target);
			} //else printf("falha:  %s não tem minúsculas", target);
		} //else printf("falha:  %s não tem maiúsculas", target);
	} //else printf("falha: %s < 8", target);
	
	//printf("\n%s não é uma senha válida\n\n", target);
	return 0;
}
