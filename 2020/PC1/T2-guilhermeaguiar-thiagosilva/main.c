#include "xmlParser.h"
#include "fileOperations.h"

extern char *title;
extern char *description;
extern char *link;

int main(void){
	FILE* fp;
	char target[1000];
	
	getContent(fp, target);
	printf("\nRESULTADO = \n%s\n\n", target);

return 0;
}
