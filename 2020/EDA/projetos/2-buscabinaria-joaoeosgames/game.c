#include "game.h"

void fillList(size_t qtde){

	game_list = callocx(qtde, sizeof(game));
	game target;
	
	for(int i = 0; i < qtde; i++){
		
		//printf("\n%d) ", i+1);
		scanf("%s %lf", target.name, &target.price);
		
		game_list[i] = target;
		
		//printf("OK (%s, %.2lf)\n", target.name, target.price);	
	}	
}

void showAllMatchedPairs(size_t qtde){

	printf("\n\nSELECIONADOS");

	for(int i = 0; i  < qtde; i++){
		game target = match_pair_list[i].pair[0];
		game target2 = match_pair_list[i].pair[1];
		
		printf("\n[%s] [%s] %.2lf", target.name, target2.name, match_pair_list[i].value);
	}
}

void showAllGames(size_t qtde){
	for(int i = 0; i  < qtde; i++){
		game target = game_list[i];
		printf("\n%s %.2lf", target.name, target.price);
	}
}

void selectMostConvenientGame(size_t qtde)  {
	int i, location = 0, diff;
	
	for(i = 0; i < qtde; i++){
		game a = match_pair_list[i].pair[0];
		game b = match_pair_list[i].pair[1];
		
		if(strcmp(a.name, "") != 0){
		printf("\na.price: %.2f", b.price);
		
			if(abs(a.price - b.price) < abs(match_pair_list[location].pair[0].price - match_pair_list[location].pair[1].price)){
				location = i;
			}
		}
	}
}


