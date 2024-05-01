#include <stdio.h>

void odd(int x)
{
	if(x&1)
		return;
	puts("odd");
}

int main()
{
	for(int i=0;i<5;i++)
		odd(i);
	return 0;
}

