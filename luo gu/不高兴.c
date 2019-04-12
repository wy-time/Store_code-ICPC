#include<stdio.h>
int main ()
{
	int cnt =0;
	int a,b,sum;
	int p =0;
	int i=0;
	while(cnt<7)
	{
		scanf ("%d %d",&a,&b);
		sum=a+b;
		cnt++;
		if(sum>8)
		{
			if(sum>p)
			{
				i=cnt;
				p=sum;
			}
		}
		
	}
	printf("%d",i);
	return 0;
}
