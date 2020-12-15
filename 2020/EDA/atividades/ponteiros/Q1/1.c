#include <stdio.h>

int main (int argc, char *argv[]) {
	
	int x, y, *p;
	y = 0;
	p = &y;
	x = *p;
	
	x = 4;
	(*p)++;
	--x;
	(*p) += x;
	
	
	printf("x:%d\ny:%d\np:%d\n\n", x, y, *p);
	
	return 0;
}
