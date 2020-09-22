#include "produto.h"
#include "crud.h"

int main (void) {

	
	extern int option;
	extern char mainMenu[][MAIN_MENU_CHARACTERS_LIMIT];
	extern char updateProductInfoMenu[][MAIN_MENU_CHARACTERS_LIMIT];
	
	do{
		showMenu(mainMenu, 6);
	
		printf("\nEscolha > ");
		scanf("%d", &option);
	
		switch(option){
			case 1:
				newProduct();
			break;
		
			case 2:
				updateProduct();
				
			break;
			
			case 3:
			sellProdutct();
			break;
		
			case 4:
			//Função cosulta produto pelo codigo
			queryProduct();
				
			break;
		
			case 5:
			//Funcao Consulta todos os produtos
			consultAllProducts();
			break;
		
			case 6:
			break;
		
			default:
				printf("\n\n	Invalid option\n\n");
		
	}
	
	}while(option != 6);
	
	return 0;
}

