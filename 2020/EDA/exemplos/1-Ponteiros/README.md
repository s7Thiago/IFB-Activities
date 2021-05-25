# definições comuns
size_t: Represeta números inteiros sem sinal. Pode ser usado para armazenar valores de endereços de memória, números de bytes etc;

## malloc
|assinatura| 
|--|
|```void* malloc(size_t size);```|


desc: Recebe um inteiro sem sinal do tipo size_t, que representa a quantidade de bytes que queremos alocar. Por exemplo, para alocar 20 bytes, chamamos ```malloc(20)```. O retorno dessa função é um ponteiro genérico(void*) que aponta para a região de memória onde estão os bytes alocados por ela, que por sua voz, por ser do tipo ```void*```, pode ter como valor armazenado qualquer outro tipo de dado (```int```, ```double```, ```char```, ```string```, ```etc```), pois o que é retornado é somente o endereço base, que posteriormente pode sofrer um cast para o valor que estiver sendo trabalhado pelo programador.

*obs:* Se por acaso, o programador solicitar ao malloc uma quantidade de memória em bytes maior do que a que realmente está a disposição, o que é retornado é uma referência para NULL, ou seja, um ponteiro para NULL.

## calloc 
|assinatura|
|--|
|```void* calloc(size_t num, size_t size);```|

desc: Basicamente faz a mesma coisa que malloc, a diferença é que ela recebe a quantidade de bytes através de 2 parâmetros:
**num**: Número de espaços de memória que queremos criar;
**size**: Tamanho em bytes de cada espaço de memória;

Ou seja, a quantidade total de memoria em bytes que será alocado pelo calloc será o equivalente a num * size.
Outra diferença do calloc para o malloc, é que além de alocar dessa forma, ele incializa toda a região alicada com zeros. No malloc, essa inicialização com zeros não é garantida, pois depende do compilador que está sendo utlizado, enquanto que no calloc, temos essa garantia, independente de qualquer coisa. ou seja, se queremos alocar bytes na memória, e ainda ter certeza de que a região de memória alvo será inicializada completamente com zeros, é uma boa ideia usar o calloc, até porque o seu retorno é o mesmo do malloc.

## realloc 
|assinatura| 
|--|
|```void* realloc(void* ptr, size_t size);```|


**desc**: Redimensiona a área de memória apontada por ptr. Em outras palavras, ele recebe uma área de memória que já está alocada dinamicamente (ptr), e o novo tamanho dessa área (size). O seu retorno consiste em um ponteiro para uma área de memória com o novo tamanho. Essa função pode ser usada para aumentar, ou diminuir a área de memória alocada dinamicamente. É importante destacar que pode ser que o resultado do retorno dessa função seja uma área de alocada em outra região da memória, dependendo do espaço disponível na mesma região onde ptr se encontrar. Ou seja, a nova região retornada pode ser diferente da original, se necessário. Por fim, ele realloc retorna NULL em caso de falha (a região antiga ainda pode ser acessada, em caso de falha).
OBS:
* Se size for menor que a area antiga, o retorno será uma área encolhida;
* Se size for maior que a area antiga, o retorno será uma área aumentada o número de bytes necessários;
* Se ptr==NULL, realloc terá o mesmo comportamente de malloc.
* Se size==0, isso é o equivalente a solicitar que a região ptr seja liberada;
* Se Se a região antiga não poder ser expandida, realloc aloca uma nova região, copiando o conteúdo antigo para essa nova área;


[x] Em C, tudo que é alocado precisa ser desalocado para evitar o consumo desnecessário de memória, alé de isso ser uma boa prática de programação. Alguns recursos que auxiliam nesse processo são:

## free 
|assinatura|
|--|
|```void free(void* ptr);```|


**desc**: Desaloca uma região de memória ptr alocada dinamicamente. Quando free é usada, basicamente, ptr deixa de apontar para uma região, ou seja, a região apontada é totalmente liberada, e ptr fica livre;



























