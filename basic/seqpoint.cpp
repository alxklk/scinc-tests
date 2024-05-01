#include <stdio.h>

int main()
{
	int x=5;
	int* p=&x;
	printf("\n%i %i %i\n", x++, ++x, *p);
	return 0;
}