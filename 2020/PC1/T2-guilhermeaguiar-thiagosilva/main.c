#include "htmlBuilder.h"

extern char data[500000];

int main(void) {
    
    char htmlContent[40000];
       
    build(data, htmlContent);
    
    saveHmtl(htmlContent);

    return 0;
}
