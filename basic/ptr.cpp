#include <stdio.h>

class Item
{
public:
	char* name;
	int val;
};

class Container
{
public:
	Item* item;
};

int main()
{
	Item i0;
	i0.val=222;
	i0.name="Item0";
	Item i1;
	i1.val=111;
	i1.name="Item1";
	Container c;
	c.item=&i0;
	c.item->val=777;
	char* cname="Cont item0";
	c.item->name=cname;
	printf("0. %s %i\n",c.item->name, c.item->val);
	c.item=&i1;
	c.item->val=888;
	c.item->name="Cont item1";
	printf("1. %s %i\n",c.item->name, c.item->val);
	c.item->name="Cont item1";
	c.item->val++;
	printf("1. %s %i\n",c.item->name, c.item->val);
	return 0;
}

