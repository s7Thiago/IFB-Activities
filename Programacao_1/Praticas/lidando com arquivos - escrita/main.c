#include <stdio.h>
#include <stdlib.h>

int main() {

    //Poneiro para o registro
    FILE *arquivo;

    //Abrindo o arquivo para escrita (caso o mesmo ja exista, as informacoes serao sobrescritas):
    arquivo = fopen("meu_arquivo.txt", "w");

    //String que contem o condeudo que ira compor o arquivo
    char content[] = "Estamos escrevendo no nosso arquivo!";

    //Verificando se esta tudo certo com o arquivo:
    if(arquivo == NULL){
        printf("\n\nOcorreu um erro ao abrir o arquivo!\n\n");
        return 1;
    } else {
    printf("\n\nArquivo aberto com sucesso!\n\n");
    }

    //Pedindo para o usuario digitar o que teremos no arquivo.
    printf("Digite alguma palavra para o arquivo: ");
    scanf("%s", &content);

    //Este comando armazena os uma palavra no arquivo. Seu funcionamento eh muito semelhante
    //ao printf, a diferença principal eh a existencia de um parâmetro para informar o arquivo onde os
    //dados serão armazenados, no caso, o primeiro parametro.
    fprintf(arquivo, "%s", content);

    //Fechando o arquivo depois de ter concluido as operacoes anteriores
    fclose(arquivo);

    printf("\n\n\nGravacao dos dados no arquivo concludida!!!              \n\n:-D\n\n");

    return 0;
}
