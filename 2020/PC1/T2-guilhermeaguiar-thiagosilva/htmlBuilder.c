#include "htmlBuilder.h"

char aux[50][5000];

void resetAux(){
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 5000; j++){
            aux[i][j] = '\0';
        }
    }
}

void buildHeader(char* data, char* buildTarget){
    resetAux();
    
//     Pegando o titulo da matéria
        getTag(data, "title", aux);
    
    
    strcat(buildTarget, "<html>\n");
    strcat(buildTarget, "<head>\n");
    strcat(buildTarget, "   <title>");
    strcat(buildTarget, aux[0]);
    strcat(buildTarget, "</title>\n");
    strcat(buildTarget, "</head>\n");
}

void buildInnerBodyItems(char* data, char* buildTarget, int index){
    
    resetAux();
    getTag(data, "title", aux);
    strcat(buildTarget, "\n<h2>");
    strcat(buildTarget, aux[index]);
    strcat(buildTarget, "</h2>");
    
    resetAux();
    getTag(data, "description", aux);    
    strcat(buildTarget, "\n<p>");
    strcat(buildTarget, aux[index]);
    strcat(buildTarget, "    </p>");
    
    resetAux();
    getTag(data, "link", aux);    
    strcat(buildTarget, "\n<a href=\"");
    strcat(buildTarget, aux[index]);
    strcat(buildTarget, "</a>");
    
    resetAux();
    getTag(data, "pubDate", aux);    
    strcat(buildTarget, "\n<p>");
    strcat(buildTarget, aux[index]);
    strcat(buildTarget, "</p>");
}

void buildInnerBody(char* data, char* buildTarget){
    strcat(buildTarget, "<h1>");
    strcat(buildTarget, aux[0]);
    strcat(buildTarget, "</h1>\n   <br>\n");
    strcat(buildTarget, "   <a href=\"");
    
//     Extração do link
    resetAux();
    
//     Pegando o link da materia
    getTag(data, "link", aux);
    
//     Inserindo o link no HTML
    strcat(buildTarget, aux[0]);
    strcat(buildTarget, "\"");
    
    strcat(buildTarget, "> ");
    strcat(buildTarget, aux[0]);
    strcat(buildTarget, " </a>\n   <br>\n   <p> ");
    
//     Extração da descrição do canal
    resetAux();
    
//     Pegando a descrição da materia
    getTag(data, "description", aux);
    
//     Inserindo a descrição no HTML
    strcat(buildTarget, aux[0]);
    strcat(buildTarget, " </p>\n\n");
    
//     Construindo itens das notícias
    resetAux();
    
    int itemsCount = 0;
    getTag(data, "item", aux);
    
    // Contando as tags <item>
    for(int i = 0; i < 50; i++){
        itemsCount++;
        if(aux[i][0] == '\0'){
            break;
        }
    }
    
    printf("Quantidade de TAGS: %d", itemsCount);
    
    // 'Materializando' as tags <item>
    for(int i = 1; i < itemsCount; i++){
    strcat(buildTarget, "\n\n   <hr> ");
        buildInnerBodyItems(data, buildTarget, i);
        
//     strcat(buildTarget, "\n\n   <hr>");
    }
    
}

void buildBody(char* data, char* buildTarget){
    strcat(buildTarget, "<body>\n\n");
    buildInnerBody(data, buildTarget);
    strcat(buildTarget, "\n\n</body>\n</html>");
}

void build(char* content, char* buildTarget) {
    
    populateData();
    
    buildHeader(content, buildTarget);
    buildBody(content, buildTarget);
}





















