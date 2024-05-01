#include <stdio.h>

class C1
{
public:
	int x;
	int y;
};

class C2
{
public:
	char s[6];
};

int main()
{
	C2 c;
	float x=sizeof(int);
	int y=sizeof(C1);
	int z=sizeof(C2);
	float w=sizeof(x);
	printf("%f %i %i %f\n",x,y,z,w);
	return 0;
}