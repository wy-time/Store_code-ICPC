#include<stdio.h>
int main ()
{
	long long i=0;
	double sum=0;
	long long n=0;
	while(scanf("%lld",&n)!=EOF)
	{
		sum =0;
		for(i=1;i<=n;i++)
		{
			sum+=1.0/i;
		}
		printf("n=%lldÊ±£¬ºÍÎª%f\n",n,sum);
	}
	return 0;
}
