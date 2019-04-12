#include<iostream>
using namespace std;
int a[8]={0,1,2,3,4,5,6,7};
bool use[10];
void dfs (int sum,int step);
int cnt;
bool isprime(int n);
int main()
{
	dfs(0,1);
	cout<<cnt;
	return 0;
}
void dfs (int sum,int step)
{
	int i=0;
	if(step==8)
	{
		for(i=0;i<8;i++)
		{
			if(!use[i])
				sum=sum*10+a[i];
		}
		if(isprime(sum))
		{
			cnt++;
			cout<<sum<<endl;
		}
	}else 
	{
		for(i=0;i<8;i++)
		{
			if(!use[i])
			{
				if(a[i]==0&&step==1)
				{
					continue;
				}
				sum=sum*10+a[i];
				use[i]=true;
				dfs(sum,step+1);
				use[i]=false;
				sum-=a[i];sum/=10;
			}
		}
	}
}
bool isprime(int n)
{
	int i;
	bool flag=true;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			flag=false;
			break;
		}
	}
	return flag;
}
