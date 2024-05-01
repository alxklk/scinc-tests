#include <stdio.h>

#define N 3
#define N1 (N+1)
#define N2 (N1/2)
#define Z(x,y) (x+1)*(y+2)
#define Y(x,y) (x-1)*(y-1)
#define W(x,y) Z(x,2)+Y(Z(y,1),Z(3,12))

#define R0(x) (x)*(x)
#define R1(x) R0(x)*R0(x)
#define R2(x) R1(x)*R1(x)
#define R3(x) R2(x)*R2(x)

#define LOG false
#define MSG0 "Log message\n"
#define MSG1 "Other log message\n"

#define LP0(x,m)
#define LP1(x,m) printf("[%s]:%s\n",(x),(m))

int main()
{
	LP0("main","some message");
	LP1("main","some message");

	if(LOG)  printf(MSG0);
	if(!LOG){printf(MSG0);}
	if(!LOG) printf(MSG0);
	if(LOG) {printf(MSG0);}
	if(LOG)  printf(MSG0);  else  printf(MSG1); 
	if(!LOG){printf(MSG0);} else {printf(MSG1);}
	if(!LOG) printf(MSG0);  else  printf(MSG1); 
	if(LOG) {printf(MSG0);} else {printf(MSG1);}
	if(LOG)  printf(MSG0);  else {printf(MSG1);} 
	if(!LOG){printf(MSG0);} else  printf(MSG1);
	if(!LOG) printf(MSG0);  else {printf(MSG1);} 
	if(LOG) {printf(MSG0);} else  printf(MSG1);


	printf("%i\n", N);
	printf("%i\n", N1);
	printf("%i\n", N2);
	printf("%i\n", Y(2,3));
	printf("%i\n", Z(2,Y(1,2)));
	printf("%i\n", W(2,3));
	printf("%i\n", W(W(2,N2),Z(1,1)));
	printf("%i\n", R3(2));
	return 0;
}