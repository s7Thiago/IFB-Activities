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
	
}

