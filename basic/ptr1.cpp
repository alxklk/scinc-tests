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
	int x;
	Item* item;
};

int main()
{
	Item i0;
	Container c;
	c.item=&i0;
	c.item->val=7;
	c.item[0].name="Art";
	printf("%s %i\n",i0.name, i0.val);
	c.x=15;
	c.item->val++;
	printf("%s %i\n",i0.name, i0.val);
	return 0;
}

