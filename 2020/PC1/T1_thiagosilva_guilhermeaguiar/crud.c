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
	"\t1 - Alterar nome:",
	"\t2 - Alterar país de origem:",
	"\t3 - Adicionar mais itens:",
};

void showMenu(char menu[][MAIN_MENU_CHARACTERS_LIMIT], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", menu[i]);
	}
}

//limpa uma string
void cleanString(char *str, int size)
{
	for (int i = 0; i < size; i++)
	{
		str[i] = '\0';
	}
}

// Cadastra informações de produtos para fins de teste
void mockProducts()
{
	char code[8];

	//
	strcpy(produtos[0].name, "Leite");
	strcpy(produtos[0].country, "Brasil");
	produtos[0].qtde = 123;
	generateProductCode(code, produtos[0].country, 1);
	strcpy(produtos[0].code, code);

	// //
	strcpy(produtos[1].name, "Smartwatch");
	strcpy(produtos[1].country, "China");
	produtos[1].qtde = 456;
	generateProductCode(code, produtos[1].country, 2);
	strcpy(produtos[1].code, code);

	// //
	strcpy(produtos[2].name, "Perfume");
	strcpy(produtos[2].country, "Alemanha");
	produtos[2].qtde = 789;
	generateProductCode(code, produtos[2].country, 3);
	strcpy(produtos[2].code, code);

	//
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
	strcpy(produtos[4].code, code);
}

int lastProductIndex()
{
	int productIndex = 0;

	for (int i = 0; i < PRODUCT_LIST_SIZE; i++)
	{
		if (produtos[i].code[0] != '\0')
		{
			productIndex++;
		}
	}

	return productIndex;
}

// Mostra os detalhes de todos os produtos inseridos
void allProducts()
{
	printf("\n\n");
	for (int i = 0; i < PRODUCT_LIST_SIZE; i++)
	{
		if (produtos[i].code[0] != '\0')
		{
			printf("===== %s [ %s ]\nCountry: %s\nQuantity: %d\n\n",
				   produtos[i].name,
				   produtos[i].code,
				   produtos[i].country,
				   produtos[i].qtde);
		}
	}
}

// Retorna o índice do produto se existir, caso contrário retorna -1
int getProductIndexFromCode(char *searchedCode)
{
	int index = -1;

	for (int i = 0; i < PRODUCT_LIST_SIZE; i++)
	{
		if (strcmp(searchedCode, produtos[i].code) == 0)
		{
			return i;
		}
	}
	return index;
}

void newProduct()
{
	char name[PRODUCT_NAME_SIZE];
	char country[PRODUCT_NAME_SIZE];
	int qtde;
	char code[PRODUCT_CODE_SIZE];

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

	//Removendo 3 caracteres finais desnecessários do código
	for (int i = PRODUCT_CODE_SIZE; i < PRODUCT_CODE_SIZE + 3; i++)
	{
		code[i] = '\0';
	}

	strcpy(newProduct.code, code);

	//Inserindo o produto na lista
	produtos[lastProdIndex] = newProduct;
}

