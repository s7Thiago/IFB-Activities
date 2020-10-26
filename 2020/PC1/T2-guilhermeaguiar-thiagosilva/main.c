#include "xmlParser.h"
#include "fileOperations.h"

extern char *title;
extern char *description;
extern char *link;
extern char *item;
extern char *pubDate;

int main(void){

	teste();

    int ch;
    char tag[20] ="";
    int tagEncontrada = 0;

    FILE *fp;
    FILE *html;

    fp = fopen("bbc.xml","r");
    html = fopen("bbc.html","w");


    if(fp == NULL){
        fprintf(stderr,"Erro na abertura do arquivo");
        return 1;
    }

	int d = 1;
	int g =1;

    while ((ch = fgetc(fp)) != EOF){
        if(ch =='<') {
            procurarTag(fp,tag);
            tagEncontrada = 1;   
        }
            
         if((strcmp(tag,title) == 0 ) && tagEncontrada == 1 && d == 1){
             pegarTag(fp,html);
             d++;    
             tagEncontrada = 0;
         }else if( (strcmp(tag,description) == 0 ) && tagEncontrada == 1 && g ==1){
             pegarTag(fp,html);
             g++;    
             tagEncontrada = 0;
         }
         
    }
    
    fclose(fp);

    

}
