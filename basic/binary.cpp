#include <stdio.h>

void printbin(int b)
{
	int t=1;
	t<<=31;
	for(int i=0;i<32;i++)
	{
		if(b&t)
			printf("1");
		else
			printf("0");
		if(i%4==3)
			printf(" ");
		t>>=1;
		t&=0x7fffffff;
	}
	printf("\n");
}

void printhex(int b)
{
	int t=0xf;
	for(int i=0;i<8;i++)
	{
		int r=((b>>((7-i)*4))&t);
		printf("  %c  ", "0123456789ABCDEF"[r]);
	}
	printf(" %x\n", b);
}

int rnd(int *state)
{
	int newState=*state*1103515245+12345;
	newState=newState-(newState/0x7fffffff)*0x7fffffff;
	return *state=newState>>1;
}
int main()
{
	int state=345345;
	for(int i=0;i<5;i++)
	{
		int x=rnd(&state);
		printbin(x);
		printhex(x);
	}
	return 0;
}
