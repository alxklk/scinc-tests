#include <stdio.h>

class Int
{
public:
	int x;
	Int operator+(Int r){Int res;res.x=x+r.x;return res;}
	Int operator*(Int r){Int res;res.x=x*r.x;return res;}
	Int add(Int r){Int res;res.x=x+r.x;return res;}
	Int mul(Int r){Int res;res.x=x*r.x;return res;}
};

int main()
{
	{
		int a = 1;
		int b = 2;
		int c = 3;
		int d=a+b*c;
		printf("\n%i+%i*%i=%i\n",a,b,c,d);
	}
	//{
	//	Int A; A.x = 1;
	//	Int B; B.x = 2;
	//	Int C; C.x = 3;
	//	Int D=A+B*C;
	//	printf("\n%i+%i*%i=%i\n",A.x,B.x,C.x,D.x);
	//}
	{
		Int A; A.x = 1;
		Int B; B.x = 2;
		Int C; C.x = 3;
		Int D=A.add(B.mul(C));
		printf("\n%i+%i*%i=%i\n",A.x,B.x,C.x,D.x);
	}
	return 0;
}