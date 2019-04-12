#include<iostream>
using namespace std;
int main ()
{
	const double test=0.9999999999;
	double a;
	cin>>a;
	double t=a;
	a+=test;
	int tt=(int)a;
	if(tt-t>0.5)
	{
		cout<<(int)t;
	}else
	{
		cout<<tt;
	}
	return 0;
}
