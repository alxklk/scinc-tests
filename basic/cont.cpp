#include <stdio.h>

class flt2
{
	float x[2];
public:
	float& get(int i){return x[i];}
};

void swap(float& x, float& y)
{
	float tmp=x;x=y;y=tmp;
}

int main()
{
	flt2 s0;
	s0.get(0)=3;
	s0.get(1)=20;
	for(int i=0;i<2;i++)printf("%f ",s0.get(i));
	puts("\nswap");
	swap(s0.get(0),s0.get(1));
	for(int i=0;i<2;i++)printf("%f ",s0.get(i));
	return 0;
}

