#include<stdio.h>
int main()
{
	const int num =102;
	int a[num];
	int i =0;
	for(i=0;i<num;i++)
	{
		a[i]=1;
	}
	for(i=1;a[i-1]!=0;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i-=2;i>=1;i--)
	{
		printf("%d",a[i]);
		if(i!=1)
		{
			printf(" ");
		}
	}
	return 0;
} 
