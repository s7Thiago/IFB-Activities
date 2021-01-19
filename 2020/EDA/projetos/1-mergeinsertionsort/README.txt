Aluno 2: Thiago Sousa da Silva

----------------------------------------
Recursos utilizados no desenvolvimento:
----------------------------------------
    Desenvolvimento
        * Visual Studio Code
        * Gedit
        * Linux (Ubuntu e Deepin)
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
        - O projeto possui 3 módulos: utils, insertion_sort e hybrid_merge_sort onde:
            * utils: Contém algumas funções utilitárias, como callocx(), printv(), e geberateEntry();
            
            * hybrid_merge_sort: Módulo que abarca a função de ordenação acessível no módulo principal, 
            além de também conter a função merge e hybrid_sort;
            
            * insertion_sort: Contém a função responsável por realizar o insertion sort;
            
            
            OBS: Para mais detalhes, consultar os comentários no código. Nos comentários do arquivo
            main.c existem alguns instruindo como adaptar as entradas para sequências de inteiros de 
            tamanho (10^4, 10^5, 10^6)
            

================================================
Repositório do projeto: https://bit.ly/3nR7zIg
================================================
