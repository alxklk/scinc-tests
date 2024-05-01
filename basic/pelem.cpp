#include <stdio.h>

class f1
{
public:
	int x[3];
};

class f2
{
public:
	f1 a[3];
};

int main()
{
	f2 s;
	s.a[1].x[1]=15;
	int* p=&s.a[1].x[1];
	(*p)++;
	printf("%i\n", s.a[1].x[1]);
	s.a[1].x[1]=15;
	(*p)++;
	printf("%i\n", s.a[1].x[1]);
	p[0]++;
	printf("%i\n", *p);
	p[0]=3;
	printf("%i\n", s.a[1].x[1]);
	*p=15;
	printf("%i\n", s.a[1].x[1]);
	*p+=5;
	printf("%i\n", s.a[1].x[1]);
	s.a[1].x[1]++;
	printf("%i\n", s.a[1].x[1]);
	return 0;
}

