#include <stdio.h>

char hundred[][13] = {
	"hundred1",
	"Cento",
	"Cem",
	"Duzentos",
	"Trezentos",
	"Quatrocentos",
	"Quinhentos",
	"Seiscentos",
	"Setecentos",
	"Oitocentos",
	"Novecentos",
	};
	
	char ten[][10] = {
	"ten1",
	"onze",
	"doze",
	"treze",
	"quatorze",
	"quinze",
	"dezesseis",
	"dezessete",
	"dezoito",
	"dezenove",
	};
	
	char ten2[][10] = {
	"ten1.1",
	"ten1.2",
	"vinte",
	"trinta",
	"quarenta",
	"cinquenta",
	"sessenta",
	"setenta",
	"oitenta",
	"noventa",
	};
	
	char unity[][7] = {
		"unity1",
		"um",
		"dois",
		"três",
		"quatro",
		"cinco",
		"seis",
		"sete",
		"oito",
		"nove",
		"dez",	
	};
	
void printItens(char list [3][20], int tam) {
	for (int i = 0; i < tam; i++) {
		printf(" - %s", list[i]);
	}
}

// The received value is just an unity
void printUnity(int target) {
	if(target >0 && target <= 10) {
		printf("\n%s\n\n", unity[target]);
	}
}

// The received value is an ten
void printTens(int target) {
	if(target / 10 > 1){
			
		if(target % 10 != 0)
			printf("\n%s e %s\n\n", ten2[target / 10], unity[target % 10]);
		else
			printf("\n%s\n\n", ten2[target / 10]);
	}
}

void printHundreds(int target) {
	if(target / 100 >= 1) {
	
		// First hundreds 1: "Cento e um" or "Cento e dois" etc
		if(target / 100 == 1 && (target / 10) % 10 == 0 && ((target % 100) % 10) != 0) {
			printf("\n%s e %s\n\n", hundred[1], unity[(target % 100) % 10]);
		}
		
		// First hundreds 2: "Cento e onze" or "Cento e doze" etc
		if(target / 100 == 1 && (target / 10) % 10 == 1 && (target % 100) % 10 != 0) {
		
			if((target % 100) % 10 > 0)
				printf("\n%s e %s \n\n", hundred[1], ten[(target % 100) % 10]);
		}
		
		if(target == 110)
			printf("\n%s e %s \n\n", hundred[1], unity[10]);
		
		// First hundreds 3: "Cento e vinte" or "Cento e trinta" etc
		if(target / 100 == 1 && (target % 100) % 10 == 0) {
		
			if((target / 10) % 10 != 1)
			
				if((target % 100) % 10 != 0)
					printf("\n%s e %s\n\n", hundred[1], ten2[(target / 10) % 10]);
					else if(target == 100)
					printf("\n%s\n\n", hundred[2]);
		}
		
		if(target / 100 == 1 // Centenas
		&& (target / 10) % 10 > 1 // Dezenas
		&& (target % 100) % 10 > 0 // Unidades
		)
			printf(
			"\n%s e %s e %s\n\n",
			hundred[1], //Centena
			ten2[(target / 10) % 10], // Dezena
			unity[(target % 100) % 10] // Unidade
			);
		
		if(target / 100 > 1){
		
			// Prints "Cem" or "Duzentos" or "Trezentos" etc
			//if((target / 10) % 10 == 0 && (target % 100) % 10 == 0){
		//		printf("\n%s\n\n", hundred[target / 100 + 1]);
			//}
			
			if((target % 100) % 10 > 0){
				// Duzentos e um or Trezentos e cinco or quatrocentos e três etc
				if((target / 10) % 10 == 0)
					printf("\n%s e %s\n\n",
					hundred[target / 100 + 1], //Centena
					unity[(target % 100) % 10] // Unidade
				);
				
			// Prints "Cem" or "Duzentos" or "Trezentos" etc
			} else if ((target % 100) % 10 == 0 && (target / 10) % 10 == 0) {
				printf("\n%s\n\n", hundred[target / 100 + 1]);
			}
			
			//Duzentos e dez or Quatrocentos e dez ou Seiscentos e dez etc
			if((target / 10) % 10 == 1 && (target % 100) % 10 == 0)
				printf("\n%s e %s\n\n",
				hundred[target / 100 + 1], //Centena
				unity[10] // Dezena
				);
			
			// Duzentos e quinze, Trezentos e Desessete e Novecentos e doze etc
			if((target / 10) % 10 == 1 && (target % 100) % 10 > 1) 
				printf("\n%s e %s\n\n",
				hundred[target / 100 + 1], //Centena
				ten[(target % 100) % 10] // Dezena
				);
			
			// Duzentos e vinte or Trezentos e quarenta or Quatrocentos e trinta etc
			if((target % 100) % 10 == 0 && (target / 10) % 10 != 0)
				printf(
				"\n%s e %s\n\n",
				hundred[target / 100 + 1], //Centena
				ten2[(target / 10) % 10] // Dezena
				
				);
				
			// Duzentos e vinte e quatro or Trezentos e quarenta e dois etc
			if((target % 100) % 10 > 0 && (target / 10) % 10 > 1)
				printf(
				"\n%s e %s e %s\n\n",
				hundred[target / 100 + 1], //Centena
				ten2[(target / 10) % 10], // Dezena
				unity[(target % 100) % 10] // Unidade
				);
		}
	
	}
}

int main () {
	
	int value;
	char extensive[3][20];
	
	do {
	
	printf("Type a value (0 to 999) > ");
	scanf("%d", &value);
	
	if (value >= 0 && value <= 999) {
		
		// The received value is just an unity
		printUnity(value);
		
		// The received value is an ten
		if(value >10 && value <= 99) {
			if(value / 10 == 1) {
				printf("\n\%s\n", ten[value%10]);
			}
			
			// Printing tens in full
			printTens(value);
		
		// Hundreds
		} else if(value >99 && value <= 999) {
		
		// Printing hundreds in full
			printHundreds(value);
		}
	} else {
		printf("\n\n~~Type a value between 0 and 999~~\n\n");
	}
	
	} while (value != 0);
	
	return 0;
}

