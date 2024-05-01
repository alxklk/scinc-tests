#include <stdio.h>

int main()
{
	printf("Testing imcrement and decrement, results: 0,0,2\n");
	int i=36;
	printf("i=%i\n",i);

	i++;
	printf("'i++' -> %i\n",i);
	++i;
	printf("'++i' -> %i\n",i);

	i--;
	printf("'i--' -> %i\n",i);
	--i;
	printf("'--i' -> %i\n",i);

	printf("inline 'i--' -> %i\n",i--);
	printf("inline '--i' -> %i\n",--i);
	printf("i=%i\n",i);

	i+=5;
	printf("i+=5 -> %i\n",i);
	printf("inline i+=5 -> %i\n",i+=5);
	printf("i=%i\n",i);

	return 0;
}
