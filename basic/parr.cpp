#include <stdio.h>

#define N 3

class f1
{
public:
	int x[3];
};

class f2
{
public:
	float f;
	float v[1];
	f1 a[3];
	float* p;
};

int main()
{
	f2 s;
	s.a[0].x[2]=15;
	int* fp=&s.a[0].x[2];
	f2* p=&s;
	printf("%i\n", p->a[0].x[2]);
	int i=0;
	s.a[i].x[(i+1)*2+1]=11;
	printf("%i\n", p->a[i].x[(i+1)*2+1]);
	printf("%i\n", p->a[0].x[2]);
	p->v[i]=44.0;
	printf("%f\n", p->v[0]);
	printf("%f\n", p->v[i]);
	printf("%f\n", (*p).v[0]);
	printf("%f\n", (*p).v[i]);
	s.v[0]=55.0;
	printf("%f\n", s.v[0]);
	printf("%f\n", s.v[i]);
	s.f=33.0;
	printf("%f\n", s.f);
	s.p=&s.f;
	printf("%f\n", *s.p);
	printf("%f\n", s.p[0]);
	printf("%f\n", s.p[i]);
	printf("%i\n", p->a[0].x[2]);
	(*fp)++;
	printf("%i\n", p->a[0].x[2]);
	
	return 0;
}

