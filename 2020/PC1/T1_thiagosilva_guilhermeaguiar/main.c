#include "produto.h"
#include "crud.h"

int main(void)
{
	init();

	extern int option;
	extern char mainMenu[][MAIN_MENU_CHARACTERS_LIMIT];
	extern char updateProductInfoMenu[][MAIN_MENU_CHARACTERS_LIMIT];

	do
	{
		showMenu(mainMenu, 6);

		printf("\nEscolha > ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			newProduct();
			break;

		case 2:
			updateProduct();

			break;

		case 3:
			sellProduct();
			break;

		case 4:
			//Função que consulta um produto pelo código
			queryProduct();

			break;

		case 5:
			//Função que consulta todos os produtos
			consultAllProducts();
			break;

		case 6:
			break;

			// Opções de teste
		case 7:
			mockProducts();
			//allProducts();
			break;

		case 8:
			allProducts();
			break;

		default:
			printf("\n\n	Invalid option\n\n");
		}

	} while (option != 6);

	return 0;
}
