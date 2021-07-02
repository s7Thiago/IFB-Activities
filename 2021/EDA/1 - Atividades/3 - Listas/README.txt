Aluno : Thiago Sousa da Silva

----------------------------------------
Recursos utilizados no desenvolvimento:
----------------------------------------
    Desenvolvimento
        * Linux (Ubuntu)
        * Visual Studio Code

    Versionamento
        * Git/Github

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
        - O projeto possui 3 módulos: main, lista_encadeada e alloc onde:

            * alloc: Contém algumas funções utilitárias, como mallocx() callocx(), que encapsulam as lógicas
            de alocação dinâmica de memória;

            * lista_encadeada: Módulo que abarca as definições e implementações de lista encadeada;

            * main: O start da aplicação. Utiliza os demais módulos para manipular conjuntos de Informações
            através das implementações no TAD de lista encadeada;


================================================
Repositório do projeto: https://bit.ly/3nR7zIg
================================================
