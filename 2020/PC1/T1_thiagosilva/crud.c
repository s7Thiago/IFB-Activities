#include "crud.h"
#include "produto.h"


int option = 0;
char mainMenu[][MAIN_MENU_CHARACTERS_LIMIT] = {
	"1 - Cadastrar novo produto",
	"2 - Atualizar informações de um produto",
	"3 - Vender produto",
	"4 - Consultar informações de um produto",
	"5 - Consultar quantidade de todos os produtos",
	"6 - Finalizar programa",
};

void showMainMenu(){
	for (int i = 0; i < MAIN_MENU_OPTIONS_LIMIT; i++){
		printf("%s\n", mainMenu[i]);
	}

}

