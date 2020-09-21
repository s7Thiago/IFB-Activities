#include "produto.h"

// Converte letra maiúscula em minúscula
char lowerToUpperChar(char target){

	char result = target;
	
	if(target > 96 && target < 123) result = target - 32;

	return result;

}

//Converte o inteiro num para String e armazena em str
void toString(char str[], int num) {
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void generateProductCode(char target[], char* country, int productIndex){
	
	char code[PRODUCT_CODE_SIZE];
	
	//Limpando code;
	for (int i = 0; i < PRODUCT_CODE_SIZE; i++){
		code[i] = '\0';
	}
	
	// Extraindo os 2 primeiros caracteres do país
	char pp[3];
	pp[0] = lowerToUpperChar(country[0]);
	pp[1] = lowerToUpperChar(country[1]);
	pp[2] = '\0';
	
	// Inserindo o resultado da operação anterior no código
	strcat(code, pp);
	strcat(code, "IFB");
	
	//Anexando o indice do produto recebido ao codigo
	char aux[2];
	
	toString(aux, productIndex); // convertendo o indece para string e armazenando em aux
		
	if(productIndex < 10) strcat(code, "00");
	if(productIndex < 100 && productIndex > 9)strcat(code, "0");
	strcat(code, aux);
	
	//Copiando o conteúdo de code para target
	for (int j = 0; j < PRODUCT_CODE_SIZE; j++){
		target[j] = code[j];
	}
}





































