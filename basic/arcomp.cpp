#include <stdio.h>

int main()
{
	int s0[10];
	for(int i=0;i<10;i++)
		s0[i]='a'+i;
	char* s1="0121234652214";
	for(int i=0;i<10;i++)
	{
		if(s1[i]=='2')
			printf("-%c-",s0[i]);
		printf("%c",s0[s1[i]-'0']);
	}
	return 0;
}
