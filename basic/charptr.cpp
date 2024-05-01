#include <stdio.h>

class Item
{
public:
	char* name;
	void Update(int i)
	{
		name[i]=name[i]+1;
		name[i+1]=65+i;
	}
};

char ar[16];

int main()
{
	for(int i=0;i<15;i++)
	{
		ar[i]='a'+i;
	}
	ar[15]=0;
	Item i0;
	i0.name=&ar[0];
	i0.Update(6);
	i0.Update(1);
	printf("%s\n",ar);
	printf("%s\n",i0.name);
	return 0;
}

