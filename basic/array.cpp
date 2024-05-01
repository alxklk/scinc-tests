#include <stdio.h>

void swap(int* x, int*y)
{
	int tmp=*x;
	*x=*y;
	*y=tmp;
}

int main()
{
	int v[10];
	for(int i=0;i<10;i++)
	{
		v[i]=i;
	}

	for(int i=0;i<10;i++)
	{
		printf("%i ", v[i]);
	}
	printf("\nSwap\n");

	for(int i=0;i<5;i++)
	{
		swap(&v[i],&v[9-i]);
	}

	for(int i=0;i<10;i++)
	{
		printf("%i ", v[i]);
	}
	printf("\n");

	return 0;
}
