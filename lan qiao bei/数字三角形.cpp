#include<iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int i,j;
	int a[105][105];
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];
		}
	}
	cout<<a[0][0];
	return 0;
}
