#include <stdio.h>

int main () {
	
	int qt;
	double avg, current;
	
	
	printf("Quantity of values > ");
	scanf("%d", &qt);
	
	for (int i = 0; i < qt; i++) {
		printf("%d > ", i + 1);
		scanf("%lf", &current);
		
		// Media
		avg += current / qt;
	}
	
	printf("AVG = %.2f\n", avg);
	
	
	return 0;
}

