#include "search.h"


int main (void) {

	// Entrada inicial
	size_t game_qtde;
	double money;
		
	scanf("%ld %lf", &game_qtde, &money);
	
	// Preenchendo a lista de games de acordo com o tamanho especificado
	fillList(game_qtde);
	
	printf("\nINSERIDOS (%ld -- %.2lf)", game_qtde, money);
	showAllGames(game_qtde);
	
	// Encontra os pares de jogos cuja soma dos preços
	// seja equivalente a mesada
	 searchMatch(game_qtde, money);
	
	//
	showAllMatchedPairs(game_qtde);
	
	//
	
	free(game_list);
	free(match_pair_list);
	
	return 0;
}
