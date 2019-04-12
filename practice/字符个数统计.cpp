#include<iostream>
#include<cstdio>
using namespace std;
int main ()
{
	bool is[128]={false};
	char temp;
	int cnt=0;
	while(~scanf("%c",&temp))
	{
		if(temp>=0&&temp<=127&&!is[temp]&&temp!='\n')
		{
			cnt++;
			is[temp]=true;
		}
	}
	printf("%d",cnt);
	return 0;
}
