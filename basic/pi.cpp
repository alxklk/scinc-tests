#include <stdio.h>

double calcPI(double N)
{
	double sum=2.;
	double nx=2;
	for(double n=1.;n<N;n++)
	{
		nx=nx*n/(2.0*n+1.);
		sum=sum+nx;
	}
	return sum;
}

int main()
{
	for(int i=1;i<29;i++)
	{
		printf("pi#%i=%.8f\n",i,calcPI(i));
	}
	printf("355/113=%.8f\n", 355.0/113.0);
	return 0;
}