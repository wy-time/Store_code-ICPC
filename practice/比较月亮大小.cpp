#include<iostream>
using namespace std;
int main ()
{
	int n;
	int a[105];
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=0)
	{
		cout<<-1;
		return 0;
	}
	if(n!=1)
	{
		if(a[n-2]<a[n-1])
		{
			if(a[n-1]!=15)
			{
				cout<<"UP"<<endl;
			}else
				cout<<"DOWN"<<endl;
		}else
		{
			if(a[n-1]!=0)
			{
				cout<<"DOWN"<<endl;
			}else
			{
				cout<<"UP"<<endl;
			}
		}
	}else
	{
		if(a[0]==0)
			cout<<"UP"<<endl;
		else if(a[0]==15)
			cout<<"DOWN"<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
