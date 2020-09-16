#include <stdio.h>
#include <string.h>

#define TAM_NAME 25
#define MAX_SONGS 10

struct album target;

char menu[4][TAM_NAME * 2] = {
	"1 - Criar o álbum musical",
	"2 - Adicionar música ao álbum",
	"3 - Listar músicas do álbum",
	"4 - Sair"
};

//Imprime o menu de opções
void showMenu() {
	printf("\n");
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
	};
	
//Limpa uma string
void cleanString(char *target) {
	for (int i = 0; i < strlen(target); i++){
		target[i] = '\0';
	}
}	

// Reseta o album
void cleanAlbum(){
	//Atribuindo
	cleanString(target.nomeAlbum);
	cleanString(target.generoMusical);
	target.qtdeMusicas = 0;
}
	
// Cria o album
void novoAlbum(){
	//Album flow
	char nomeAlbum[TAM_NAME];
	char generoMusical[TAM_NAME];
	int qtdeMusicas;
	
	//Nome
	printf("Nome: ");
	scanf("%s", nomeAlbum);
	
	//genero
	printf("Gênero musical: ");
	scanf("%s", generoMusical);
	
	//qtde
	printf("Qtde de músicas: ");
	scanf("%d", &qtdeMusicas);
	
	//Atribuindo
	strcpy(target.nomeAlbum, nomeAlbum);
	strcpy(target.generoMusical, generoMusical);
	target.qtdeMusicas = qtdeMusicas;
	
	//
	printf("\nINFO:\nnome: %s\ngenero: %s\nfaixas: %d\n", 
	target.nomeAlbum, target.generoMusical, target.qtdeMusicas);
}

void adicionarMusica() {
	
}

int main (void) {

	int option;
	
	do{
		//
		showMenu();
	
		printf("Escolha > ");
		scanf("%d", &option);
	
	switch(option) {
	
		case 1:
			novoAlbum();
		break;
	
		case 2:
		break;
	
		case 3:
		break;
	
		case 4:
		break;
	
		case 5:
			printf("\nINFO:\nnome: %s\ngenero: %s\nfaixas: %d\n", 
			target.nomeAlbum, target.generoMusical, target.qtdeMusicas);
		break;
	
		default:
			printf("\n\nOpção Inválida!\n\n");
			cleanAlbum();
	}
	
	}while(option != 4);
	
	return 0;
}
