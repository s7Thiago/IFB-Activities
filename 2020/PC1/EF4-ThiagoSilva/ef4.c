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
	
	};

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

// Cria uma nova musica
void novaMusica(int index){
	// nomeMusica, duracao
	struct musica faixa;
	
	char nome[TAM_NAME];
	char duracao[MAX_SONGS];
	
	faixa.id = index + 1;
	
	printf("Nome > ");
	scanf("%s", faixa.nomeMusica);
	
	printf("Duração (MM:SS) > ");
	scanf("%s", faixa.duracao);
	
	//Associando
	target.musicas[index] = faixa;
}

int indexMusica(){
	int indexValue = 0;
	for (int i = 0; i < MAX_SONGS; i++){
		if(target.musicas[i].nomeMusica[0] != '\0') {
			indexValue++;
		}
	}
	
	return indexValue;
}

// Adiciona uma nova musica ao album
void adicionarMusica() {
	
	if(target.qtdeMusicas < MAX_SONGS) {
		int id = indexMusica();
		
		printf("\n\nmusicas: %d\n\n", id);
		novaMusica(id);
		
	} else {
		printf("\n\nERRO: Número máximo de músicas atingido\n\n");
	}
}

void listarMusicas(){

	for (int i = 0; i < indexMusica(); i++){
		printf("%d - %s\n", target.musicas[i].id, target.musicas[i].nomeMusica);
	}

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
		adicionarMusica();
		break;
	
		case 3:
			listarMusicas();
		break;
	
		case 4:
		break;
	
		default:
			printf("\n\nOpção Inválida!\n\n");
			cleanAlbum();
	}
	
	}while(option != 4);
	
	return 0;
}
