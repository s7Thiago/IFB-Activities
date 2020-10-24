#include<stdio.h>
#include<string.h>

const char *title = "title";
const char *description = "description";
const char *link = "link";



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

int main(){

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