#include "xmlParser.h"

//
char data[8000];
char *title = "title";
char *description = "description";
char *link = "link";

void procurarTag(FILE *fp,char tag[20]){

    int i = 0;
    int ch;
  

    while( ((ch = fgetc(fp)) != EOF) && (ch != '>') && (i < 19)){
        tag[i] = ch;
        i++;       
    }
    tag[i] = '\0';
}


void pegarTag(FILE *fp, FILE *html){
    int ch;

    fseek(fp,9,SEEK_CUR);

    while ( ((ch = fgetc(fp))!= EOF) && (ch !=']')){
        fprintf(html,"%c",ch);
    }
fprintf(html,"\n");
    
}

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
	int auxOpenCount = 0;
	int auxClosureCount = 0;

	printf("RESULTADO: %s\t%s\t(%d , %d)\n\n", openingTag, closureTag, openTagSize, closureTagSize);

	for(int i = 0; i < strlen(searchPlace); i++){
		
	}

	
}

































