#include <stdio.h>

void ref(int& x)
{
	x=135;
	printf("ref  %i\n",x);
}

int main()
{
	int x=5;
	printf("main %i\n",x);
	ref(x);
	printf("main %i\n",x);
	return 0;
}

