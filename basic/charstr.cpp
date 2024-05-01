#include <stdio.h>

#define N 9

void Print(float f)
{
	char sd[N];
	int nc=0;
	if(f<0)
	{
		sd[nc++]='-';
		printf("-");
		f=-f;
	}
	int dot=0;
	while(f>10)
	{
		f/=10.;
		dot++;
	}
	for(int i=0;i<N-3;i++)
	{
		int d=f;
		f=f-d;
		f*=10.;
		printf("%i",d);
		sd[nc++]="0123456789"[d];
		if(i==dot)
		{
			sd[nc++]='.';
			printf(".");
		}
	}
	sd[nc++]=0;
	printf("\n");
	printf("%s\n",sd);
}


int main(
#ifndef __SCINC__
int argc, char** argv
#endif
)
{
	for(int i=275;i<1748;i+=311)
	{
		float v=10000.0f/i;
		printf("\n%.4f\n",v);
		Print(v);
	}
	return 0;
}
