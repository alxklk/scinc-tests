#include <stdio.h>

class srec
{
public:
	float x[2];
	void Init(float a, float b)
	{
		x[0]=a;
		x[1]=b;
	}
	srec operator+(srec& r)
	{
		printf("op+ this  %f %f\n",x[0],x[1]);
		printf("op+ r     %f %f\n",r.x[0],r.x[1]);
		float x0=x[0];
		float rx0=r.x[0];
		float x1=x[1];
		float rx1=r.x[1];
		printf("op+ x0+x1=%f\n",x0+x1);
		printf("op+ x0  %f %f\n",x0,x1);
		printf("op+ rx0 %f %f\n",rx0,rx1);
		srec res;
		res.x[0]=x[0]+rx0;
		res.x[1]=this->x[1]+r.x[1];
		printf("------\nop+ res   %f %f\n",res.x[0],res.x[1]);
		return res;
	}
	srec X20()
	{
		printf("x20 this   %f %f\n",x[0],x[1]);
		printf("x20 this-> %f %f\n",this->x[0],this->x[1]);
		printf("x20 *this. %f %f\n",(*this).x[0],(*this).x[1]);
		return *this+*this;
	}
	void print(char* s)
	{
		printf("%s=[%f, %f]\n",s,x[0],x[1]);
	}
};

srec mkRec(int a, int b)
{
	srec tmp;
	tmp.Init(a,b);
	return tmp;
}

void swap(srec& x, srec& y)
{
	srec tmp=x;
	x=y;
	x=tmp;
}

void printRec(char* s, srec& r)
{
	r.print(s);
}

int main()
{
	srec d=mkRec(35,43).X20();
	srec c;c.Init(3,5);
	swap(c,d);
	printRec("c",c);
	printRec("d",d);
	return 0;
}
