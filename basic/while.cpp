#include <stdio.h>

int main()
{
	printf("\nWhile\n");
	int i=0;
	while(1)
	{
		i++;
		if(i<4)
		{
			printf("cont at i=%i\n",i);
			continue;
		}
		printf("i=%i\n",i);
		if(i>=8)
		{
			printf("cont at i=%i\n",i);
			break;
		}
	}
	while(0)
	{
		printf("Totally skipped\n");
	}
	return 0;
}
