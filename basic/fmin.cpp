#include <stdio.h>

class Item
{
public:
	float x;
	float y;
	float z;
	float w;
	char* name;
	void Init()
	{
		x=1;
		y=2;
		z=3;
		w=4;
		name="Item0";
	}
	void Increment()
	{
		x++;
		y++;
		z++;
		w++;
		name="Changed Item";
	}
};

class Container
{
public:
	char* name;
	Item* item;
	float z;
};

float tf(Container* c)
{
	return (*(*c).item).z;
}

float tfp(Container* c)
{
	Item* i=(*c).item;
	return (*i).z;
}

class cp
{
public:
	int *x;
};

int main()
{
	int x=3;
	int* px=&x;
	printf("%i\n",*px+5);


	cp pp;
	pp.x=px;
	x=1;
	printf("%i\n",x);
	pp.x=&x;
	*pp.x=2;
	printf("%i\n",x);
	*px=3;
	printf("%i\n",x);
	*(&x)=4;
	printf("%i\n",x);
	*(*(&px))=5;
	printf("%i\n",x);


	Container c;
	Item i;
	i.Init();
	c.z=-1;
	c.item=&i;
	c.name="Container1";
	printf("item.name=%s\n",i.name);
	i.Increment();
	printf("item->name=%s\n",c.item->name);
	c.item->name="Old Name";
	printf("old item->name=%s\n",c.item->name);
	c.item->Increment();
	printf("inc item->name=%s\n",c.item->name);
	c.item->name="Old Name 1";
	printf("old item->name=%s\n",c.item->name);
	(*c.item).Increment();
	printf("inc (*item).name=%s\n",c.item->name);
	float b=c.item->z+5;
	printf("b=%f\n",b);

	printf("-> : %f\n",c.item->z);
	printf("'.': %f\n",i.z);
	printf("*.: %f\n",(*c.item).z);
	printf("tfp: %f\n",tfp(&c));
	printf("tf : %f\n",tf(&c));


	return 0;
}

