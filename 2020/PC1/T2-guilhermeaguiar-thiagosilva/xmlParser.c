#include "xmlParser.h"

//
char data[8000];

// ######### Novas
void populateData() {
	FILE *fp;
	FILE *html;
	// Armazena o conteúdo do XML na variável `data`
	getContent(fp, data);
}

void getTag(char* searchPlace, char* tagName, char contentsPlace[][600]) {
	char openingTag[30];
	char closureTag[30];

	// Open tag
	char open[2] = "<";
	char endTag[2] = ">";

	// Tag closure
	char openClosure[3] = "</";

	// Building opening tag base
	cleanString(openingTag);
	strcat(openingTag, open);
	strcat(openingTag, tagName);
	strcat(openingTag, endTag);

	// Building opening tag base
	cleanString(closureTag);
	strcat(closureTag, openClosure);
	strcat(closureTag, tagName);
	strcat(closureTag, endTag);

	int openTagSize = strlen(openingTag);
	int closureTagSize = strlen(closureTag);

	// Auxiliares
	char auxOpeningTag[30];
	char auxClosureTag[30];
    char auxCharContentTag[2];
	char auxCharClosureTag[2];
	char auxChar[2];
    int contentsCount = 0;
	int j = 0;

	for (int i = 0; i < strlen(searchPlace); i++)
	{
		cleanString(auxChar);
		cleanString(auxOpeningTag);

		if (searchPlace[i] == '<') {
// 			Verificando ocorrências da tag de abertura no XML
			for (j = i; j < openTagSize + i; j++){
				auxChar[0] = searchPlace[j];
				auxChar[1] = '\0';
				strcat(auxOpeningTag, auxChar);
			}

// 			Verificando correspondência com a tag de abertura
			if (strcmp(auxOpeningTag, openingTag) == 0){

// 				Copia o conteúdo seguinte para `tagContents` até encontrar
// 				a tag de fechamento
				for (int k = j; k < strlen(searchPlace); k++){
                    
//                     Transferir conteúdo
//                     Building content to transfer
                    auxCharContentTag[0] = searchPlace[k];
                    auxCharContentTag[1] = '\0';
                    strcat(contentsPlace[contentsCount], auxCharContentTag);

					// Buscando tag de fechamento correspondente
					if (searchPlace[k + 1] == '<' && searchPlace[k + 2] == '/'){
                        cleanString(auxClosureTag);
                        
                        // Montando a tag de fechamento para fins de verificação
                        for(int l = k + 1; l <= closureTagSize + k; l++){
                            auxCharClosureTag[0] = searchPlace[l];
                            auxCharClosureTag[1] = '\0';
                            strcat(auxClosureTag, auxCharClosureTag);
                        }
                        
                        if(strcmp(auxClosureTag, closureTag) == 0){
                            break;
                        }
					}
				}
				contentsCount++;
			}
		}
	}
}















