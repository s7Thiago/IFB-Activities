#include <stdio.h>
#include <stdlib.h>

int main() {

    //Primeiramente eh necessario criar um ponteiro para o arquivo Ele vai apontar para a localizacao do registro
    FILE *arquivo;

    //Abtes de abrir o arquivo, eh importante entender os parametros exigidos. O primeiro parametro eh o nome
    //do arquivo. Eh aqui que colocamos o caminho onde desejamos criar o arquivo, caso apenas o nome seja passado,
    //o compilador cria o arquivo na mesma pasta do programa e o segundo, eh referente ao tipo de abertura que
    //desejamos, que pode ser:

    //r: Abre o arquivo com permissao de somente leitura. Eh necessario que ele ja exista no disco

    //w: Abre o arquivo com permissao para escrita. caso o arquivo nao exista, ele cria. Eh necessario tomar cuidado
    //com o uso desta permissao, pois caso o arquivo ja exista, ele o recria o arquivo, apagando os dados anteriores
    //ou seja, certamente voce vai perder informacoes, se nao forem feitas as verificacoes tratamentos adequados.

    //a: Permite abrir um arquivo para escrita, acrescentando novos dados ao final do mesmo. Caso o arquivo referido
    //nao exista, ele eh criado.

    //Como dito, com apenas o nome do arquivo passado no primeiro parametro, ele sera criado na mesma pasta do programa
    arquivo = fopen("meu_arquivo.txt", "a");

    //Depois que as operacoes sao feitas, eh importante fechar o fluxo para liberar o arquivo. O comando eh este:
    fclose(arquivo);

    printf("O arquivo foi criado com sucesso");

    system("pause");
    return 0;
}
