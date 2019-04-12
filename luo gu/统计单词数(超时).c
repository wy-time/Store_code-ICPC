//A~Z 65~90 a~z 97~122 空格32 
#include<stdio.h>
#include<string.h>
void space(char*t);
void change(char*s);
int main ()
{
	char target[13];
	char a[1000003];
	char*r;
	int cnt =1;
	gets(target);
	gets(a);//可以读空格 
	change(target);
	change(a);
	r=strstr(a,target);
	if(strstr(a,target)!=NULL)
	{
		int b =0;
		for(b=0;&a[b]!=r;b++)
		{
		}
		while(strstr(r+1,target)!=NULL)
		{
			cnt++;
			r=strstr(r+1,target);
		}
		printf("%d %d",cnt,b);
	}else
	{
		printf("%d",-1);
	}
	return 0;
}
void change(char*s)//大写改小写函数  并调用加空格函数 
{
	int i=0;
	for(i=0;i<strlen(s);i++)
	{
		if((int)s[i]>=65&&(int)s[i]<=90)
		{
			s[i]=(int)s[i]+32;
		}
	}
	space(s);
}
void space(char*t)//首末位加空格函数 
{
	int length=strlen(t)+3;
	char p[2]=" ";
	char q[length];
	strcpy(q,p);
	strcat(q,t);
	strcat(q,p);
	strcpy(t,q);
} 
