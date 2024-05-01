#ifndef __SCINC__
#include <stdio.h>
#else
#define const
#endif

#define N 10
#define Nd (N/2)

#define mullog false

int pow_of_2(int v)
{
	int r=0;
	while(v>>=1)
	{
		r++;
	}
	return r;
}

class bigint
{
public:
	int sign;
	int digits[N];
	void Zero()
	{
		sign=1;
		for(int i=0;i<N;i++)digits[i]=0;
	}
	void Seti(int x)
	{
		Zero();
		if(x)
		{
			if(x<0)
			{
				sign=-1;
				x=-x;
			}
			for(int i=0;i<(N-Nd);i++)
			{
				digits[Nd+i]=x%10;
				x/=10;
				if(x==0)
					break;
			}
		}
	}

	void Sets(char* num)
	{
		Zero();
		int istart=0;
		sign=1;
		if(num[0]=='-')
		{
			sign=-1;
			istart=1;
		}
		int iend=0;
		for(int i=istart;i<N;i++)
		{
			if(num[i]=='.')
			{
				iend=i;
				break;
			}
			if(num[i]==0)
			{
				iend=i;
				break;
			}
		}
		for(int i=iend-1;i>=istart;i--)
		{
			int index=Nd-1+(iend-istart)-(i-istart);
			digits[index]=num[i]-'0';
		}
		if(num[iend]=='.')
		{
			for(int i=0;i<Nd;i++)
			{
				int index=iend+i+1;
				if(num[index]==0)
					break;
				digits[Nd-1-i]=num[index]-'0';
			}
		}
	}

	int Lead() const
	{
		int lead=N-1;
		for(int i=N-1;i>0;i--)
		{
			if(digits[i]==0)
				lead=i-1;
			else
				break;
		}
		return lead;
	}

	int End() const
	{
		int end=0;
		for(int i=0;i<N-1;i++)
		{
			if(digits[i]==0)
				end=i;
			else
				break;
		}
		return end;
	}

	int Shift01()
	{
		int lead=Lead();
		if(lead<Nd-1)
		{
			return Nd-lead-1;
		}
		else if(lead>Nd-1)
		{
			return Nd-lead-1;
		}
		else return 0;
	}

	int modgt(const bigint& right)const
	{
		//printf("modgt 0\n");
		for(int i=N-1;i>=0;i--)
		{
			int a=digits[i];
			int b=right.digits[i];
			//printf("modgt i=%i a=%i b=%i\n",i,a,b);
			if(a<b)
			{
				//printf("modgt 1\n");
				return 0;
			}
			else if(a>b)
			{
				//printf("modgt 2\n");
				return 1;
			}
		}
		//printf("modgt 3\n");
		return 0;
	}

	bigint operator+(const bigint& right)
	{
//		printf("op+\n");
		if(sign!=right.sign)
		{
			//printf("swap + -> -\n");
			//right.sign=-right.sign;
			bigint tmp=right;
			tmp.sign=-tmp.sign;
			//tmp.Print();
			//printf("\n");
			return *this-tmp;
		}
		bigint ret;
		ret.sign=sign;
		for(int i=0;i<N;i++)
			ret.digits[i]=0;
		int carry=0;
		for(int i=0;i<N;i++)
		{
			int a=digits[i];
			int b=right.digits[i];
			int res=a+b+carry;
			carry=0;
			if(res>9)
			{
				carry=1;
				res=res-10;
			}
			ret.digits[i]=res;
		}
		return ret;
	}

