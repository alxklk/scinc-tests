#include <stdio.h>

int rnd(int* seed)
{
	*seed=(*seed*1664525+1013904223)&0x7ffffff;
	return *seed;
}

void randomize(int* a0, int* a1, int *s)
{
	*a0=rnd(s);
	*a1=rnd(s);
}

int main()
{
	int v0=0; int v1=0;
	int seed=0x17ff482;
	for(int i=1002;i>1000;i--)
	{
		printf("\n Cycle %i begin\n", i);
		
		{randomize(&v0,&v1,&seed);int v3=v0+v1 ;printf("%i  + %i = %i (%x  + %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0-v1 ;printf("%i  - %i = %i (%x  - %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0/v1 ;printf("%i  / %i = %i (%x  / %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0*v1 ;printf("%i  * %i = %i (%x  * %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0%v1 ;printf("%i %% %i = %i (%x %% %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0&v1 ;printf("%i  & %i = %i (%x  & %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0|v1 ;printf("%i  | %i = %i (%x  | %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0^v1 ;printf("%i  ^ %i = %i (%x  ^ %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0||v1;printf("%i || %i = %i (%x || %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=v0&&v1;printf("%i && %i = %i (%x && %x=%x)\n", v0,v1,v3,v0,v1,v3);};
		{randomize(&v0,&v1,&seed);int v3=~v0;printf("~%i = %i (~%x=%x)\n", v0,v3,v0,v3);};

		printf("\n Cycle %i end\n", i);
	}
	return 0;
}
