#include "insertion_sort.h"

void insertionsort(int* v, size_t n){
	int i, j, chave;
	
	for(i = 1; i < n; i++){
		chave = v[i]; // Elementos que queremos inserir
		
		// Compara o elemento chave com todo mundo que está a esquerda dele
		// Enquanto o j>=0 e o j-ésimo elemento for maior do que a chave,
		// em outras palavras, enquanto esse laço estiver rodando, quer
		// dizer que estamos encontrando algum elemento maior do que aquele
		// que queremos inserir
		// Condição de saída:
		// 	* Quando j for -1
		// 	* Quando acharmos um elemento <= o que estamos inserindo
		for(j = i - 1; (j >= 0) && chave < v[j]; j--){
			
			// Para liberar espaço para o elemento que queremos inserir,
			// o elemento é movido para a direita do elemento com o qual
			// acabamos de compará-lo
			v[j+1] = v[j];
		}
		v[j+1] = chave; // Em ambos os casos a chave tem que ser inserida nessa posição
	}
}































