#include <stdio.h>

int rand(int *state)
{
	return *state=(*state*1103515245+12345)%0x7ffffff;
}
	
int main()
{
	int state=78762563;
	for(int i=0;i<10;i++)
	{
		printf("%i : %u\n", i, rand(&state));
	}
	return 0;
}