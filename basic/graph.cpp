#include <stdio.h>

float mem[256];

int main()
{
    mem[0]=5;
    mem[1]=3;
    mem[2]=4;
    mem[3]=mem[2]+mem[0]*mem[1];
    printf("%f",mem[3]);
    return 0;
}
