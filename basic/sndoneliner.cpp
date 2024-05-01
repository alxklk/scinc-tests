#include <stdio.h>

int main()
{
	int t0=15000;
	for(int t=t0;t<t0+1000;t++)
	{
		int a1=((t*("36364689"[(t>>13)&7]&15))/12&128)
		+(((((t>>12)^(t>>12)-2)%11*t)/4|t>>13)&127);
		int il=t*2*(a1);
		float l=(il&255)/255.;
		printf("%i ",a1);
	}
	return 0;
}