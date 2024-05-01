#include <stdio.h>

class float2
{
public:
	float x;
	float y;
	float2 operator+(const float2& r){float2 res;res.x=x+r.x;res.y=y+r.y;return res;}
	float2 operator*(float r){float2 res;res.x=x*r;res.y=y*r;return res;}
};

// TODO:
//float2 operator*(float l, const float2& r){float2 res;res.x=l*r.x;res.y=l*r.y;return res;}

int main()
{
	float2 x;
	x.x=3;
	x.y=5;
	float2 y=x*1.5;
	printf("(%f,%f)\n",y.x,y.y);
//	float2 z=1.5*y;
//	printf("(%f,%f)\n",z.x,z.y);
	return 0;
}
