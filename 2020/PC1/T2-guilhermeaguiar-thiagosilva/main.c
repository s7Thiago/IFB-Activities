#include "xmlParser.h"

extern char data[8000];
char titleContentsPlace[50][600];
char linkContentsPlace[50][600];
char urlContentsPlace[50][600];

int main(void) {

	populateData();

	getTag(data, "title", titleContentsPlace);
    printf("Registro title: %s\n", titleContentsPlace[0]);
    
    getTag(data, "link", linkContentsPlace);
    printf("Registro link: %s\n", linkContentsPlace[0]);
    
    getTag(data, "url", urlContentsPlace);
    printf("Registro url: %s\n", urlContentsPlace[0]);
    
    printf("\n\n");

	return 0;
}