	bigint operator-(const bigint& right)
	{
//		printf("op-\n");
		if(sign!=right.sign)
		{
			//printf("swap - -> +\n");
			bigint tmp=right;
			tmp.sign=-tmp.sign;
			//tmp.Print();
			//printf("\n");
			return *this+tmp;
		}
		bigint ret;
		ret.sign=sign;
		for(int i=0;i<N;i++)
			ret.digits[i]=0;
		int carry=0;
		int swap=0;

		if(!modgt(right))
			swap=1;
		if(swap)
			ret.sign=-ret.sign;
		for(int i=0;i<N;i++)
		{
			int res;
			int a=digits[i];
			int b=right.digits[i];
			if(swap)
				res=b-a-carry;
			else
				res=a-b-carry;
			carry=0;
			if(res<0)
			{
				carry=1;
				res=res+10;
			}
			ret.digits[i]=res;
		}
		return ret;
	}

	bigint operator*(const bigint& right)
	{
		//printf("mul: ");
		//Print();
		//printf(" * ");
		//right.Print();
		//printf("\n");

		bigint ret;
		ret.Zero();
		ret.sign=sign*right.sign;

		int lead0=Lead()+1;
		int end0=End()+1;

		int lead1=right.Lead()+1;
		int end1=right.End()+1;


		if(mullog)
		{
			printf(" 1: %i-%i, 2: %i-%i\n",lead0,end0,lead1,end1);
		}

		for(int i=end0;i<lead0+1;i++)
		{
			if(mullog)
				printf("\ndigit[%i]: %i ", i, digits[i]);
			int carry=0;
			for(int j=end1;j<lead1+1;j++)
			{
				int index=i-Nd+j;
				if(index>=0)
				{
					int rd=digits[i]*right.digits[j];
					if(index>=N)
					{
						if(rd)
						{
						// overflow;
						}
					}
					else
					{
						if(rd)
						{
							if(mullog)
								printf("%i*%i=%i ",digits[i],right.digits[j],rd);
						}
						rd+=carry;
						ret.digits[index]+=rd;
						carry=ret.digits[index]/10;
						if(mullog)
							printf(" c %i ",carry);
						ret.digits[index]=ret.digits[index]%10;
					}
				}
			}
		}
		return ret;
	}

	bigint operator-()const
	{
		bigint ret=*this;
		ret.sign=-ret.sign;
		return ret;
	}

	void Mul10()
	{
		for(int i=N-1;i>0;i--)
		{
			digits[i]=digits[i-1];
		}
		digits[0]=0;
	}

	void Div10()
	{
		for(int i=0;i<N-1;i++)
		{
			digits[i]=digits[i+1];
		}
		digits[N-1]=0;
	}

	bigint operator/(const bigint& right)
	{
		bigint d=right;
		bigint n=*this;

		int newsign=sign*d.sign;

		d.sign=1;
		n.sign=1;

		int shift=d.Shift01();
		if(shift<0)
		{
			for(int i=0;i< -shift;i++)
			{
				n.Div10();
				d.Div10();
			}
		}
		else if(shift>0)
		{
			for(int i=0;i<shift;i++)
			{
				n.Mul10();
				d.Mul10();
			}
		}

		int iter=0;

		for(int i=0;i<2;i++)
		{
			int topdigit=d.digits[Nd-1];
			if(topdigit==9)
				break;
			if(topdigit==0)
			{
				bigint inf;
				inf.Sets("-99.99");
				return inf;
			}
			bigint mul;
			/* */if(topdigit==0){mul.Sets("10.0"   );}
			else if(topdigit==1){mul.Sets("5.0"    );}
			else if(topdigit==2){mul.Sets("3.33333");}
			else if(topdigit==3){mul.Sets("2.5"    );}
			else if(topdigit==4){mul.Sets("2.0"    );}
			else if(topdigit==5){mul.Sets("1.66666");}
			else if(topdigit==6){mul.Sets("1.42857");}
			else if(topdigit==7){mul.Sets("1.25"   );}
			else if(topdigit==8){mul.Sets("1.11111");}
			else if(topdigit==9){mul.Sets("1.0"    );}

			d=d*mul;
			n=n*mul;
			iter++;
		}

		while(true)
		{
			bigint two; two.Seti(2);
			bigint mul=two-d;
			d=d*mul;
			n=n*mul;
			iter++;
			if(iter>3+pow_of_2(Nd))
				break;
		}
		n.sign=newsign;
		return n;
	}

