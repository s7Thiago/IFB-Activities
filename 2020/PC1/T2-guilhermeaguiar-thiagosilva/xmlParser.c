#include "xmlParser.h"

//
char data[8000];
char tagContents[600][50];
char *title = "title";
char *description = "description";
char *link = "link";

// ######### Novas
void pupulateData(){
	FILE* fp;
	// Armazena o conteúdo do XML na variável `data`
	getContent(fp, data);
}

void getTag(char* searchPlace, char* tagName){
	char openingTag[30];
	char closureTag[30];

	//Open tag
	char open[2] = "<";
	char endTag[2] = ">";

	//Tag closure
	char openClosure[3] = "</";

	//Building opening tag
	cleanString(openingTag);
	strcat(openingTag, open);
	strcat(openingTag, tagName);
	strcat(openingTag, endTag);

	//Building opening tag
	cleanString(closureTag);
	strcat(closureTag, openClosure);
	strcat(closureTag, tagName);
	strcat(closureTag, endTag);

	int openTagSize = strlen(openingTag);
	int closureTagSize = strlen(closureTag);

	// Aux
	char auxOpeningTag[30];
	char auxClosureTag[30];
    char auxContentTag[30];
	char auxChar[2];
    char auxCharContent[2];
	int auxOpenCount = 0;
	int auxClosureCount = 0;
    int j = 0;

//	printf("RESULTADO: %s\t%s\t(%d , %d)\n\n", openingTag, closureTag, openTagSize, closureTagSize);

	for(int i = 0; i < strlen(searchPlace); i++){
		cleanString(auxChar);
		cleanString(auxOpeningTag);

		if(searchPlace[i] == '<'){
			// Verificando ocorrências da tag de abertura no XML
			for(j = i; j < openTagSize + i; j++){
					auxChar[0] = searchPlace[j];
					auxChar[1] = '\0';
					strcat(auxOpeningTag, auxChar);
			}
			
// 			Verificando correspondência com a tag de abertura
			if(strcmp(auxOpeningTag, openingTag) == 0){
//                 Tags de abertura
//                 printf("\n%s\n", auxOpeningTag);
                
//                 Copia o conteúdo seguinte para `tagContents` até encontrar 
//                 a tag de fechamento
                for(int k = j; k < strlen(searchPlace); k++) {
                    
					 printf("%c",searchPlace[k]);			 
//                   Buscando tag de fechamento correspondente
                        if(searchPlace[k + 1] == '<' && searchPlace[k + 2] == '/'){					
							printf("\n");
							break;
                         }
                }
			}

		}
	}

	
}

































