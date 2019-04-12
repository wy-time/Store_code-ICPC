#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f;
int main ()
{
	char s[5005];
	gets(s);
	int len=strlen(s);
	int i;
	int cnt=0;
	for(i=len-1;i>=0;i--)
	{
		if(s[i]!=' ')
			cnt++;
		else
			break;
	}
	cout<<cnt;
	return 0;
}
