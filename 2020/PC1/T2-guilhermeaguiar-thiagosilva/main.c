#include "xmlParser.h"

extern char data[8000];
extern char tagContents[50][600];

int main(void)
{

	populateData();
    
    //
//     printf("Registro 1 (%d):\n%s", tagContents[0]), strlen(tagContents[0]);
    printf("Registro 1: %s\n", tagContents[0]);

	getTag(data, "title");
    
    printf("\n\n");

	return 0;
}
