#include<iostream>
#include<cstring>
using namespace std;
bool ans[200000];
int a[200000];
int main ()
{
	memset(ans,true,sizeof(ans));
	int i,j;
	for(i=2;i<=200000;i++)
	{
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				ans[i]=false;
				break;
			}
		}
	}
	int cnt=0;
	for (i=2;i<200000;i++)
	{
		if(ans[i])
		{
			a[cnt++]=i;
		}
	}
	int cha=0;
	int len=1;
	for(cha=2;cha<50000;cha++)
	{
		for(i=0;i<cnt;i++)
		{
			int temp=a[i];
			while(len<10)
			{
				if(ans[temp+cha])
				{
					len++;
					temp+=cha;
				}else
				{
					len=1;
					break;
				}
			}
			if(len==10)
				break;
		}
		if(len==10)
			break;
	}
	cout<<cha<<endl;
	return 0;
}
