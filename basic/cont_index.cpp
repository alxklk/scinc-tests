#include <stdio.h>

class flt2
{
	float x[3];
public:
	float& operator[](int i)
	{
		if((i<0)||(i>1))
		{
			printf("\nIndex out of range %i\n", i);
			i=2;
			return x[i];
		}
		return x[i];
	}
};

void swap(float& x, float& y)
{
	float tmp=x;x=y;y=tmp;
}

int main()
{
	flt2 s0;
	s0[0]=12;
	s0[1]=20;
	for(int i=0;i<2;i++)printf("%f ",s0[i]);
	s0[2]=5;
	puts("swap\n");
	swap(s0[0],s0[1]);
	for(int i=0;i<2;i++)printf("%f ",s0[i]);
	puts("\nOut of range\n");
	for(int i=-3;i<4;i++)printf("%f ",s0[i]);
	return 0;
}

