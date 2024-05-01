#include <stdio.h>

int Go()
{
	int maxn=1000;
	for(int i=maxn;i>1;i--)
	{
		int comp=0;
		for(int j=2;j<i;j++)
			if(i%j==0)
			{
				comp=1;
				break;
			}
		if(comp==0)
		{
			printf("%i -- maximal prime number below %i\n", i, maxn);
//			break;
		}
	}
	return 0;
}

int main()
{
	return Go();
}
