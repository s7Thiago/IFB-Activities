#ifndef GAME_H
#define GAME_H

#include "util.h"

#define GAME_NAME_MAX 30
#define GAME_MAX_VALUE 1000000000
#define GAME_MAX_QTDE 100000
#define GAME_MIN_QTDE 2
#define MONEY_MAX 2 * 10000000000
#define MONEY_MIN 1

typedef struct game{
	char name[GAME_NAME_MAX];
	double price;

} game;

typedef struct game_pair {
	game pair[GAME_MIN_QTDE];
	double value;
} game_pair;

game* game_list; //  Armazena todos os games
game_pair* match_pair_list; // Coleção dos pares de games que atendem o critério


// Preenche a lista de gales game_list
void fillList(size_t qtde);

// Mostra todos os games armazenados em memória
void showAllGames(size_t qtde);

// 
void showAllMatchedPairs(size_t qtde);

//
void selectMostConvenientGame(size_t qtde);

#endif
