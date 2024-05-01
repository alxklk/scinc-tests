#include <stdio.h>

class int2
{
public:
	int x[2];
	int2 operator+(int2& r)
	{
		int2 res;
		res.x[0]=x[0]+r.x[0];
		res.x[1]=x[1]+r.x[1];
		return res;
	}
	void operator+=(int2& r)
	{
		x[0]+=r.x[0];
		x[1]+=r.x[1];
	}
};

int main()
{
	int2 c;c.x[0]=2;c.x[1]=12;
	int2 d;d.x[0]=3;d.x[1]=13;
	printf("c.x=[%i,%i]\n",c.x[0],c.x[1]);
	printf("d.x=[%i,%i]\n",d.x[0],d.x[1]);
	int2 e=c+d;
	printf("e=c+d; e.x=[%i,%i]\n",e.x[0],e.x[1]);
	e+=c;
	printf("e+=c; e.x=[%i,%i]\n",e.x[0],e.x[1]);
	return 0;
}
