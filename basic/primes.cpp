#include <stdio.h>

int Go()
{
	int start=99900;
	int stop=start+1000;
	printf("Primes between %i and %i\n", start, stop);
	for(int i=start;i<stop;i++)
	{
		int comp=0;
		for(int j=2;j<i/2;j++)
		{
			// Ugly code to check implicit type converions
			float f=i;
			float rf=f/j;
			int r=i/j;
			float ri=r;
			if(rf==ri)
			{
				comp=1;
				break;
			}
		}
		if(comp==0)
		{
			printf("%i -- prime\n",i);
		}
	}
	return 0;
}

int main()
{
	return Go();
}
