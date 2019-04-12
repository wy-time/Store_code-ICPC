#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
	int n;
	while(cin>>n&&n)
	{
		int i;
		int cnt=0; 
		int a[10005];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cnt=0;
			bool wanquan=false;
			if(a[i]==1)
			{
				cout<<1<<endl;
				continue;
			}
			else 
			{
				double t=sqrt(a[i]);
				if(t-(int)t==0)
				{
					wanquan=true;
				}
			}
			for(int j=1;j*j<a[i];j++)
			{
				if(a[i]%j==0)
				{
					cnt++;
				}
			}
			cnt*=2;
			if(wanquan)
				cnt++;
			cout<<cnt<<endl;
		}
	}
	return 0;
}
