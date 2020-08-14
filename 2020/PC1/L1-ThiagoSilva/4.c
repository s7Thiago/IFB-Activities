#include <stdio.h>

int letterCase(int letter) {
  	if (letter >= 'A' && letter <= 'Z') {
      return 1;
    } else {
      return 0;
    }
}

void printSequence(int start, int end) {

	printf("\n");
	
	for (int i = 1; i <= end - start; i++) {
		printf(" %c", (start + i));
	}
}

int main () {
	
	char c;
	
	printf("Type a letter > ");
	scanf("%c", &c);
	
	if (letterCase(c) > 0) {
		printf("Letra Maiúscula");
		printSequence(c, 'Z');
	} else {
		printf("Letra Minúscula");
		printSequence(c, 'z');
	}
	
	printf("\n");
	
	return 0;
}


