#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char s[205];
	int i=0;
	char temp;
	while(~scanf("%c",&temp))
	{
		s[i]=temp;
		i++;
	}
	s[i]='\0';
	int len=strlen(s);
	int cnt=0;
	for(i=0;i<len;i++)
	{
		if(s[i]!='\n')
		{
			printf("%c",s[i]);
			cnt++;
		}else
		{
			if(cnt%8!=0)
			{
				while(cnt%8!=0)
				{
					printf("0");
					cnt++;
				}
				if(i!=len-1)
					printf("\n");
			}
			continue;
		}
		if(cnt%8==0&&i!=len-1)
		{
			printf("\n");
		}
	}
	return 0;
}
