#include <stdio.h>

int main()
{
	float f;
	f=.5f;printf("%f\n", f);
	f=0.5;printf("%f\n", f);
	f=3.f;printf("%f\n", f);
	f=5e2;printf("%f\n", f);
	f=-.5f;printf("%f\n", f);
	f=-0.5;printf("%f\n", f);
	f=-3.f;printf("%f\n", f);
	f=-5e-2;printf("%f\n", f);
	int x;
	x=0xff67f;printf("%i\n", x);
	x=073672;printf("%i\n", x);
	x=79872;printf("%i\n", x);
	x=-0xff67f;printf("%i\n", x);
	x=-073672;printf("%i\n", x);
	x=-79872;printf("%i\n", x);
	return 0;
}