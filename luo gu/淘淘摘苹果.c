#include<stdio.h>
int main()
{
	int cnt=0;
	int a=0;
	int i =0;
	int b[10]={0};
	for(i=0;i<10;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&a);
	a+=30;
	for(i=0;i<10;i++)
	{
		if(b[i]<=a)
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
