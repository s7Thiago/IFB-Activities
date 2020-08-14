#include <stdio.h>


int main () {

	// variables
	double w, f, d, m, a, pStart, pEnd;
	
	//Storing values for m, a and f
	printf("\n\n=== Calculating force (F = M x A) ===\n");
	printf("Type values bellow:\n");
	
	printf("M (Massiness) > ");
	scanf("%lf", &m);
	
	printf("A (Aceleration) > ");
	scanf("%lf", &a);
	
	//Calculating force f
	f = m * a;
	printf("\nForce = %.2f\n", f);
	
	//Storing values for pSart, pEnd and d
	printf("\n=== Calculating displacement (D = pEnd - pStart) ===\n");
	printf("Type values bellow:\n");
	
	printf("pEnd (Final position) > ");
	scanf("%lf", &pEnd);
	
	printf("pStart (Initial position) > ");
	scanf("%lf", &pStart);
	
	//Calculating displacement
	d = pEnd - pStart;
	printf("\nDisplacement: %.2f\n", d);
	
	//Calculating work W
	w = f * d;
	printf("\n\nWork w = %.2f\n\nEnd", w);
	
	
	return 0;
}

