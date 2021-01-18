#include "bublesort.h"


/**
Autor: Thiago Silva

Desc: O  bublesort  é  um algoritmo  cujo custo  no  pior  caso é 
quadrático, ou  seja, o  número  de passos/iterações  necessárias 
para se ordenar uma entrada cresce de forma quadrática dependendo 
do tamanho  da entrada, e  de o quanto ela está desordenada, isso
por um lado é ruim, pois o torna lento, mas em contrapartida, ele
é um algoritmo fácil de implementar.

Alé disso é um método:

	* In-place: Não precisa de muita memória extra para
	operar;
	 
	* Estável: Elementos iguais conservam suas posições 
	relativas;

**/

int main (void) {

	// vetor que vamos ordenar
	int v[TAM] = {11, 29, 7, 17, 3, 13, 5, 19, 23, 2};
	
	printf("ANTES\n");
	printv(v, TAM);
	
	// Ordenando (usar bublesortl para ver a saída com logs)
	bublesort(v, TAM);
	
	printf("DEPOIS\n");
	printv(v, TAM);
	
	
	return 0;
}

