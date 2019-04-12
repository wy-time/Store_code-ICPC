#include<stdio.h>
int main ()
{
	int a,b,c,d;
	int e,f;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(d<b)
	{
		c-=1;
		d+=60;
	}
	e=c-a;
	f=d-b;
	printf ("%d %d",e,f);
	return 0;
}
