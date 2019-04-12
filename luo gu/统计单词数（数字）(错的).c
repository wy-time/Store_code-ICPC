#include<stdio.h>
#include<string.h>
int sum(char*s,int j,int *b,int*d);
int main()
{
	int c=0;
	char target[11];
	char a[1000001];
	int b[1];
	int d[1];
	int j=0;
	int cnt =0;
	gets(target);
	gets(a);
	for(;target[j]!=' '&&j<strlen(target);j++)
	{
		if(target[j]>=65&&target[j]<=90)
		{
			target[j]=(int)target[j]+32;
		}
		b[0]+=(int)target[j];
	}
	int s =b[0];
	j=0;
	while(j!=-1)
	{
		j=sum(a,j,b,d);
		if(s==b[0])
		{
			cnt++;
			if(cnt==1)
			{
				c=d[0];
			}
		}
	}
	if(cnt!=0)
	{
		printf("%d %d",cnt,c);
	}else
	{
		printf("%d",-1);
	}
	return 0;
}
int sum(char*s,int j,int *b,int *d)
{
	b[0]=0;
	d[0]=j;
	for(;s[j]!=' '&&j<strlen(s);j++)
	{
		if(s[j]>=65&&s[j]<=90)
		{
			s[j]=(int)s[j]+32;
		}
		b[0]+=(int)s[j];
	}
	j++;
	if(j==strlen(s))
	{
		j=-1;
	}
	return j;
}
