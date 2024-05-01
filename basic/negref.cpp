#include <stdio.h>

#ifdef SCRIP
#define const
#endif

class SF
{
public:
	float x;
};

void neg(float& x)
{
	x=-x;
}

void mul2(float& x)
{
	x*=2.;
}

float mul3(const float& x)
{
	return x*3.;
}

float mul9(const float &x)
{
	return mul3(mul3(x));
}

int main()
{
	float f[1];
	f[0]=5;

	int i0=0;
	f[i0]=-f[i0];
	printf("%f\n",f[i0]);

	SF s[1];
	s[0].x=5;
	s[i0].x=-s[i0].x;
	printf("%f\n",s[i0].x);
	neg(s[i0].x);
	printf("%f\n",s[i0].x);
	mul2(s[i0].x);
	printf("%f\n",s[i0].x);
	mul2(s[i0].x);
	printf("%f\n",mul9(s[i0].x));

	return 0;
}