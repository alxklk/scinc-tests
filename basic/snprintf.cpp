#include <stdio.h>

int main()
{
	char s[64];
	int i=331;
	float f=3.14;
	snprintf(s,64,"%s %i %f\n", "Hi", i, f);
	puts(s);
	printf("%s %i %f\n", "Hi", i, f);
	return 0;
}

