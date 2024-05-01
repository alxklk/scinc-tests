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
	flt2 purp()
	{
		flt2 tmp;
		tmp.x=y;
		tmp.y=-x;
		return tmp;
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
	flt2 operator+=(flt2 right)
	{
		x+=right.x;
		y+=right.y;
		flt2 tmp;
		tmp.x=x;
		tmp.y=y;
		return tmp;
	}
	flt2 operator-()
	{
		flt2 tmp;
		tmp.x=-x;
		tmp.y=-y;
		return tmp;
	}
	flt2 add(flt2 right)
	{
		flt2 tmp;
		tmp.x=x+right.x;
		tmp.y=y+right.y;
		return tmp;
	}
};

void testop()
{
	flt2 a;
	flt2 b;
	flt2 c=a+b;
}

flt2 purp(flt2 p)
{
	flt2 tmp;
	tmp.Set(p.y,-p.x);
	return tmp;
}

class rect
{
public:
	flt2 p;
	flt2 s;
};

rect mkrect()
{
	rect tmp;
	tmp.p.Set(1,2);
	tmp.s.Set(3,4);
	return tmp;
}

flt2 yx(flt2 xy)
{
	flt2 tmp;
	tmp.Set(xy.y,xy.x);
	return tmp;
}


void Swap(float* x, float*y)
{
	float tmp=*x;
	*x=*y;
}

int main()
{
	flt2 s0;
	s0.x=1;s0.y=2;
	flt2 s1;
	s1.x=10;s1.y=20;
	(s1+=s0).Print();
	s1.Print();
	float f0=1;
	float f1=2;

	flt2 s=-s0;
	s.Print();

	float f=-s0.x;
	printf("%f\n",f);
	
	{flt2 t=s0+s1;}
	{float t=f0+f1;}
	flt2 t=s0;
	(-t).Print();
	s0.add(s1).Print();
	((s0+s1)+s0).Print();

	s0.x=1;
	s0.y=2;
	s1.x=3;
	s1.y=4;
	t=s1;
	t.Print();
	t=s0+s1;
	t.Print();
	t=s0.add(s1);
	t.Print();
	int x0=5;
	int x1=6;
	int y=x0+x1;
	printf("%i\n",y);
	flt2 t0=s.purp();
	flt2 t1=purp(s);
	t=t0+t1;
	s=yx(s);
	s.purp().Print();
	t0.Print();
	t1.Print();
	mkrect().s.purp().Print();
	flt2 n=mkrect().s;
	float x=mkrect().s.x;
	printf("%f\n",x);
	printf("%f\n",yx(n).x);

	return 0;
}

