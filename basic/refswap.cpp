#include <stdio.h>

class box
{
public:
	float x[2];
};

void printr(char* s, box&v)
{
	printf("%s=[%f,%f]\n", s, v.x[0], v.x[1]);
}

void swapr(box&l, box&r)
{
	box tmp=r;
	r=l;
	l=tmp;
}

void swaprf(float &l, float &r)
{
	float tmp=r;
	r=l;
	l=tmp;
}

void swappf(float *l, float *r)
{
	float tmp=*r;
	*r=*l;
	*l=tmp;
}

void swapp(box*l, box*r)
{
	box tmp=*r;
	*r=*l;
	*l=tmp;
}

int main()
{
	box c;c.x[0]=163;c.x[1]=284;
	box d;d.x[0]=601;d.x[1]=805;
	printr("c",c);
	printr("d",d);

	puts("\n----- SWAP & -----\n");
	swapr(c,d);
	printr("c",c);
	printr("d",d);

	puts("\n----- SWAP * -----\n");
	swapp(&c,&d);
	printr("c",c);
	printr("d",d);

	puts("\n----- SWAP float &-----\n");
	swaprf(c.x[0],c.x[1]);
	printr("c",c);

	puts("\n----- SWAP float *-----\n");
	swappf(&c.x[0],&c.x[1]);
	printr("c",c);
	return 0;
}
