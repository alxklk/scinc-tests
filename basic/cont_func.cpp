#include <stdio.h>

class flt2
{
public:
	float a[2];
	float* x;
	void Init(){x=&a[0];}
	float& at(int i){return x[i];}
};

void swap(float& x, float& y)
{
	float tmp=x;x=y;y=tmp;
}

int main()
{
	flt2 s0;
	s0.Init();
	s0.at(0)=3;
	s0.at(1)=20;
	for(int i=0;i<2;i++)printf("%f ",s0.at(i));
	puts("\nswap");
	swap(s0.at(0),s0.a[1]);
	for(int i=0;i<2;i++)printf("%f ",s0.a[i]);
	for(int i=0;i<2;i++)printf("%f ",s0.at(i));
	return 0;
}

