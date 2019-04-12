#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
char s[50005][105];
void del();
int main ()
{
	char temp;
	int i=0,j=0;
	int cnt=0;
	int ans[2]={0};
	while(~scanf("%c",&temp))
	{
		if(temp!='\n')
		{
			if(temp!=';')
			{
				if(j>=3)
				{
					del();
					j=0;
					cnt=0;
					continue;
				}else
				{
					if(isalpha(temp))
						cnt++;
					if(cnt>=2)
					{
						del();
						j=0;
						cnt=0;
						continue;
					}
					s[i][j]=temp;
					j++;
				}
			}else
			{
				if(j<2)
				{
					j=0;
					cnt=0;
					continue;
				}
				s[i][j]='\0';
				i++;
				j=0;
				cnt=0;
			}
		}else
		{
			j=i;
			for(i=0;i<j;i++)
			{
				if(isalpha(s[i][0]))
				{
					switch (s[i][0])
					{
						case 'A':
							ans[0]-=atoi(&s[i][1]);
							break;
						case 'D':
							ans[0]+=atoi(&s[i][1]);
							break;
						case 'W':
							ans[1]+=atoi(&s[i][1]);
							break;
						case 'S':
							ans[1]-=atoi(&s[i][1]);
							break;
						default:
							continue;
					}
				}
			}
			printf("%d,%d\n",ans[0],ans[1]);
			memset(s,0,sizeof(s));
			i=0,j=0,cnt=0;
			ans[0]=ans[1]=0;
			continue;
		}
	}
	return 0;
}
void del()
{
	while(getchar()!=';');
}
