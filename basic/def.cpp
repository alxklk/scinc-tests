#define N 5

#ifndef __SCINC__
#include <stdio.h>
#endif

int main(
#ifndef __SCINC__
int argc, char** argv
#endif
)
{

#ifdef N
	printf("N defined\n");
#endif

#ifdef N
	printf("#else: N defined\n");
#else
	printf("#else: N not defined\n");
#endif

#ifndef K
	printf("K not defined\n");
#endif

#ifdef K
	printf("K defined\n");
#endif

#ifdef K
	printf("#else: K defined\n");
#else
	printf("#else: K not defined\n");
#endif


	int x[N];
	for(int i=0;i<N;i++)
	{
		x[i]=1+i*i;
	}
	for(int i=0;i<N;i++)
	{
		printf("%i ", x[i]);
	}
	printf("\n");
	return 0;
}