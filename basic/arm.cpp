#include <stdio.h>
class f2
{
public:
	float v[1];
	float* p;
};

float Do1(f2* f)
{
	return f->v[0];
}

float Do2(f2* f)
{
	return *f->p;
}

int main()
{
	f2 s;
	float f=0.33;
	s.v[0]=0.25;
	s.p=&f;
	
	printf("%f ", Do1(&s));
	printf("%f ", Do2(&s));

	return 0;
}

