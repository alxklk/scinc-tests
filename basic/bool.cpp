#include <stdio.h>
int main()
{
	printf("\nStrip\n");
	for(int i=0;i<16;i++)
	{
		printf("|");
		for(int j=0;j<16;j++)
		{
			if((j+i>=14)&&(j+i<=16))
				printf("*");
			else
				printf(" ");
		}
		printf("|\n");
	}
	printf("\nStrip not\n");
	for(int i=0;i<16;i++)
	{
		printf("|");
		for(int j=0;j<16;j++)
		{
			if(!((!(j+i>=14))||(!(j+i<=16))))
				printf("*");
			else
				printf(" ");
		}
		printf("|\n");
	}
	return 0;
}
