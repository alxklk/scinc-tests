#include <stdio.h>

void add(int* x, int *y, int* z){*x=*y+*z;}

int main()
{
	int x=0;
	int y=10;
	int z=12;
	printf("%i+%i=", y, z);add(&x,&y,&z);printf("%i\n", x);
	printf("%i+%i=", x, x);add(&x,&x,&x);printf("%i\n", x);
	printf("%i+%i=", x, z);add(&x,&x,&z);printf("%i\n", x);
	return 0;
}