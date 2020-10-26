#include "xmlParser.h"

extern char data[8000];
extern char *title;
extern char *description;
extern char *link;

int main(void){
	
	pupulateData();

	printf("%s", data);
	

return 0;
}
