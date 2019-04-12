#include<iostream>
using namespace std;
typedef struct
{
	int num;
	int v;
	int ip;
	int type;
}st;
bool isbuy[70];
int dp[70][33000];
int vlual[70];
int ip[70];
int main ()
{
	st info [70];
	int n,m;
	cin>>n>>m;
	int i;
	int cnt=1;
	for(i=1;i<=m;i++)
	{
		cin>>info[i].v>>info[i].ip>>info[i].type;
		if(info[i].type==0)
		{
			info[i].num=cnt;
			vlual[cnt]=info[i].v;
			ip[cnt]=info[i].ip;
			cnt++;
		}else
			info[i].num=-1;
	}
	int j=0;
	for(i=1;i<=m;i++)
	{
		for(j=n;j>=info[i].v;j--)
		{
			//if(j>=info[i].v)
		//	{
				if(info[i].type==0)
				{
					if(dp[i-1][j]<=dp[i-1][j-info[i].v]+(info[i].v*info[i].ip))
					{
						dp[i][j]=dp[i-1][j-info[i].v]+(info[i].v*info[i].ip);
						isbuy[info[i].num]=true;
					}else
						dp[i][j]=dp[i-1][j];
				}else
				{
					int temp=info[i].type;
					if(j>=info[i].v+vlual[temp])
					{
						if(isbuy[temp])
						{
							dp[i][j]=max(dp[i-1][j],dp[i-1][j-info[i].v]+info[i].v*info[i].ip);
						}else
						{
							if(dp[i-1][j]<=dp[i-1][j-info[i].v-vlual[temp]]+info[i].v*info[i].ip+vlual[temp]*ip[temp])
							{
								dp[i][j]=dp[i-1][j-info[i].v-vlual[temp]]+info[i].v*info[i].ip+vlual[temp]*ip[temp];
								isbuy[temp]=true;
							}else
								dp[i][j]=dp[i-1][j];
						}
					}else
					{
						dp[i][j]=dp[i-1][j];
					}
				}
		//	}else
				//dp[i][j]=dp[i-1][j];
		}
	}
	for(i=0;i<=n;i++)
		cout<<dp[m][i]<<endl;
	return 0;
}