void updateProduct()
{
	char localCode[PRODUCT_CODE_SIZE];
	char name[PRODUCT_NAME_SIZE];
	char country[PRODUCT_NAME_SIZE];
	int qtdeAdd = 0;
	int productIndex;
	//
	char trailing[6];

	// Cadastrando produtos para teste
	mockProducts();

	// Mostra detalhes de todos os produtos cadastrados
	allProducts();

	// Recebendo o código
	printf("Código > ");
	scanf("%s", localCode);

	// Procurando o índice
	productIndex = getProductIndexFromCode(localCode);

	if (productIndex != -1)
	{
		showMenu(updateProductInfoMenu, 3);
		printf("\tEscolha > ");
		scanf("%d", &updateProductOptions);

		switch (updateProductOptions)
		{
		case 1: // Alterar nome

			// Recebendo o código
			printf("\tNovo nome > ");
			scanf("%s", name);

			//Limpando o valor antigo
			for (int i = 0; i < strlen(produtos[productIndex].name); i++)
			{
				produtos[productIndex].name[i] = '\0';
			}

			//Cadastrando o nome
			strcpy(produtos[productIndex].name, name);
			break;

		case 2: // Alterar país de origem
			printf("\tNova origem > ");
			scanf("%s", country);

			// A alteração só acontece se a nova origem for diferente da antiga
			if (strcmp(country, produtos[productIndex].country) != 0)
			{

				//Limpando o trailing
				cleanString(trailing, 6);

				// Salvando a parte que não vai mudar no novo código
				for (int i = 2; i < 8; i++)
				{

					trailing[i - 2] = produtos[productIndex].code[i];
				}

				//Removendo pare indevida do trailing
				for (int j = 6; j < (8 + strlen(country)); j++)
				{
					trailing[j] = '\0';
				}
			}

			// Extraindo os 2 primeiros caracteres do país
			char pp[3];
			pp[0] = lowerToUpperChar(country[0]);
			pp[1] = lowerToUpperChar(country[1]);
			pp[2] = '\0';

			strcat(pp, trailing);

			// Atribuindo o novo código
			strcpy(produtos[productIndex].code, pp);

			// Atribuindo o novo país
			cleanString(produtos[productIndex].country, strlen(produtos[productIndex].country));
			strcpy(produtos[productIndex].country, country); //Copia o novo país para a propriedade no produto

			break;

		case 3: // Adicionar mais itens
			printf("\tQuantidade > ");
			scanf("%d", &qtdeAdd);

			// Adicionando quantidade recebida
			produtos[productIndex].qtde += qtdeAdd;
			break;

		default:
			break;
		}
	}
	else
	{
		printf("\nCódigo inválido!\n");
	}
}

void subtrairquantidade(int qtde, int productIndex)
{

	produtos[productIndex].qtde -= qtde;

	if (produtos[productIndex].qtde == 0){
		cleanString(produtos[productIndex].name, strlen(produtos[productIndex].name));
		cleanString(produtos[productIndex].country, strlen(produtos[productIndex].country));
	
		

	}
}

// Vende um produto
void sellProduct()
{

	char Code[PRODUCT_CODE_SIZE];
	int productIndex;
	int qtde;
	mockProducts();

	printf("\tCodigo do Produto: ");
	scanf("%s", Code);

	productIndex = getProductIndexFromCode(Code);
	if (productIndex != -1)
	{

		do
		{
			printf("Digite a quantidade de itens vendidos: ");
			scanf("%d", &qtde);
			if (qtde > 0)
			{
				if (qtde > produtos[productIndex].qtde)
					printf("\tNão existem itens suficientes para este produto\n");
			}

			if (qtde < 0)
				printf("\tValor invalido,digite novamente\n");

		} while (qtde < 0 || qtde > produtos[productIndex].qtde);

		subtrairquantidade(qtde, productIndex);
	}
	else
	{
		printf("\n\tCódigo inválido!\n\n");
	}
}

// Imprimindo produtos encontrados
void imprimirProduto(int i)
{
	printf("\n");

	if (produtos[i].code[0] != '\0')
	{
		printf("\tNome do Produto: %s\n\tPais de Origem: %s\n\tQuantidade de Itens: %d\n\tCódigo: %s\n\n",
			   produtos[i].name,
			   produtos[i].country,
			   produtos[i].qtde, produtos[i].code);
	}
}

// Consulta um produto pelo código
void queryProduct()
{
	char Code[PRODUCT_CODE_SIZE];
	int productIndex;

	mockProducts();

	printf("\tCódigo do Produto: ");
	scanf("%s", Code);

	productIndex = getProductIndexFromCode(Code);

	if (productIndex != -1)
	{

		imprimirProduto(productIndex);
	}
	else
	{
		printf("\n\tCódigo inválido!\n\n");
	}
};

// Imprime o código e a quantidade de todos os produtos
void printCodeQt()
{
	printf("\n");
	for (int i = 0; i < PRODUCT_LIST_SIZE; i++)
	{
		if (produtos[i].code[0] != '\0')
		{
			printf("\t%s\t%d\n",
				   produtos[i].code,
				   produtos[i].qtde);
		}
	}
	printf("\n");
}

// Mostra detalhes de  todos os produtos
void consultAllProducts()
{
	mockProducts();
	printCodeQt();
};
