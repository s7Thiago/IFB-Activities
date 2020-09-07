#include <stdio.h>
#include <string.h>

#define MAX 50

void removeVolgals(char *target) {
	for (int i = 0; i < strlen(target); i++) {
		if(target[i] == 'a' || target[i] == 'A' || target[i] == 'e' || target[i] == 'E' ||
		target[i] == 'i' || target[i] == 'I' || target[i] == 'o' || target[i] == 'O' ||
		target[i] == 'u' || target[i] == 'U'
		){
			target[i] = ' ';	
		}
	}
}

int main (void) {
	
	char target[MAX]; 
	
	printf("Digite > ");
	scanf("%[^\n]s", target);
	
	removeVolgals(target);
	
	printf("\n%s\n\n", target);
	
	return 0;
}

