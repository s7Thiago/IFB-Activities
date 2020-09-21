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

void showMenu(char menu[][MAIN_MENU_CHARACTERS_LIMIT]){
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
	strcpy(produtos[0].country, "Brasioe");
	produtos[0].qtde = 123;
	generateProductCode(code, produtos[0].country, 1);
	strcpy(produtos[0].code, code);
	
	//
	strcpy(produtos[1].name, "Smartwatch");
	strcpy(produtos[1].country, "China");
	produtos[1].qtde = 456;
	generateProductCode(code, produtos[1].country, 2);
	strcpy(produtos[1].code, code);
	
	//
	strcpy(produtos[2].name, "Perfume");	
	strcpy(produtos[2].country, "Alemanha");
	produtos[2].qtde = 789;
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
	
	for (int i = 0; i < PRODUCT_LIST_SIZE; i++){
		if(produtos[i].code[0] != '\0'){
		productIndex++;
		}	
	}
	
	return productIndex;
}

// Mostra os detalhes de todos os produtos inseridos
void allProducts() {
	printf("\n\n");
	for (int i = 0; i < PRODUCT_LIST_SIZE; i++){
		if(produtos[i].code[0] != '\0'){
			printf("===== %s [ %s ]\nCountry: %s\nQuantity: %d\n\n",
				produtos[i].name, 
				produtos[i].code,
				produtos[i].country,
				produtos[i].qtde);
		}	
	}
}

// Retorna o índice do produto se existir, caso contrário retorna -1
int getProductIndexFromCode(char* searchedCode){
	int index = -1;
	
	for (int i = 0; i < PRODUCT_LIST_SIZE; i++){
		if(strcmp(searchedCode, produtos[i].code) == 0){
			return i;
		}
	}
	return index;
}


void newProduct(){
	char name[PRODUCT_NAME_SIZE];
	char country[PRODUCT_NAME_SIZE];
	int qtde;
	char code[PRODUCT_CODE_SIZE];

	// Cadastrando produtos para teste
	mockProducts();
	
	// Mostra detalhes de todos os produtos cadastrados
	allProducts();
	
	// Pegando o indice do ultimo produto cadastrado
	int lastProdIndex = lastProductIndex() + 1;
	
	// Recebendo os dados do novo produto
	printf("	Nome > ");
	scanf("%s", name);
	
	printf("	País > ");
	scanf("%s", country);
	getchar();
	
	printf("	Quantidade > ");
	scanf("%d", &qtde);
	
	//Atribuindo dados
	produto newProduct;
	
	strcpy(newProduct.name, name);
	newProduct.qtde = qtde;
	strcpy(newProduct.country, country);
	
	// atribuindo o código ao produto em questão
	generateProductCode(code, country, lastProdIndex);
	
	
	//Removendo 3 caracteres finais desnecessários do codigo
	for (int i = PRODUCT_CODE_SIZE; i < PRODUCT_CODE_SIZE + 3;i++){
		code[i] = '\0';
	}
	
	strcpy(newProduct.code, code);
	
	//Inserindo o produto na lista
	produtos[lastProdIndex] = newProduct;
	
	// Mostra detalhes de todos os produtos cadastrados
	allProducts();
}

void updateProduct(){
	char localCode[PRODUCT_CODE_SIZE];
	int productIndex;
	
	// Cadastrando produtos para teste
	mockProducts();
	
	// Mostra detalhes de todos os produtos cadastrados
	allProducts();
	
	// Recebendo o código
	printf("Código > ");
	scanf("%s", localCode);
	
	// Procurando o índice
	productIndex = getProductIndexFromCode(localCode);
	
	if(productIndex != -1) {
		showMenu(updateProductInfoMenu);
		printf("	Escolha > ");
		scanf("%d", &updateProductOptions);
		
	} else {
		printf("\nCódigo inválido!\n");
	}
}



































