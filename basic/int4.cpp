#include <stdio.h>

class int4
{
public:
	int x[2];
	void Init(int ix, int iy)
	{
		x[0]=ix;
		x[1]=iy;
	}
	int4 operator+(int4 r)
	{
		printf("op+ this  %i %i\n",x[0],x[1]);
		int4 res;res.Init(0,0);
		res.x[0]=x[0]+r.x[0];
		res.x[1]=x[1]+r.x[1];
		printf("op+ r     %i %i\n",r.x[0],r.x[1]);
		printf("op+ x2    %i %i\n",res.x[0],res.x[1]);
		return res;
	}
	int more(int4 r)
	{
		for(int i=0;i<2;i++)
		if(x[i]>r.x[i])return i;
		return -1;
	}
	int4 X2()
	{
		//printf("x2 this   %i %i %i %i\n",x[0],x[1],x[2],x[3]);
		//printf("x2 this-> %i %i %i %i\n",this->x[0],this->x[1],this->x[2],this->x[3]);
		//printf("x2 *this. %i %i %i %i\n",(*this).x[0],(*this).x[1],(*this).x[2],(*this).x[3]);
		//int4 tmp=*this;
		//return tmp+*this;
		//return *this+tmp;
		return *this+*this;
	}
};

int4 Int4(int x, int y)
{
	int4 tmp;
	tmp.Init(x,y);
	return tmp;
}

int main()
{
	int4 c;c.Init(12,37);
	int4 d=Int4(1,2).X2();
	printf("d %i %i\n",d.x[0],d.x[1]);
	int4 e=Int4(1,1);
	printf("%i",e.more(Int4(2,1)));
	return 0;
}
