#include<stdio.h>
#include<string.h>

  typedef struct pessoa
    {
        char nome [30];
        int idade;
        char cpf [15];
    }Pessoa;

int main(){

    FILE *fp;
    Pessoa pessoa;

    fp = fopen("log.bin","a+b");

    if(fp ==NULL){
        printf("erro no arquivo\n");
        return 1;
    }

         printf("\nDigite o nome da pessoa: ");
        scanf("%[^\n]", pessoa.nome);
        

        printf("Digite o cpf: ");
        scanf("%s", pessoa.cpf);
   

        printf("Digite a idade: ");
        scanf("%d", &pessoa.idade);
        getchar();

        fwrite(&pessoa,sizeof(Pessoa),1,fp);    

 
    fclose(fp);

}
