#include <stdio.h>
#include <string.h>

#define TAM_NAME 25
#define MAX_SONGS 10

char menu[4][TAM_NAME] = {
	"1 - Criar o álbum musical",
	"2 - Adicionar música ao álbum",
	"3 - Listar músicas do álbum",
	"4 - Sair"
};

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
		musica musicas[MAX_SONGS]
	}album;

int main (void) {
	
	
	
	return 0;
}
