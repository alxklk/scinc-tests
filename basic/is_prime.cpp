#include <stdio.h>

bool is_prime2(int n)
{
	if(n<=2)
	{
		return (n==2);
	}

	if((n&1)==0){return false;}

	int max_div=n/2;
	for(int div=3;div<=max_div;div+=2)
	{
		if(n%div==0){return false;}
	}

	return true;
}

int main()
{
	for(int i=1;i<5000;i++)
	{
		if(is_prime2(i))
			printf("%i is prime\n",i);
	}
	return 0;
}