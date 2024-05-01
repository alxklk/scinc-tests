#include <stdio.h>

struct cplx
{
	float re;
	float im;
	cplx operator*(float r)
	{
		cplx res;
		res.re=re*r;
		res.im=im*r;
		return res;
	}
	cplx operator *(cplx& r)
	{
		cplx res;
		res.re=re*r.re-im*r.im;
		res.im=im*r.re+r.im*re;
		return res;
	}
};

int main()
{
	cplx x;
	x.re=3;
	x.im=5;
	cplx y=x*1.5;
	printf("(%f,%f)\n",y.re,y.im);
	y.re=2;
	y.re=7;
	y=y*x;
	printf("(%f,%f)\n",y.re,y.im);
	return 0;
}
