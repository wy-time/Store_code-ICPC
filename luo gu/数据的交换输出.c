#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n=0;
	int i=0;
	int *a;
	int t=0;
	int k=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			break;
		}
		k=0;
		a=malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		t=a[0];
		for(i=1;i<n;i++)
		{
			if(t>a[i])
			{
				t=a[i];
				k=i;
			}
		}
		a[k]=a[0];
		a[0]=t;
		for(i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[i]);
		free(a);
	}
	return 0;
}
