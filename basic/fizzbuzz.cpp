#include <stdio.h>

int main()
{
	for(int i=1;i<=100;i++)
	{
		bool printNum=true;
		if(i%3==0)
		{
			printf("Fizz");
			printNum=false;
		}
		if(i%5==0)
		{
			printf("Buzz");
			printNum=false;
		}
		if(printNum)
		{
			printf("%i",i);
		}
		printf("\n");
	}
	return 0;
}