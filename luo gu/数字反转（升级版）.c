#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void declare (char *s,char*t);
int change(int len,int l,char*t,char*s);
int main ()
{
	char s[23];
	char *t;
	while(scanf("%s",s)!=EOF)
	{
		int j=0;
		int i=0;
		int len=strlen(s);
		int l=0;
		if(strchr(s,'%')!=NULL)
		{
			if(s[0]=='0')
			{
				printf("0%\n");
				continue;
			}
			t=malloc(len*sizeof(char)+1);
			l=len-2;
			j=change(len,l,t,s);
			t[len-1]=s[len-1];
			for(i=j;i<len;i++)
			{
				printf("%c",t[i]);
			}free(t);
			printf("\n");
			continue;
		}else if(strchr(s,'/')!=NULL)
		{
			char*p=strchr(s,'/');
			*p='\0';
			declare(s,t);
			printf("/");
			declare(p+1,t);
			printf("\n");
			continue;
		}else if(strchr(s,'.')!=NULL)
		{
			char*p=strchr(s,'.');
			*p='\0';
			declare(s,t);
			printf(".");
			int k=atoi(p+1);//讲0000xxxxx变成xxxx
			sprintf(p+1,"%d",k);//将数字转化回字符串 
			declare(p+1,t);
			printf("\n");
			continue;
		}else
		{
			declare(s,t);
			printf("\n");
			continue;
		}
	}
	return 0;
} 
int change(int len,int l,char*t,char*s)
{
	int i=0;
	int j=0;
	for(i=0;i<len;i++)
	{
		if((int)s[l-i]==48)
		{
			j++;
		}else
		{
			break;
		}
	}
	for(i=0;i<=len-1;i++)
	{
		t[i]=s[l-i];
	}
	return j;
}
void declare (char *s,char*t)
{
	int i;
	int len;
	int l;
	int j;
	len=strlen(s);
	t=malloc(len*sizeof(char)+1);
	l=len-1;
	j=change(len,l,t,s);
	if(j==len)
	{
		printf("0");
	}
	for(i=j;i<len;i++)
	{
		printf("%c",t[i]);
	}
	free(t);
}
