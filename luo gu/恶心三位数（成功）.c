#include<stdio.h>
#include<stdlib.h>
void decompose(int numer,int*a);
int compare(int *a,int *b);
int compareself(int *a);
int main ()
{
	int num1=123;
	int num2,num3;
	int *a,*b,*c;
	a= malloc(12);
	b= malloc(12);
	c= malloc(12);
	int i =0;
	int p =0,q=0;
	while(num1<333)
	{
		if(num1%10==0)
		{
			num1++;
		}
		num2=num1*2;
		num3=num1*3;
		decompose (num1,a);
		decompose (num2,b);
		decompose (num3,c);
		if(compareself (a)&&compareself (b)&&compareself (c))
		{
			p=compare (a,b);
			if(p)
			{
				p=compare (a,c);
				if(p)
				{
					p=compare(b,c);
					if(p)
					{
						printf("%d %d %d\n",num1,num2,num3);
					}
				}
			}
		}
		
		num1++;
	}
	free(a);
	free(b);
	free(c);
	return 0;
}
void decompose(int number,int*a)
{
	int j=0;
	for(j=0;j<3;j++)
	{
		a[j]=number%10;
		number/=10;
	}
}
int compare(int *a,int *b)
{
	int k =0;
	int safe =1;
	for(k=0;k<3;k++)
	{
		int l =0;
		for(l=0;l<3;l++)
		{
			if(a[k]==b[l])
			{
				safe =0;
				break;
			}
		}if(safe==0)break;
	}
	return safe;
}
int compareself(int *a)
{
	int safe =1;
	int i =0;
	for(i=0;i<3;i++)
	{
		if(a[i]==0)
		{
			safe =0;
		}
	}
	i=0;
	if(a[i]==a[i+1]||a[i]==a[i+2]||a[i+1]==a[i+2])
	{
		safe =0;
	}
	return safe;
}
