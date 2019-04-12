#include<stdio.h>
int main ()
{
	int n=0;
	int i =0;
	int c=0;
	scanf("%d",&n);
	while(n!=0)
	{
		i=n%10;
		c=c*10+i;
		n/=10;
	}
	printf("%d",c);
	return 0;
}