	void Print()
	{
		int end=End();
		int lead=Lead();
		if(lead<end)
		{
			printf("0.0");
		}
		if(lead<Nd)
			lead=Nd;
		if(end>Nd-2)end=Nd-2;

		char sd[N+1];
		int nc=0;
		if(sign==-1)
		{
//			printf("-");
			sd[nc++]='-';
		}
		for(int i=lead;i>end;i--)
		{
			int digit=digits[i];
			sd[nc++]="0123456789"[digit];
//			printf("%c","0123456789"[digit]);
//			printf("%c",digit+'0');
			if(i==Nd)
			{
//				printf(".");
				sd[nc++]='.';
			}
		}
		sd[nc++]=0;
		printf("%s",sd);
	}

	bigint Sqrt()
	{
		bigint a;
		a.Sets("1.0");
		bigint h;
		h.Sets("0.5");
		bigint x=*this;

		int shift=Shift01();

		if(shift<0)
			for(int i=0;i< -shift/2;i++)
				a.Mul10();
		else if(shift>0)
			for(int i=0;i< shift/2;i++)
				a.Div10();

		int cnt=2+pow_of_2(N);
		for(int i=0;i<cnt;i++)
		{
			a=(x/a+a)*h;
			printf("Sqrt approx %i=",i);
			a.Print();
			printf("\n");
		}
		return a;
	}

	// inf  1   /   4        2        1        1    \ .
	// SUM ---- | ------ - ------ - ------ - ------ | .
	// k=0 16^k \  8k+1     8k+4     8k+5     8k+6  / .

	void PI()
	{
		bigint sum;
		sum.Zero();
		bigint bi16;
		bi16.Seti(16);
		bigint pow16;
		pow16.Seti(1);
		for(int k=0;k<Nd*4/5;k++)
		{
			bigint term;
			term.Zero();

			bigint over0;
			bigint under0;
			over0.Seti(4);
			under0.Seti(8*k+1);
			term=over0/under0;

			bigint over1;
			bigint under1;
			over1.Seti(-2);
			under1.Seti(8*k+4);
			term=over1/under1+term;

			bigint over2;
			bigint under2;
			over2.Seti(-1);
			under2.Seti(8*k+5);
			term=over2/under2+term;

			bigint over3;
			bigint under3;
			over3.Seti(-1);
			under3.Seti(8*k+6);
			term=over3/under3+term;

			bigint termd16=term*pow16;
			sum=sum+termd16;
			pow16=pow16/bi16;
			sum.Print();
			printf("\n");
		}
		*this=sum;
	}

	void PI0()
	{
		bigint sum;sum.Seti(2);
		bigint nx;nx.Seti(2);
		for(int n=1;n<Nd*3;n++)
		{
			bigint top;top.Seti(2*n*n);
			bigint bottom;bottom.Seti(2*n*(2*n+1));
			nx=nx*top/bottom;
			sum=sum+nx;
			sum.Print();
			printf("\n");
		}
		*this=sum;
	}



};


int main(
#ifndef __SCINC__
int argc, char** argv
#endif
)
{
	bigint a;
	a.Sets("4");
	a.Print();
	printf("\n+\n");
	bigint b;
	b.Seti(-2);
	b.Print();
	b=b+-a;
	printf("\n=\n");
	bigint c=a/b;
	c.Print();
	printf("\n");
	b.Sets("2000");
	printf("Sqrt ");
	b.Print();
	printf("\n");
	b=b.Sqrt();
	b.Print();
	printf("\n");
	b=b*b;
	printf("Check\n");
	b.Print();
	printf("\n");
	bigint Pi;
	Pi.PI();
	bigint Pi0;
	Pi0.PI0();
	printf("Pi :");Pi.Print();printf("\n");
	printf("Pi0:");Pi0.Print();printf("\n");
	return 0;
}
