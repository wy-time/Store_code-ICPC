#include<iostream>
#include<cstring>
#include<cstdio>
char s[100005][30];
using namespace std;
int main ()
{
	
	int i=0;
	while(~scanf("%s",&s[i]))
		i++;
	for(i-=1;i>0;i--)
	{
		printf("%s ",s[i]);
	}
	printf("%s",s[i]);
	return 0;
}
