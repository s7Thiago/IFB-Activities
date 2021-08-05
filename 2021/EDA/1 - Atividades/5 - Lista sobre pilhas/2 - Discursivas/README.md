# Questões discursivas

## 1. O que e e para que serve uma pilha?
## 2. 2. Em que situac¸oes uma pilha pode ser utilizada?
> É uma estrutura que serve literalmente para empilhar dados como uma pilha de pratos, seguindo o princípio de que somente o elemento do topo pode (o último a ser inserido) ser acessado diretamente, um elemento mais ao centro da pilha só pode ser acessado depois desempilhar os que estão mais acima, basicamente, retirando os elementos na ordem inversa em que foram inseridos. Alguns exemplos de situações onde o uso de pilhas pode favorecer a implementação:
>
> - [x] Calculadora pós-fixada
> - [x] Navegação entre páginas Web
> - [x] Mecanismos de desfazer/refazer em editores
> - [x] Inversão de listas

## 3. Suponha que uma pilha possua 4 valores na seguinte ordem: 1, 2, 3 e 4. Qual seria a sequencia correta de operações de inserção (I) eliminação (E) para se obter os registros na ordem 2 4 3 1?
>```c
> * push(1)
> * pop() // 2
> * push(3)
> * push(4)
> * push(2)
> ```



## 21. Dada as operac¸oes de pilha insere I e remove R, escreva a configuração final da pilha após as seguintes operações: I(10), I(20), R, I(30), I(45), I(21), R, R.
> * Solução ``30 -> 20``
>




















