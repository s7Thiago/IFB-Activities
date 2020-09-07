#include <stdio.h>
#include <string.h>

void sortValues(int a, int b, int c) {
	
	if (a > b && b > c) {
		
	} else if (a > b && c > b) {
		
	} else if (b > a && a > c) {
		
	} else if (b > a && c > a) {
		
	}
	
	printf("\n\na > %d\nb > %d\nc > %d\n", a, b, c);
	
}

int main (void) {

	int a, b, c;
	
	printf("Digite 3 números (Separados por espaço) > ");
	scanf("%d %d %d", &a, &b, &c);
	
	sortValues(a, b, c);
	
	return 0;
}
