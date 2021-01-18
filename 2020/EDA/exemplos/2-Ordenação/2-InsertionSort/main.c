#include "insertionsort.h"


/**
Autor: Thiago Silva

Desc: O número que comparações do insertion sort é uma progressão aritmética
de razão 1, isso significa que ele nos dá um tempo quadrático assim como o
bublesort, ou seja, não é o ideal par entradas grandes, pois pode cair em um
comportamento onde levaria um tempo incrementado quadraticamente.

Observações para o método:
	* Eficiente para entradas pequenas, por fazer poucas comparações;
	* Mais rápido que o bublesort, porém, devido ao seu comportamento
	quadrático, não é recomendado o uso para entradas grandes;

Além disso, o método é: 

	* In-place: Não precisa de muita memória extra, precisando de poucas
	 variáveis auxiliares (além do vetor de entrada) para funcionar;
	 
	* Estável: Elementos iguais conservam suas posições 
	relativas;
	
As classificações acima o tornam um bom método, porém, para entradas
mouto grandes, o seu uso é desencorajado.

**/

int main (void) {

	// vetor que vamos ordenar
	int v[TAM] = {11, 29, 7, 17, 3, 13, 5, 19, 23, 2};
	
	printf("ANTES\n");
	printv(v, TAM);
	
	// Ordenando (usar insertionsortl() para ver a saída com logs)
	insertionsort(v, TAM);
	
	printf("DEPOIS\n");
	printv(v, TAM);
	
	
	return 0;
}

