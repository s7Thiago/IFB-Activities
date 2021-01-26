#include "search.h"


// match_pair_list
// game_list

void searchMatch(size_t size, double money_target){
	int i, j;
	size_t prev_tam;
	game targetA, targetB;
	
	printf("\n\n");
	// Prevendo o espaço que deve ser alocado
	for(i = 0; i < size; i++) {
		targetA = game_list[i];	
		
		for(int j = size; j > i; j--) {
			targetB = game_list[j];
			
			if((targetA.price + targetB.price) == money_target){
				prev_tam++;
			}
			
		}
	}
	
	i = 0;
	j = 0;
	match_pair_list = callocx(prev_tam, sizeof(game) * 2);
	
	//
	for(i = 0; i < size; i++) {
		targetA = game_list[i];	
		
		for(int j = 0; j < size; j++) {
			targetB = game_list[j];
			
			if(strcmp(targetA.name, targetB.name) != 0) {
				if((targetA.price + targetB.price) == money_target){
					strcpy(match_pair_list[i].pair[0].name, targetA.name);
					strcpy(match_pair_list[i].pair[1].name, targetB.name);
					match_pair_list[i].value = targetA.price + targetB.price;
				
					printf("\nPar aceito: [%s] [%s] = %.2lf", targetB.name, targetA.name, match_pair_list[i].value);
				}
			}
		}
	}
	
	selectMostConvenientGame(prev_tam);
}
















