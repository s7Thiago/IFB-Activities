#include "xmlParser.h"

extern char data[500000];
char itemContentsPlace[50][5000];
char linkContent[50][5000];

int main(void) {

    populateData();

    getTag(data, "item", itemContentsPlace);
    printf("Registro title: %s\n", itemContentsPlace[0]);
    
    getTag(itemContentsPlace[0], "title", linkContent);
    printf("\n\nTITLE CONTENT: %s", linkContent[0]);

    printf("\n\n");

    return 0;
}
