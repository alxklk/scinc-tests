int mullog;

#ifndef __SCINC__
#include <stdio.h>
#else
#define const
#endif

class int2
{
public:
	int x;
	void Sets(char* num)
	{
		x=num[0]-'0';
	}

	int2 operator*(const int2& right)
	{
		int2 ret;
		ret.x=x*right.x;
		return ret;
	}

	int2 operator+(const int2& right)
	{
		int2 ret;
		ret.x=x+right.x;
		return ret;
	}

	int2 operator-(const int2& right)
	{
		// Removed because order of execution is implementation dependent and cannot serve as a test subject
		//printf("Binary %i-%i=%i\n",x,right.x,x-right.x);
		int2 ret;
		ret.x=x-right.x;
		return ret;
	}

	int2 operator-()
	{
		// Removed because order of execution is implementation dependent and cannot serve as a test subject
		//printf("Unary -%i=%i\n",x,-x);
		int2 ret=*this;
		ret.x=-ret.x;
		return ret;
	}

	void Print()
	{
		printf("[%i]",x);
	}
};


int main(
#ifndef __SCINC__
int argc, char** argv
#endif
)
{
	int2 a;int2 b;int2 c;
	a.Sets("2");b.Sets("3");c.Sets("4");
	printf("a=");a.Print();printf(" b=");b.Print();printf(" c=");c.Print();printf("\n");
	// TODO: find bug in argument passing for operators
	int2 d=c+a*b-c*-b+a*-(b+c)+-(b-a)*(c+c);
	printf("d=");
	d.Print();
	printf("\n");
	d=-b-a;
	printf("d=");
	d.Print();
	printf("\n");
	return 0;
}