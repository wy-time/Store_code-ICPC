#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	char s[20];
	cin>>s;
	int len=strlen(s);
	int i;
	for(i=len-1;i>=0;i--)
	{
		cout<<s[i];
	}
	return 0;
}
