#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	string s[1005];
	int i;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	sort(s,s+n);
	for(i=0;i<n;i++)
	{
		cout<<s[i]<<endl;
	}
	return 0;
}
