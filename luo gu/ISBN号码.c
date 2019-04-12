#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int decompose (int number,int i,int j[]);
int main()
{
	char a[14]="0-000-00000-0";
	int b =0;
	int i =0;
	int sum =0;
	int j[10];//用来存单个的数 
	for(i=0;i<10;i++)
	{
		j[i]=1;
	}
	i=0;
	scanf("%s",a);
	char*p=strchr(a,'0');
	while(p!=NULL)//一个整数开头为0的特殊情况 
	{
		if(p==&a[2])
		{
			j[1]=0;
			if(a[3]=='0')
			{
				j[2]=0;
				if(a[4]=='0')
				{
					j[3]=0;
				}
			}
		}
		if(p==&a[6])
		{
			j[4]=0;
			if(a[7]=='0')
			{
				j[5]=0;
				if(a[8]=='0')
				{
					j[6]=0;
					if(a[9]=='0')
					{
						j[7]=0;
						if(a[10]=='0')
						{
							j[8]=0;
						}else break;
					}else break;
				}else break;
			}else break;
		}
		p=strchr(p+1,'0');
	}
	char *c=strchr(a,'X');//字符串中有X的特殊情况 
	if(c!=NULL)
	{
		*(c-1)='\0';
		j[9]=10;
	}
	b=atoi(a);//将字符串转化成数字 
	i=decompose(b,i,j);
	c=strchr(a,'-');
	b=atoi(c+1);
	i=decompose(b,i,j);
	while(strchr(c+1,'-')!=NULL)
	{
		c=strchr(c+1,'-');
		b=atoi(c+1);
		i=decompose(b,i,j);
	}
	for(i=0;i<9;i++)
	{
		sum+=(j[i]*(i+1));
	}
	a[11]='-';//防止有X的特殊情况使字符串变小 
	if(sum%11==j[9])
	{
		printf("Right");
	}else if(sum%11==10)
	{
		a[12]='X';
		printf("%s",a);
	}else
	{
		int q=(sum%11)+48;//通过ASCII码讲数字转成字符串，0的ASCII码是48，到9依次加1 
		a[12]=q;
		printf("%s",a);
	} 
	return 0;
}
int decompose (int number,int i,int j[])
{
	int safe =1;
	int s[6]={1,1,1,1,1,-1};
	int k =0;
	if(number==0&&(i==0||i==9))
	{
		safe =0;
		j[i]=0;
		i++;
	}
	if(number==0&&i!=0&&i!=9&&safe)
	{
		if(i==1)
		{
			i=4;
			goto end;
		}
		if(i==4)
		{
			i==9;
		}
	}
	while(number>0)
	{
		while(j[i]==0)
		{
			i++;
		}
		s[k]=number%10;
		number/=10;
		k++;
		s[5]=1;
	}if(s[5]==1)
	{
		for(k-=1;k>=0;k--)
		{
			j[i]=s[k];
			i++;//把逆序的整数弄正 
		}
	}
end:
	return i;
}
