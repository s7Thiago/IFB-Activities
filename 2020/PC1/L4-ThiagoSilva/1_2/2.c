#include<stdio.h>

 typedef struct pessoa
    {
        char nome [30];
        int idade;
        char cpf [15];
    }Pessoa;

int main(){

    FILE *arq;
    Pessoa pessoa;
    arq = fopen("log.bin","rb");
    if (arq ==NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    
    fread(&pessoa,sizeof(Pessoa),1,arq);
    
 
 while (!feof(arq)){
  
        printf("\nNOME: %s\nCPF: %s\nIDADE: %d\n", pessoa.nome, pessoa.cpf, pessoa.idade);
        fread(&pessoa, sizeof(Pessoa), 1, arq);
 };

    fclose(arq);

}
