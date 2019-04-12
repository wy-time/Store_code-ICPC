#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main ()
{
	char s[10005];
	while(~scanf("%s",s))
	{
		//int len=strlen(s);
		//int i;
		long long ans=0;
		sscanf(&s[2],"%x",&ans);
		printf("%lld\n",ans);
		/*for(i=len-1;i>=2;i--)
		{
			if(s[i]>'9')
			{
				ans[j]=s[i]-'A'+10;
			}else
			{
				ans[j]=s[i]-'0';
			}
			j++;
		}
		int jing=0;
		for(i=0;i<j;i++)
		{
			ans[i]+=jing;
			jing=0;
			while(ans[i]>=10)
			{
				jing+=ans[i]/10;
				ans[i]%=10;
			}
		}
		if(jing!=0)
		{
			ans[i]=jing;
			i++;
		}
		for(i-=1;i>=0;i--)
		{
			printf("%d",ans[i]);
		}
		printf("\n");*/
	}
	return 0;
}
