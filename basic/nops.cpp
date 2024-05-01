#include <stdio.h>

class flt2
{
public:
	float x;
	void Print()
	{
		printf("{x=%f;};\n",x);
	}
	flt2 operator+(flt2 right)
	{
		flt2 tmp;
		tmp.x=x+right.x;
		return tmp;
	}
};

int test(int c, char* v)
{
	return 0;
}

int main()
{
	int x=test(0,"");
	flt2 s0;
	s0.x=1;
	flt2 s1;
	s1.x=3;
	flt2 s2=s0+s1;
	printf("{x=%f;};\n",s2.x);
//	(s0+s1).Print();
	return 0;
}

