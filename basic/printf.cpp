#include <stdio.h>

int main()
{
	printf("%s\n","abcdefghijklmnopqrstuvwxyz");
	char s[27];
	for(int i=0;i<27;i++)
		s[i]='a'+i;
	s[26]=0;
	printf("%s\n",s);

	printf("%i, %3.1f, '%s'\n", 0, 1.0/13.0, "test");
	printf("%.4f\n", 1365.1264775);
	printf("%.5f\n", 1000.0/17.0);
	return 0;
}