#include <stdio.h>

int main()
{
	printf("\nTesting nested for:\n");
	{
		for(int i=0;i<5;i++)
		{
			printf("\nrow %02i : ",i);
			for(int j=0;j<5;j++)
			{
				printf("%02i ", i*10+j);
			}
		}
	}

	{
		printf("\n\nTesting nested while:\n");
		int i=0;
		while(i++<5)
		{
			printf("\nrow %02i : ",i);
			int j=0;
			while(j++<5)
			{
				printf("%02i ", i*10+j);
			}
		}
	}
	return 0;
}
