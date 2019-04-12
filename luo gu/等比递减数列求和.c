#include<stdio.h>
int main()
{
	double x=0.0;
	double sum =0.0;
	int cnt =1;
	int i =0;
	const double s =0.98;
	scanf("%lf",&x);
	while(sum<x)
	{
		double t =1.0;
		for(i=0;i<cnt;i++)
		{
			t*=s;
		}
		sum=(2*(1-t))/(1-s);
		cnt++;
	}
	printf("%d",cnt-1);
	return 0;
}
