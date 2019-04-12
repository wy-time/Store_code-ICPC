#include<stdio.h>
int main()
{
	int a;
	double b;
	scanf("%d",&a);
	if(a>400)
	{
		b=150*0.4463+250*0.4663;
		a-=400;
		b+=a*0.5663;
	}else if(a>150)
	{
		b=150*0.4463;
		a-=150;
		b+=a*0.4663;
	}else 
	{
		b=a*0.4463;
	}
	printf("%.1f",b);
	return 0;
}
