#include <stdio.h>

int Go()
{
	for(int i=5000;i<5050;i++)
	{
		int sq=0;
		int n;
		for(int j=1;j<i;j++)
		{
			if(j*j==i)
			{
				sq=i;
				n=j;
			}
		}
		if(sq)
		{
			printf("%i = %i^2\n", sq, n);
		}
	}
	return 0;
}

int main()
{
	return Go();
}
