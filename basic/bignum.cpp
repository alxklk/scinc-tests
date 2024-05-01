#include <stdio.h>

class bignum
{
public:
	int sign;
	int digits[20];

	void SetF(float f)
	{
		int ints=f;
		int frax=(f-ints)*10e6;
		SetII(ints,frax);
	}

	void SetII(int ints, int frax)
	{
		sign=1;
		if(ints<0)
			sign=-1;
		for(int i=0;i<20;i++)
		{
			digits[i]=0;
		}
		for(int i=0;i<10;i++)
		{
			digits[10+i]=ints%10;
			ints/=10;
			if(ints==0)
				break;
		}
		int fdec=1;
		int fstop=0;
		for(int i=0;i<10;i++)
		{
			if(frax>fdec)
				fstop=i;
			else
				break;
			fdec*=10;
		}
		for(int i=0;i<10;i++)
		{
			digits[9-fstop+i]=frax%10;
			frax/=10;
			if(frax==0)
				break;
		}
	}
	bignum operator+(bignum right)
	{
		int carry=0;
		for(int i=0;i<20;i++)
		{
			int res=digits[i]+right.digits[i]+carry;
			carry=0;
			if(res>10)
			{
				carry=1;
				res=res-10;
			}
			digits[i]=res;
		}
		bignum ret;
		ret.sign=sign;
		for(int i=0;i<20;i++)
			ret.digits[i]=digits[i];
		return ret;
	}

	void Print()
	{
		int lead=10;
		int end=10;

		for(int i=19;i>10;i--)
		{
			if(digits[i]==0)
				lead=i-1;
			else
				break;
		}
		for(int i=0;i<9;i++)
		{
			if(digits[i]==0)
				end=i;
			else
				break;
		}

		for(int i=lead;i>end;i--)
		{
			printf("%i",digits[i]);
			if(i==10)
				printf(".");
		}
	}
};

int main()
{
	bignum n;
	n.SetII(0,0);n.Print();printf("\n");
	n.SetII(1,0);n.Print();printf("\n");
	n.SetF(0.5);n.Print();printf("\n");
	n.SetII(1234567,0);n.Print();printf("\n");
	n.SetII(123,456789);n.Print();printf("\n------\n");
	{
		bignum n1;n1.SetII(1234,5555);
		bignum n2;n2.SetF(1111.1234);
		n1.Print();
		printf("+\n");
		n2.Print();
		printf("=\n");
		(n1+n2).Print();
	}
	printf("\n-------\n");
	{
		bignum n1;n1.SetII(1234,5955);
		bignum n2;n2.SetII(8919,1294);
		n1.Print();
		printf("+\n");
		n2.Print();
		printf("=\n");
		(n1+n2).Print();
	}
	printf("\n");
	return 0;
}