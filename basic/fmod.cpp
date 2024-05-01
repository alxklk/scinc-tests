#include <stdio.h>
#include <math.h>

float fnear(float x, float y)
{
	int r=x/y+.5;
	if(x<0)r--;
	return x-r*y;
}

int main()
{
	float x;
	float y;
	float z;
	x=5   ;y= 3;z=fnear(x,y);printf("fmod(%5.3f,%5.3f)=%5.3f\n",x,y,z);
	x=15  ;y=10;z=fnear(x,y);printf("fmod(%5.3f,%5.3f)=%5.3f\n",x,y,z);
	x=126 ;y=20;z=fnear(x,y);printf("fmod(%5.3f,%5.3f)=%5.3f\n",x,y,z);
	x=-5  ;y= 3;z=fnear(x,y);printf("fmod(%5.3f,%5.3f)=%5.3f\n",x,y,z);
	x=-15 ;y=10;z=fnear(x,y);printf("fmod(%5.3f,%5.3f)=%5.3f\n",x,y,z);
	x=-127;y=20;z=fnear(x,y);printf("fmod(%5.3f,%5.3f)=%5.3f\n",x,y,z);
	return 0;
}
