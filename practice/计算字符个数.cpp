#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main ()
{
	char s[100005];
	int i=0;
	char temp;
	while(~scanf("%c",&temp))
	{
		if(temp!='\n')
		{
			s[i]=temp;
			i++;
		}
	}
	s[i]='\0';
	int len =strlen(s);
	int cnt=0;
	for(i=0;i<len;i++)
	{
		s[i]=toupper(s[i]);
	}
	char aim=s[len-1];
	for(i=0;i<len-1;i++)
	{
		if(s[i]==aim)
			cnt++;
	}
	cout<<cnt;
	return 0;
}
