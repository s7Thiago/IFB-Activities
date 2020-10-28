Aluno 1: Guilherme Aparecido Correia Aguiar
Aluno 2: Thiago Sousa da Silva

----------------------------------------
Recursos utilizados no desenvolvimento:
----------------------------------------
    Reuniões
        * Meet
        * Telegram

    Desenvolvimento
        * Visual Studio Code
        * Gedit
        * Linux (Ubuntu e Deepin)
        * Kate

    Versionamento
        * Git/Github

    Publicação:
        * NEAD (para a avaliação do professor)

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
    
    Fonte de dado usado
        - IFB, Campus taguatinga
        
    Funcionamento do código
        - O projeto possui 4 módulos: main, xmlParser, htmlBuilder e fileOperations onde:
            * main: Aciona os demais módulos;
            
            * xmlParser: Responsável por fazer a análise do XML e salvar o conteúdo de todas
            as recorrências de uma tag desejada em uma matriz 50 x 5000;
            
            * fileOperations: Provê acesso a recursos de leitura e gravação no disco para possibilitar
            que o XML possa ser processado dentro do programa;
            
            * htmlBuilder: responsável por utilizar as saídas obtidas pelo xmlParser e construir
            um HTML de acordo com a especificação do trabalho;
            
            

================================================
Repositório do projeto: https://bit.ly/35K5Opc
================================================
