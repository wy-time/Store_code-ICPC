#include<stdio.h>
#include<string.h>
void change(char*s,int length);
int main()
{
	int safe =1;
	int i=0;
	int j =0;
	int d=0;
	int cnt =0;
	char target[11];
	char a[1000001];
	char a1[1];
	gets(target);
	gets(a);
	int tlen=strlen(target);
	int alen=strlen(a);
	change(target,tlen);
	change(a,alen);
	a1[0]=target[0];
	for(i=0;i<alen-tlen;i++)
	{
		safe=1;
		if(a[i]==a1[0])
		{
			if(i==0||a[i-1]==' ')
			{
				for(j=1;j<tlen;j++)
				{
					if(target[j]!=a[i+j])
					{
						safe=0;
						break;
					}
				}
				if(safe)
				{
					if(i+tlen==alen||a[i+tlen]==' ')
					{
						cnt++;
						if(cnt==1)
						{
							d=i;
						}
					}
				}
			}
		}
	}
	if(cnt==0)
	{
		printf("%d",-1);
	}else
	{
		printf("%d %d",cnt,d);
	}
	return 0;
}
void change(char*s,int length)//大写改小写函数 
{
	int i=0;
	for(i=0;i<length;i++)
	{
		if((int)s[i]>=65&&(int)s[i]<=90)
		{
			s[i]=(int)s[i]+32;
		}
	}
}

