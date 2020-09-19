#include "produto.h"
#include "crud.h"


int main (void) {
	
	extern int option;
	printf("\nResult: %s\n\n", generateProductCode("brasil", 12));
	
	do{
		showMainMenu();
	
		printf("\nEscolha > ");
		scanf("%d", &option);
	
		switch(option){
			case 1:
			break;
		
			case 2:
			break;
			
			case 3:
			break;
		
			case 4:
			break;
		
			case 5:
			break;
		
			case 6:
			break;
		
			default:
				printf("\n\n	Invalid option\n\n");
		
	}
	
	}while(option != 6);
	
	return 0;
}

