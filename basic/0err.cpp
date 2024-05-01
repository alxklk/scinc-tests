#include <stdio.h>

class C0
{
public:
	int sign;
	int value;
	C0 operator+(C0 r)
	{
		if(sign!=r.sign)
		{
			r.sign=-r.sign;
			return *this-r;
		}
		C0 res;
		res.sign=sign;
		res.value=value+r.value;
		return res;
	}
	C0 operator-(C0 r)
	{
		if(sign!=r.sign)
		{
			r.sign=-r.sign;
			return *this+r;
		}
		C0 res;
		res.sign=sign;
		res.value=value-r.value;
		if(res.value<0)
		{
			res.value=-res.value;
			res.sign=-res.sign;
		}
		return res;
	}
	void Set(int isign, int ivalue)
	{
		if(isign=='+')
			this->sign=1;
		else if(isign=='-')
			this->sign=-1;
		else
			printf("Bad sign\n");
		this->value=ivalue;
	}
	void Print()
	{
		printf("%c",sign<0?'-':'+');
		printf("%i",value);
	}
};

int main()
{
	{
		C0 a;a.Set('+',33);
		C0 b;b.Set('-',25);
		C0 c=a+b;c.Print();
	}
	{
		C0 a;a.Set('-',12);
		C0 b;b.Set('-',25);
		C0 c=b-a;c.Print();
	}
	return 0;
}