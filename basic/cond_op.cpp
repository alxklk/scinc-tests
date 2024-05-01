#include <stdio.h>

float abs(float x)
{
	float r=x<0?-x:x;
	return r;
}

int main()
{
	for(float i=-3;i<=3;i++)printf("%f ",abs(i));
	return 0;
}

