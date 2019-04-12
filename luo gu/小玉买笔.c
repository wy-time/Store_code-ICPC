#include<stdio.h>
int main()
{
	int a,b;
	int have=0;
	scanf("%d %d",&a,&b);
	have =a*10+b;
	have/=19;
	printf("%d",have);
	return 0;
}
