/*#include<stdio.h>
int main ()
{
	int i =0;
	int j =0;
	int k =0;
	int num1,num2,num3=0;
	int lock1=1;
	int lock2=1;
	int exit =0;
	for(i=1;i<10;i++)
	{
		exit=0;
		for(j=1;j<10;j++)
		{
			if(j==i)
			{
				j+=1;
			}
			for(k=1;k<10;k++)
			{
				while(k==i||k==j)
				{
					k+=1;
				}
				if(lock1)
				{
					num1=i*100+j*10+k;
					lock1 =0;
					lock2=1;
				}
				if(lock2)
				{
					num2=i*100+j*10+k;
					if(num2==num1*2)
					{
						lock2=0;
					}
				}
				if(lock2==0)
				{
					num3=i*100+j*10+k;
					if(num3==3*num1)
					{
						printf("%d %d %d",num1,num2,num3);
						num3=987;
					}
				}
				if(num3==987)
				{
					num3=0;
					lock2 =1;
					num1++;
					if(num1%10==0)
					{
						num1++;
					}
					if(num1>333)
					{
						goto end;
					}
					i=0;
					j=1;
					k=1;
					exit=1;
					break;
				}
			}if(exit) break;
		}
	}
end:
	return 0;
}*///¥Û ß∞‹
 
