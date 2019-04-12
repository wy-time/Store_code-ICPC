#include<stdio.h>
int main ()
{
	int k;
	int n=0;
	double sum =0;
	scanf("%d",&k);
	for(n=1;sum<=k;n++)
	{
		sum+=1.0/n;
	}
	printf("%d",n-1);
	return 0;
}
