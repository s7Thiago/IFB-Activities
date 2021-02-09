Aluno: Thiago Sousa da Silva

----------------------------------------
Recursos utilizados no desenvolvimento:
----------------------------------------
    Desenvolvimento
        * Visual Studio Code
        * Gedit
        * Linux (Ubuntu)
        * Kate

    Versionamento
        * Git/Github

    Local de avaliação:
        * Classroom

----------------------------------------
Instruções de compilação
----------------------------------------
    Passo 1:
        - make build (gera os executáveis)
    Passo 2:
        - make run (Executa o programa)

    Instruções Adicionais:
        - make all (remove os executáveis, compila o programa e roda)
        - make rm (Remove os arquivos compilados e o executável)

    Sugestão de fluxo de compilação:
        - Na primeira execução (quando não existem arquivos compilados),
        use "make build" para compilar, e nas próximas execuções,
        use make all.
        
    Funcionamento do código
        - O projeto possui 3 módulos: utils, game e search onde:
            * alloc: Contém funções utilitárias responsáveis por alocar memória;
            
            * lista_encadeada: Contém as definições e a implementação da lista encadeada
            
            * projeto3: Contém as implementações do projeto utilizando o módulo da lista encadeada;

            * in.txt: É um arquivo de entrada. para usá-lo use:
                    make build && make all < in.txt

================================================
Repositório do projeto: https://bit.ly/36Ql2dN
================================================
