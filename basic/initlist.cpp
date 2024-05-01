#include <stdio.h>

struct flt2{ float x; float y;};

int main()
{
/*
	flt2 a={.5,.7};
	printf("%f %f\n",a.x,a.y);
	flt2 b={.7};
	printf("%f %f\n",b.x,b.y);
*/
	int y[3]={3+2*2};
	printf("%i %i %i\n",y[0],y[1],y[2]);
	int z[3]={};
	printf("%i %i %i\n",z[0],z[1],z[2]);
	int x[3]={3,5,3*2};
	printf("%i %i %i\n",x[0],x[1],x[2]);
	float f[5]={1,.5,.77,2.4};
	printf("%f %f %f %f %f\n",f[0],f[1],f[2],f[3],f[4]);
	float g[5]={(77-2)/5.};
	printf("%f %f %f %f %f\n",g[0],g[1],g[2],g[3],g[4]);
	return 0;
}