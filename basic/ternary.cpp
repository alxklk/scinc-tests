#include <stdio.h>

int main()
{

    for(int i=0;i<7;i++)
	{
		int x=i>=4?0:i%2?1:0;
		int y=(i>=4)?0:(i%2?1:0);
		int z=i>=4?0:i%2?1:0;
        printf("i=%i x=%i y=%i z=%i\n",i,x,y,z);
	}
    for(int i=0;i<5;i++)
    {
        int x=1;
        int y=1;
        *(i<3?&x:&y)=0;
        printf("i=%i x=%i y=%i\n",i,x,y);
    }
	int a[16];
	for(int i=0;i<16;i++)a[i]=i;
	for(int i=0;i<16;i++)a[i]=a[i]<8?0:1;
	for(int i=0;i<16;i++)printf("%i ",a[i]);
	puts("");
	for(int i=0;i<16;i++)a[i]=i<8?0:i%2?1:0;
	for(int i=0;i<16;i++)printf("%i ",a[i]);
	return 0;
}
