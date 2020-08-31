#include <stdio.h>
#include <string.h>

#define LIMIT 200

// Retorna o tamanho de uma string
int strlength(char* target) {
	int size = 0;
	while(target[size] != '\0'){
	size++;
	}
	
	return size;
}

void removeSequence(char* target, char sequence[LIMIT]){
	int targetSize = strlength(target);
	int sequenceSize = strlength(sequence);
	int countRecurrences = 0;
	char result[targetSize - sequenceSize];
	
	printf("===== Input: %s =====\n\n", target);

	// percorre toda a sequencia alvo
	for(int i = 0; i < targetSize; i++){
		char deletionSearch[sequenceSize];
		deletionSearch[sequenceSize] = '\0';
		int resemblance;
		
		// Percorre intervalos do tamanho do termo procurado em busca de correspondencias
		for (int j = 0;j < sequenceSize;j++){
			deletionSearch[j] = target[j + i];
		}
		
		resemblance = strcmp(deletionSearch, sequence); // Calculating resemblance
		//printf("current: %s (%s resesemblance: %d)", deletionSearch, sequence, resemblance);
		
		
		if(resemblance == 0){
			//printf(" => MATCH!!! (%d)\n", i);
			// Removendo partes
			for (int j = 0;j < sequenceSize;j++)
				target[j + i] = '\0';
		}
		else {
			char currentCharacter[2];
			currentCharacter[0] = target[i];
			currentCharacter[1] = '\0';
		
		strcat(result, currentCharacter);
		
		//printf("\ncurrentCharacter: %s\n", currentCharacter);
		}
	}
	
	printf("===== result: %s =====\n\n", result);
}

int main(void){

	char target[LIMIT] = "Arara azul bem rara";
	//char term[LIMIT];
	
	//puts("Digite uma frase > ");
	//scanf("%[^\n]s", target);
	
	//puts("\nTermo > ");
	//scanf("%[^\n]s", term);
	
	
	removeSequence(target, "ra");

	return 0;
}
















