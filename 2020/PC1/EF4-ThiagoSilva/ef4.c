#include <stdio.h>
#include <string.h>

#define TAM_NAME 25
#define MAX_SONGS 10

char menu[4][TAM_NAME * 2] = {
	"1 - Criar o álbum musical",
	"2 - Adicionar música ao álbum",
	"3 - Listar músicas do álbum",
	"4 - Sair"
};

//Imprime o menu de opções
void showMenu() {
	for (int i = 0; i < 4; i++){
		printf("%s\n", menu[i]);
	}
	
	printf("\n");
}

//struct musica
	struct musica{
		int id;
		char nomeMusica[TAM_NAME];
		char duracao[MAX_SONGS];
	
	}musica;

//struct album
	struct album{
		char nomeAlbum[TAM_NAME];
		char generoMusical[TAM_NAME];
		int qtdeMusicas;
		struct musica musicas[MAX_SONGS];
	}album;

int main (void) {

	int option;
	
	do{
	//
	showMenu();
	
	printf("Escolha > ");
	scanf("%d", &option);
	
	switch(option) {
	
	case 1:
	break;
	
	case 2:
	break;
	
	case 3:
	break;
	
	case 4:
	break;
	
	default:
		printf("Opção inválida");
	}
	
	}while(option != 4);
	
	return 0;
}
