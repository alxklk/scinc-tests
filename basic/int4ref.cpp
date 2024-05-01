#include <stdio.h>

class ivec
{
public:
	int x[2];
};

void printr(ivec&v)
{
	printf("x=[%i,%i]\n", v.x[0], v.x[1]);
}

int main()
{
	ivec c;c.x[0]=163;c.x[1]=284;
	ivec* pc=&c;
	printr(c);
	printr(*pc);
	return 0;
}
