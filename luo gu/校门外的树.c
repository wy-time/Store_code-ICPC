#include<stdio.h>
int main()
{
	int L,M;
	int i=0;
	int j,k;
	int cnt =0;
	scanf("%d %d",&L,&M);
	int a[L+1];
	for(i=0;i<L+1;i++)
	{
		a[i]=1;
	}
	for(i=0;i<M;i++)
	{
		scanf("%d %d",&j,&k);
		for(;j<=k;j++)
		{
			a[j]=0;
		}
	}
	for(i=0;i<L+1;i++)
	{
		if(a[i])
		{
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
