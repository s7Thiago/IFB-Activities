/**
Autor: Thiago Silva

Desc: 

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
#include "hybrid_merge_sort.h"

int main (void) {

	// Tamanhos das entradas
	int t1 = pow(10, 4), t2 = pow(10, 5), t3 = pow(10, 6);
	
	// vetores entradas
	int* v1 = generateEntry(10);    // Substituir 10 por t1
	int* v2 = generateEntry(20);    // Substituir 20 por t2
	int* v3 = generateEntry(30);    // Substituir 30 por t3
	
	/**
	Ordena um vetor vi, passando um tamanho ti e uma variável que especifica
	o tamanho limite dos subvetores do merge (ti * n), este último é um
	número decimal, minha intenção foi diversificar os tamanhos predefinidos
	**/
	sort('A', v1, 10, 10 * 0.5);    // Substituir 10 por t1
	sort('B', v2, 20, 20 * 0.2);    // Substituir 20 por t2
	sort('C', v3, 30, 30 * 0.23);   // Substituir 30 por t3
	
	
	// Liberando memória alocada
	free(v1);
	free(v2);
	free(v3);
	
	
	return 0;
}

