#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
	int a[101][101];
	int i,j;
	int cnt=1;
	for(i=0;i<101;i++)
	{
		for(j=0;j<101;j++)
		{
			a[i][j]=cnt;
			cnt++;
		}
	}
	int sum=0;
	for(i=0;i<101;i++)
	{
		int t =abs(50-i);
		int cnt=101-2*t;
		for(j=0;j<101;j++)
		{
			if(j>=t&&cnt)
			{
				sum+=a[i][j];
				cnt--;
			}
			if(cnt==0)
				break;
		}
	}
	cout<<sum;
	return 0;
}
