#include <stdio.h>

class Item
{
public:
	int value;
	char* name;
};

int main()
{
	Item i;
	i.value=3;
	i.name="Item 3";
	Item* pi=&i;
	printf("i.value=%i i.name=%s\n", i.value, i.name);
	pi->name="New item";
	pi->value++;
	printf("i.value=%i i.name=%s\n", i.value, i.name);
	return 0;
}

