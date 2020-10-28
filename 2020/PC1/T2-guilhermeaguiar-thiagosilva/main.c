#include "htmlBuilder.h"

extern char data[500000];

int main(void) {
    
    char htmlContent[40000];
       
    build(data, htmlContent);
    
    printf("\n\n%s\n\n", htmlContent);

    return 0;
}
