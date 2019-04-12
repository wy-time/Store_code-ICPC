#include<stdio.h>
#define LEAP_YEAR(y) if(y%4==0&&y%100!=0) i=1;\
else if(y%400==0) i=1;
int main ()
{
	int y;
	int i=0;
	scanf("%d",&y);
	LEAP_YEAR(y);
	if(i)
	{
		printf("L");
	}else
	{
		printf("N");
	}
	return 0;
}
