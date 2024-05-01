#include <stdio.h>

class flt2
{
public:
	float x;
	float y;

	void Set(float newX, float newY)
	{
		x=newX;
		y=newY;
	}
	void Print()
	{
		printf("{x=%f; y=%f;};\n",x,y);
	}
	flt2 operator+(flt2 right)
	{
		flt2 tmp;
		tmp.x=x+right.x;
		tmp.y=y+right.y;
		return tmp;
	}
};

int main()
{
	flt2 s0;
	s0.x=1;s0.y=2;
	flt2 s1;
	s1.Set(10,20);
	flt2 s3=s0+s1;
	s3.Print();
	(s0+s1).Print();
//	((s0+s1)+s0).Print();
	return 0;
}

