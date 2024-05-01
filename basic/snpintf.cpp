#include <stdio.h>

int main()
{
	int i=331;
	float f=3.14;
	char s[64];
	snprintf(s,64,"%s %i %f\n", "Hi", i, f);
	puts(s);
	return 0;
}

