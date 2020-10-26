#include "xmlParser.h"
#include "fileOperations.h"

extern char *data;
extern char *title;
extern char *description;
extern char *link;

int main(void){
	FILE* fp;
	
	// Armazena o conteúdo do XML na variável `data`
	getContent(fp, data);
	

return 0;
}
