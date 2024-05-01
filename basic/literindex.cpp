#include <stdio.h>

int main()
{
	char* hex="0123456789ABCDEF";
	for(int i=0;i<16;i++)
		printf("%c",hex[i]);
	int i=2;
	char c="abc"[i];
	printf("\n%c",c);
	printf("\n%c","abc"[1]);
	printf("\n%c","abc"[i]);
	for(int i=0;i<16;i++)
		printf("%c","0123456789ABCDEF"[i]);
	printf("\n%c","0123456789ABCDEF"[15]);
	return 0;
}