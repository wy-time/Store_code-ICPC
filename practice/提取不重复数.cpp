#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int a[15];
	int cnt=0;
	bool is[10]={false};
	while(n)
	{
		a[cnt]=n%10;
		n/=10;
		cnt++;
	}
	int i;
	for(i=0;i<cnt;i++)
	{
		if(!is[a[i]])
		{
			cout<<a[i];
			is[a[i]]=true;
		}
	}
	return 0;
}
