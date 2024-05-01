#include <stdio.h>

#define WHILE
#define IFTRUE
#define IFFALSE
#define IFFALSEELSE
#define IFTRUEELSE

int main()
{
	printf("Constant conditions\n");

#ifdef IFFALSE
	printf("if false\n");
	if(false)
	{
		printf("23\n");
		printf("234234");
	}
#endif

#ifdef IFTRUE
	printf("if true\n");
	if(true)
	{
		printf("12\n");
	}
#endif

#ifdef IFFALSEELSE
	printf("if false else\n");
	if(false)
	{
		printf("34\n");
	}
	else
	{
		printf("43\n");
	}
#endif

#ifdef IFTRUEELSE
	printf("if true else\n");
	if(false)
	{
		printf("778\n");
	}
	else
	{
		printf("887\n");
	}
#endif

#ifdef WHILE
	printf("\nwhile false\n");
	while(false)
	{
		printf("...\n");
		break;
	}
	printf("\nwhile true\n");
	while(true)
	{
		printf("...\n");
		break;
	}
	printf("\nwhile true count\n");
	int i=0;
	while(true)
	{
		printf("...%i\n",i);
		if(i++>5)
			break;
	}
	printf("\n");
#endif
	printf("-----\n");
	return 0;
}
