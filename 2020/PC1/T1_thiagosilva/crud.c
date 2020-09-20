#include "crud.h"
#include "produto.h"

int option = 0;
char mainMenu[][MAIN_MENU_CHARACTERS_LIMIT] = {
	"1 - Cadastrar novo produto;",
	"2 - Atualizar informações de um produto;",
	"3 - Vender produto;",
	"4 - Consultar informações de um produto;",
	"5 - Consultar quantidade de todos os produtos;",
	"6 - Finalizar programa;",
};

int updateProductOptions = 0;
char updateProductInfoMenu[][MAIN_MENU_CHARACTERS_LIMIT] = {
	"	1 - Alterar nome;",
	"	2 - Alterar país de origem;",
	"	3 - Adicionar mais itens;",
};

void showMainMenu(char menu[][MAIN_MENU_CHARACTERS_LIMIT]){
	for (int i = 0; i < MAIN_MENU_OPTIONS_LIMIT; i++){
		printf("%s\n", menu[i]);
	}
}

//limpa uma string
void cleanString(char* str, int size) {
	for (int i = 0; i < size; i++){
		str[i] = '\0';
	}
}

// Cadastra informações de produtos para fins de teste
void mockProducts(){
	char code[8];

	//
	strcpy(produtos[0].name, "Leite");
	strcpy(produtos[0].country, "Brasil");
	produtos[0].qtde = 150;
	generateProductCode(code, produtos[0].country, 1);
	strcpy(produtos[0].code, code);
	
	//
	strcpy(produtos[1].name, "Smartwatch");
	strcpy(produtos[1].country, "China");
	produtos[1].qtde = 150;
	generateProductCode(code, produtos[1].country, 2);
	strcpy(produtos[1].code, code);
	printf("Testando quantidade: %d", produtos[1].qtde);/////////////////
	
	//
	strcpy(produtos[2].name, "Perfume");	
	strcpy(produtos[2].country, "Alemanha");
	produtos[2].qtde = 150;
	generateProductCode(code, produtos[2].country, 3);
	strcpy(produtos[2].code, code);
	
	/*//
	strcpy(produtos[3].name, "Smartphone");
	strcpy(produtos[3].country, "China");
	produtos[3].qtde = 150;
	generateProductCode(code, produtos[3].country, 4);
	strcpy(produtos[3].code, code);
	
	//
	strcpy(produtos[4].name, "SSD");
	strcpy(produtos[4].country, "Egito");
	produtos[4].qtde = 150;
	generateProductCode(code, produtos[4].country, 5);
	strcpy(produtos[4].code, code);*/
}

int lastProductIndex(){
	int productIndex = 0;
	
	for (int i = 0; i < PRODUCT_LIST_SIZE - 990; i++){
		if(produtos[i].code[0] != '\0'){
		productIndex++;
		}	
	}
	
	return productIndex;
}

// Mostra os detalhes de todos os produtos inseridos
void allProducts() {
	printf("\n\n");
	for (int i = 0; i < PRODUCT_LIST_SIZE - 990; i++){
		if(produtos[i].code[0] != '\0'){
			printf("===== %s [ %s ]\nCountry: %s\nQuantity: %d\n\n",
				produtos[i].name, 
				produtos[i].code,
				produtos[i].country,
				produtos[i].qtde);
		}	
	}
}

void newProduct(){

	// Cadastrando produtos para teste
	mockProducts();
	int lastProdIndex = lastProductIndex();
	
	allProducts();
	
	
	
}



































