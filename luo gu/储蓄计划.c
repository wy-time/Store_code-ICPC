#include<stdio.h>
int main()
{
	int month =0;
	int a=0;
	int save =0;
	int i =0;
	const int max =100;
	int rest = 0;
	int z =0;
	while (month<12)
	{
		scanf("%d",&a);
		rest+=300-a;
		month++;
		if(rest>=max)
		{
			z =rest/max;
			rest-=z*max;
			save+=z*max;
		}else if(rest<0)
		{
			if(i>=0)
			{
				i=-month;
			}
		}
	}
	if(i<0)
	{
		printf("%d",i);
	}
	else
	{
		rest+=save*1.2;
		printf("%d",rest);
	}
	return 0;
}
