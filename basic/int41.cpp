#include <stdio.h>

class int4
{
public:
	int a;
	int x;
	int4 operator+(int4& r)
	{
		printf("op+ %i+%i\n",x,r.x);
		int4 res;
		res.x=x+r.x;
		return res;
	}
	int4 X2()
	{
		puts("x2");
		return *this+*this;
	}
};

int main()
{
	puts("int41");
	int4 c;c.x=12;
	int4 d=c.X2();
	printf("d %i\n",d.x);
	return 0;
}
