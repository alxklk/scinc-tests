#include <stdio.h>

int rnd(int* seed)
{
	*seed=(*seed*1664525+1013904223)&0x7ffffff;
	return *seed;
}

int main()
{
	int v0;
	int v1;
	int v3;
	int s=0x17ff482;
	v0=rnd(&s);
	v3=v0<<4;
	printf("%i<<4=%i (%x<<4=%x)\n", v0,v3,v0,v3);
	v0=rnd(&s);
	v3=v0>>4;
	printf("%i>>4=%i (%x>>4=%x)\n", v0,v3,v0,v3);
	v0=rnd(&s);
	v1=rnd(&s)%8;
	v3=v0<<v1;
	printf("%i<<%i=%i (%x<<%x=%x)\n", v0,v1,v3,v0,v1,v3);
	v0=rnd(&s);
	v1=rnd(&s)%8;
	v3=v0>>v1;
	printf("%i>>%i=%i (%x>>%x=%x)\n", v0,v1,v3,v0,v1,v3);
	return 0;
}
