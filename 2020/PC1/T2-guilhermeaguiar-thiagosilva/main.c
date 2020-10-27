#include "xmlParser.h"

extern char data[8000];
char contentsPlace[50][600];

int main(void)
{

	populateData();

	getTag(data, "title", contentsPlace);
    
    printf("Registro 1: %s\n", contentsPlace[0]);
    
    printf("\n\n");

	return 0;
}
