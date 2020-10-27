#include "xmlParser.h"

extern char data[8000];

int main(void){
	
	populateData();

	getTag(data, "calories");
	

return 0;
}
