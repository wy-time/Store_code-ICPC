#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int a[n];
	int b[n];
	b[0]=0;
	int t =0;
	int i =0;
	int j =0;
	int cnt =0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		cnt =0;
		t=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]<t)
			{
				cnt++;
			}
		}
		b[i]=cnt;
	}
	for(i=0;i<n;i++)
	{
		printf("%d",b[i]);
		if(i!=n-1)
		{
			printf(" ");
		}
	}
	return 0;
}
