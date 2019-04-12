#include<stdio.h>
void solve (int a);
int main ()
{
	int n;
	scanf("%d",&n);
	solve(n);
	return 0;
}
void solve (int a)
{
	int i=0;
	for(i=1000;i>=10;i/=10)
	{
		printf("%d ",a/i);
		a%=i;
	}
	printf("%d",a);
}
