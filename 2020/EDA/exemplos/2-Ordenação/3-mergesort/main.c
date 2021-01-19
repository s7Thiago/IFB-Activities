#include "mergesort.h"


/**
Autor: Thiago Silva

Desc: O mergesort é um algoritmo n log(n), e isso sem dúvida o torna melhor
do que um algoritmo quadrático, o tornando adequado para entradas grandes,
funcionando, nesse caso, de maneira muito mais eficiente do que um bublesort
ou um insertionsort

Observações para o método:
	* Requer uma quantidade maior de memória (devido aos vetores
	auxiliares);
	* É um método que trabalha recursivamente;

Além disso, o método é: 

	* Não In-place: Para funcionar, precisa de mais memória extra, que vai
	 desde simples variáveis auxiliares até vetores auxiliares (além do 
	 vetor de entrada), o fazendo consumir pelo menos o dobro de memória;
	 
	* Estável: Elementos iguais conservam suas posições 
	relativas;
	
Considerações finais
**/

int main (void) {

	// vetor que vamos ordenar
	int v[TAM + 5] = {11, 29, 7, 17, 3, 13, 5, 19, 23, 2 /***/, 65, 1, 22, 14, 18};
	
	printf("ANTES\n");
	printv(v, TAM + 5);
	
	// Ordenando (usar insertionsortl() para ver a saída com logs)
	mergesort(v, TAM + 5);
	
	printf("DEPOIS\n");
	printv(v, TAM + 5);
	
	
	return 0;
}

