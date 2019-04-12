#include<iostream>
using namespace std;
int main ()
{
	long long n;
	cin>>n;
	int i;
	for(i=2;i<=n;i++)
	{
		while(n%i==0)
		{
			cout<<i<<" ";
			n/=i;
		}
	}
	return 0;
}
