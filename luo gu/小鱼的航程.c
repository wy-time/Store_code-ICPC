#include<stdio.h>
int main()
{
	int x,n;
	int distance =0;
	scanf("%d %d",&x,&n);
	while(n>0)
	{
		if(x==6)
		{
			n-=2;
			x=1;
		}
		if(x==7)
		{
			x=1;
			n--;
		}
		if(n<=0)
		{
			break;
		}
		distance+=250;
		x++;
		n--;
	}
	printf("%d",distance);
	return 0;
}
