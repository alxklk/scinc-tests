#include <stdio.h>

int main()
{
	int x=331;
	int* p=&x;
	(*p)++;
	printf("%i\n", x);
	return 0;
}

