#include <stdio.h>
#include <string.h>

#define LIMIT 20

// Retorna o tamanho de uma string
int strlength(char* target) {
	int size = 0;
	while(target[size] != '\0'){
	size++;
	}
	
	return size;
}

// Verifica se um caractere existe numa string e retorna 1, caso verdadeiro
int contains(char *target, char letter){
	int contains = 0;

	for (int i = 0; i < strlen(target); i++){
		if(target[i] == letter)
			contains = 1;
	}
	return contains;
}

// recebe uma string e retorna uma nova versão dela sem caracteres repetidos
char* cleanString(char *target){
	char resumedArray[LIMIT] = "";
	char actualLetter[2];
	
	// Percorre *target adicionando cada novo caractere na na string resumida
	for (int i = 0; i < strlen(target); i++){
		actualLetter[0] = target[i];
		actualLetter[1] = '\0';
		
		// Verifica se *resumedArray já contém o caractere de *target
		if(contains(resumedArray, target[i]) == 1){
		
			//printf("já existe: %c\n", target[i]);
		} else {
			strcat(resumedArray, actualLetter);
			//printf("		Adicionando %c: %s\n", target[i], resumedArray);
		}
	}
	
	return strcat(resumedArray, "\0");
}

// Retorna o numero de vezes que um caractere searched aparece em uma string target
int characterRecurrences(char* target, char searched){
	int recurrences = 0;
	for(int i = 0; i < strlength(target); i++) {
		if(target[i] == searched)
			recurrences++;
	}
	return recurrences;
}

void getMostRecurrentCharacter(char entry[LIMIT]) {
    
    // Versão de entry sem caracteres repetidos para auxílio
    char *resumed = cleanString(entry);
    // Armazena a quantidade respectiva de vezes que cada letra de resumed aparece em entry
    int recurrences[strlength(resumed)];
    
    //printf("Array resumido para %s => %s\n", entry, resumed);
    //printf("tamanho de %s => %d\n\n", resumed, strlength(resumed));
    
    // Preenchendo a lista de recorrencias (recurrences)
    for(int i = 0; i < strlength(resumed); i++){
    	for(int j = 0; j < strlength(entry); j++) {
    		recurrences[i] = characterRecurrences(entry, resumed[i]);
    	}	 
    }
    
    // imprimindo a lista de recorrencias
    for(int i = 0; i < strlength(resumed); i++){
    	//printf("%c %dx\n", resumed[i], recurrences[i]);
    }
    
    // descobrindo quem aparece mais
    int recurrencePos = 0;
    for(int i = 0; i < strlength(resumed); i++){
    	for (int j = 0; j < strlength(resumed); j++){
    		if(recurrences[i] > recurrences[j]) {
    			recurrences[j] = recurrences[i];
    			recurrencePos = i;
    		}
    					
    	}
    }
    
    printf("\n\n%c aparece %d vezes\n", resumed[recurrencePos], recurrences[recurrencePos]);
}


int main(){

    char input[] = "abcabcaaaaaaabzzabvr";
    

    // printf("Digite algo > ");
    // scanf("%[^\n]s", input);

    getMostRecurrentCharacter(input);
    

    return 0;
}








































