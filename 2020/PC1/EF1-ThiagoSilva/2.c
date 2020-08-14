#include <stdio.h>

double result = 0;
int activateLogs = 0;

int calc(char operator, double a, double b) {
	switch(operator) {
		case '+':
			if(activateLogs == 1)
				printf("\n(%.2lf ➕️ %.2lf = (%.2lf))\n", a, b, (a + b));
			return a + b;
		break;
		
		case '-':
			if(activateLogs == 1)
				printf("\n(%.2lf ➖️ %.2lf = (%.2lf))\n", a, b, (a - b));
			return a - b;
		break;
		
		case '*':
			if(activateLogs == 1)
				printf("\n(%.2lf ✖️  %.2lf = (%.2lf))\n", a, b, (a * b));
			return a * b;
		break;
		
		case '/':
			if(activateLogs == 1)
				printf("\n(%.2lf ➗️ %.2lf = (%.2lf))\n", a, b, (a / b));
			return a / b;
		break;
		
		default:
			if(operator != '=')
				printf("\n⚠️  Invalid Operator (%c) ⚠️\n\n", operator);
			else
				printf("\n✅️  %.2lf\n\n", result);
		break;
	}
	
};

int main() {

	double a, b;
	int loop = 0;
	char operator;

	printf("\nActivate Logs? \n[1=yes, 0=no]> ");
	scanf("%d", &activateLogs);


do {

	//
	if(loop == 0){
		printf("\nType a value > ");
		scanf("%lf", &a);
	}
	
	//
	printf("Operation > ");
	scanf(" %c", &operator);
	// getchar();
	
	//
	if(loop == 0){
		printf("Type value b > ");
		scanf("%lf", &b);
	}
	
	// *************************
	if(loop == 1 && operator != '='){
		printf("Type a value > ");
		scanf("%lf", &a);
	}
	
	// Calculating
	if(loop == 0)
		result = calc(operator, a, b);
	else
		result = calc(operator, result, a);
	
	if(loop == 0)
	loop++; //

} while(operator != '=');

return 0;
}


































