# Questões discursivas

## 1. O que e e para que serve uma fila?

## 2. 2. Em que situações uma fila pode ser utilizada?

> É uma TAD onde os elementos são mantidos em uma ordem específica. Essa ordem é a FIFO (First-In-First-Out), que basicamente se caracteriza pelo fato de os primeiros elementos a entrarem na estrutura também serem os primeiros a deixarem a mesma. Abaixo segue algumas aplicações onde o pode ser aplicável uma fila:
> 
> - [x] Controle de documentos para impressão
> - [x] Troca de mensagem entre computadores numa rede

## 3. Suponha que uma pilha possua 4 valores na seguinte ordem: 1, 2, 3 e 4. Qual seria a sequencia correta de operações de inserção (I) eliminação (E) para se obter os registros na ordem 2 4 3 1?

> ```c
> * push(1)
> * pop() // 2
> * push(3)
> * push(4)
> * push(2)
> ```

## 21. Dada as operac¸oes de pilha insere I e remove R, escreva a configuração final da pilha após as seguintes operações: I(10), I(20), R, I(30), I(45), I(21), R, R.

> * Solução ``30 -> 20``
