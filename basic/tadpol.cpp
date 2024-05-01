#include <stdio.h>

int main()
{
	int x = 5;
	int z=x-+~~-x;
	int y=x+~-x;
	printf("\nx=%i y=%i z=%i\n", x+~-x, y, z);
	printf("\n%i %i \n", x+~-x, x-~-x, x);
	printf("\n%i %i %i\n", x*~-x, x*-~x, ~-x ^ -~x);
	return 0;
}