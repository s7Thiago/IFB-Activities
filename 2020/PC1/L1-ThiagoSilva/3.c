#include <stdio.h>

//Prints the options list
void printOptions(char s[][15], int tam) {

	printf("\n");
	
	for (int i = 0; i < tam; i++) {
		printf("(%d) %s\n", (i),s[i]);
	}
}

//Ensolarado flow
void ensolaradoFlow() {
	char options[][15] = {"Alta", "Normal", "Baixa"};
	int target;
	
	//Printing options
	printOptions(options, 3);
	
	//Initializing flow
	printf("=== Ensolarado Flow ===\n");
	
	printf("\nWhat is the umity situation? > (Number): ");
	scanf("%d", &target);
	
	switch(target) {
		case 0:
			printf("%s selected", options[target]);
			printf("\nNão");
		break;
		
		case 1:
			printf("%s selected", options[target]);
			printf("\nSim");
		break;
		
		case 2:
			printf("%s selected", options[target]);
			printf("\nNão");
		break;
		
		default:
		printf("Invalid option");
		break;
	}
}

//Chuvoso flow
void chuvosoFlow() {
	char options[][15] = {"Forte", "Fraco"};
	int target;
	
	//Printing options
	printOptions(options, 2);
	
	//Initializing flow
	printf("=== Chuvoso Flow ===\n");
	
	printf("\nWhat is the umity situation? > (Number): ");
	scanf("%d", &target);
	
	switch(target) {
		case 0:
			printf("%s selected", options[target]);
			printf("\nSim");
		break;
		
		case 1:
			printf("%s selected", options[target]);
			printf("\nNão");
		break;
		
		
		default:
		printf("Invalid option");
		break;
	}
}

int main () {
	
	char options[][15] = {"Ensolarado", "Nublado", "Chuvoso"};
	int target;
	
	//Printing options
	printOptions(options, 3);
	
	printf("Type bellow based on the data above\n\n");
	
	printf("What is the climatic perspective? > (Number): ");
	scanf("%d", &target);
	
	//Choices flow:
	printf("\noption received from keyboard entry: %s\n\n", options[target]);
	switch(target) {
	
		case 0:
		printf("%s selected", options[target]);
		ensolaradoFlow();
		break;
		
		case 1:
		printf("%s selected", options[target]);
		printf("\nSim");
		break;
		
		case 2:
		printf("%s selected", options[target]);
		chuvosoFlow();
		break;
		
		default:
		printf("Invalid option");
		break;
	
	}
	
	printf("\n");
	
	return 0;
}


