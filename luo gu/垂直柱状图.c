#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main ()
{
	char s[288][27]={" "};
	char c[73];
	int i=0;
	int j=0;
	int k=0;
	int acc =0;
	int a[26]={0};
	char *p;
	for(i=0;i<4;i++)
	{
		gets(c);
		int len =strlen(c);
		p=malloc(len*sizeof(char)+1);
		for(j=0;j<26;j++)
		{
			s[286][j]=(j+65);
		}
		for(j=0;j<26;j++)//A=65,Z=90
		{
			int cnt =0;
			p=strchr(c,j+65);
			while(p!=NULL&&*p!='\0')
			{
				p=strchr(p,j+65);
				if(p==NULL)
				{
					break;
				}
				cnt++;
				p+=1;
			}
			a[j]+=cnt;
		}
		free(p);
	}
	for(i=0;i<26;i++)
	{
		if(a[i]>acc)
		{
			acc=a[i];
		}
	}
	for(j=0;j<26;j++)
	{
		for(k=a[j];k>0;k--)
		{
			s[286-k][j]='*';
		}
	}
	for(i=acc;i>=0;i--)
	{
		for(j=0;j<26;j++)
		{
			printf("%c",s[286-i][j]);
			if(j!=25&&i!=0)
			{
				k=0;
				int l;
				for(l=j+1;l<26;l++)
				{
					if(s[286-i][l]=='*')
					{
						printf(" ");
						k=1;
						break;
						
					}
				}
				if(k==0)
				{
					printf("\n");
					break;
				}
			}
			if(j==25)
			{
				printf("\n");
			}else if(i==0)
			{
				printf(" ");
			}
		}
	}
	return 0;
}
