#include "htmlBuilder.h"

char aux[50][5000];

void resetAux(){
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 5000; j++){
            aux[i][j] = '\0';
        }
    }
}

void part1(char* data, char* buildTarget){
    resetAux();
    
//     Pegando o titulo da materia
    getTag(data, "title", aux);
    
    
    strcat(buildTarget, "<html>\n");
    strcat(buildTarget, "<head>\n");
    strcat(buildTarget, "   <title>");
    strcat(buildTarget, aux[0]);
    strcat(buildTarget, "</title>\n");
    strcat(buildTarget, "</head>\n");
    strcat(buildTarget, "</html>\n");


}

void build(char* content, char* buildTarget) {
    
    populateData();
    
    part1(content, buildTarget);
}
