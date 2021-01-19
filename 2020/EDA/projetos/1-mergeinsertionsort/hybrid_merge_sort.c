#include "hybrid_merge_sort.h"

void merge(int* v, int* v1, int* v2, size_t size){
	// i aponta para o vetor resultado v
	// j aponta para a primeira parte do vetor v (v1)
	// k aponta para a segunda parte do vetor v (v2)
	// Cada um aponta para o começo do seu respectivo vetor
	size_t i = 0, j = 0, k = 0;
	
	size_t size_v1 = size / 2;
	size_t size_v2 = size - size_v1;
	
	// Varre os dois subvetores
	for(i = 0; j < size_v1 && k < size_v2; i++){
	// Compara v1[j] com v2[j] para definir qual deles é o menor
	// Ou seja, compara os elementos de cada metade na mesma posição
	// para definir qual vai ser inserido no vetor resultado. Isso é
	// repetido até que um dos dois vetores que representam cada metede
	// do original ficar sem elementos (enquanto j for menor do que o 
	// tamanho da primeira metade e enquanto k for menor do que o tamanho
	// da segunda metade do vetor original), dessa forma, saímos desse laço
		if (v1[j] <= v2[k]) {
			// Se o elemento da primeira metade for menor que
			// o elemento da segunda metade que está na mesma
			// posição, passa v1[j] para o vetor resultado, e 
			// incrementa j
			v[i] = v1[j];
			j++;
		} else {
			// Se o elemento da segunda metade for menor que
			// o elemento da primeira metade que está na mesma
			// posição, passa v2[k] para o vetor resultado, e 
			// incrementa k
			v[i] = v2[k];
			k++;
		}
		// Independentemente de qual vetor receber o elemento, a variável
		// i continua sendo incrementada para que o vetor resultado possa
		// continuar sendo preenchido
	}
	
	// Quando o laço anteriror terminar, apenas um dos vetores (v1 ou v2)
	// ainda vai conter elementos, as próximas linhas tratam isso
	// Descobre em qual dos dois vetores ainda restaram elementos e 
	// transfere esses elementos restantes encontrados para o vetor 
	// resultado v;
	// se j é menor do que o tamanho do tamanho do vetor da primeira metade
	// significa que ainda existem elementos nele, a mesma coisa é feita com
	// a segunda metade, mas usamos k para decidir sobre o tamanho da mesma;
	// 	* Se um dos vetores referenciados abaixo não tiver elementos, o
	// 	simplesmente não é executado
	while(j < size_v1) v[i++] = v1[j++];
	while(k < size_v2) v[i++] = v2[k++];
}


void hybrid_sort(int* v, size_t size, size_t subproblems_target_size) {
	size_t metade;
	
	if(size > 1) {
		metade = size / 2;
		
		// Enquanto o tamanho do subvetor for menor do que o tamanho
		// determinado para ele, fazer o insertionsort
		if( metade <= subproblems_target_size) {
			subproblems_target_size--;
			insertionsort(v, size);
		} else {
		
		// Alocando espaço para os vetores que conterão cada metade da 
		// entrada
		int* v1 = mallocx(sizeof(int) * metade);
		int* v2 = mallocx(sizeof(int) * size - metade);
		
		// Copiando os elementos de v cada um para a sua respectiva 
		// metade
		int i;
		for(i = 0; i < metade; i++)
			v1[i] = v[i];
			
		for(i = metade; i < size; i++)
			v2[i - metade] = v[i];
		
		// Ordeando recursivamente a primeira metade
		hybrid_sort(v1, metade, subproblems_target_size);
		
		// Ordeando recursivamente a segunda metade
		hybrid_sort(v2, size - metade, subproblems_target_size);
		
		// Realizando a junção das metades
		merge(v, v1, v2, size);
		
		// Liberando o espaço que havia sido alocado para cada metade
		free(v1);
		free(v2);
		}
	}

}


void sort(char label, int* v, size_t size, size_t limit){
	printf("VETOR %c ANTES\n", label);
	printv(v, size);
	
	// Ordenando
	hybrid_sort(v, size, limit);
	
	printf("VETOR %c DEPOIS\n", label);
	printv(v, size);
	printf("***************************************\n\n");
}































































