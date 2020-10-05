#include <stdio.h>

#define OUTPUT "aprovados.txt"
#define INPUT "data.txt"


int main (void) {
	char name[20];
	int age;
	double result;
	FILE* in;
	FILE* out;
	in = fopen(INPUT, "r");
	out = fopen(OUTPUT, "w");
	
	// Vericicando se está tudo certo com os arquivos
	if (in == NULL) {
		printf("\n\nErro ao abrir o arquivo de entrada!\n\n");
		return 1;
	}
	
	// Fazendo a leitura do arquivo de entrada e armazenando num vetor de caracteres
	while((fscanf(in, "%s %d %lf", name, &age, &result))){
		if (fgetc(in) == EOF) {
			break;
		}
		
		if (age >= 18 && result > 6.0) {
			fprintf(out, "%s %d %.2lf\n", name, age, result);
		}
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
