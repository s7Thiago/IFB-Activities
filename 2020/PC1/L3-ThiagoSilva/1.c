#include <stdio.h>
#include <string.h>

void sortValues(int a, int b, int c) {

	int auxA = a, auxB = b, auxC = c;
	
	if (a < b && b < c) {
		printf("a b c");
	} else if (a < c && c < b) {
		printf("a c b");
		b = auxC;
		c = auxB;
	} else if (b < a && a < c) {
		printf("b a c");
		a = auxB;
		b = auxA;
	} else if (b < c && c < a) {
		printf("b c a");
		a = auxB;
		b = auxC;
		c = auxA;
	} else if (c < a && a < b) {
		printf("c a b");
		a = auxC;
		b = auxA;
		c = auxB;
	} else if (c < b && b < a) {
		printf("c b a");
		a = auxC;
		c = auxA;
	}
	
	printf("\n\na > %d\nb > %d\nc > %d\n\n", a, b, c);
}

int main (void) {

	int a, b, c;
	
	printf("Digite 3 números (Separados por espaço) > ");
	scanf("%d %d %d", &a, &b, &c);
	
	sortValues(a, b, c);
	
	return 0;
}
