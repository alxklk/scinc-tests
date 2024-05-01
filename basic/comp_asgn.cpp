#include <stdio.h>

int eseed;

int irand()
{
	eseed=(eseed*1103515245+12345)%0x7ffffff;
	return eseed;
}

int main()
{
	eseed=7236491;
	float k=1;
	for(float f=0;f<1;f+=0.1)
	{
		printf("%3.1f ",f);
		float j=k*=2.0;
		printf("%3.1f %3.1f ",k,j);
	}
	printf("\n");
	
	int v1=2;
	int v0=(v1+v1)*(v1*7+4);
	printf("v0=%i, v1=%i\n", v0,v1);
	v0+=v1;
#define N 3
	for(int i=0;i<N;i++){v0=irand();v1=irand()&5;int v3=v0<<=v1;printf("v3=v0<<=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=irand()&5;int v3=v0>>=v1;printf("v3=v0>>=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=irand();int v3=v0+=v1;printf("v3=v0+=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=irand();int v3=v0-=v1;printf("v3=v0-=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=irand();int v3=v0*=v1;printf("v3=v0*=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=(irand()&64)+1;int v3=v0/=v1;printf("v3=v0/=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=(irand()&64)+1;int v3=v0%=v1;printf("v3=v0%%=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=irand();int v3=v0&=v1;printf("v3=v0&=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=irand();int v3=v0^=v1;printf("v3=v0^=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	for(int i=0;i<N;i++){v0=irand();v1=irand();int v3=v0|=v1;printf("v3=v0|=v1 : v0=%i, v1=%i, v3=%i\n", v0,v1,v3);}
	return 0;
}
