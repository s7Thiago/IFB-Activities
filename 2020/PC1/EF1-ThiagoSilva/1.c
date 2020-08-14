#include <stdio.h>

//Return 0 for pair or 1 for odd
int isOdd(int value) { 
	if (value % 2 == 0) {
		return 0;
	}
	
	return 1;
}

//Print the values between a and b
void printValuesBetween(int a, int b) {

	if(isOdd(a) == 1){
	printf("%d", a);
	}
	
	//Print the values between a and b
	for (int i = a + 1; i < b; i++) {
		if(isOdd(i) == 1){
		printf(" - %d ", i);
		}
	}
	
	if(isOdd(b) == 1){
	printf("- %d", b);
	}

	
}

//
int main () {
	
	int x, y;
	
	printf("=== Type values bellow ===\n\n");
	
	//Capturing values keyboard entry
	printf("X > ");
	scanf("%d", &x);
	
	printf("Y > ");
	scanf("%d", &y);
	
	//Sorting values and printing values between entries
	if (x < y) {
		printValuesBetween(x, y);
		
	} else {
		printValuesBetween(y, x);
		
	}
	printf("\n\n");
	return 0;
}





































































