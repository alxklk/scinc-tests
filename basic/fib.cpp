#include <stdio.h>

int fib(int x)
{
	if(x==0)
		return 1;
	if(x==1)
		return 1;
	return fib(x-1)+fib(x-2);
}

int main()
{
	for(int i=0;i<33;i++)
		printf("fib(%i)=%i\n", i, fib(i));
	return 0;
}