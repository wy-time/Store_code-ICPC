#include <iostream>
#include<cstring>
using namespace std;
bool dfs(int n,int step,int sum,int tsum);
int ans[20][20];
bool use[20];
int r[20];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,sum;
    cin>>n>>sum;
    ans[0][0]=1;
    int i;
    for(i=1;i<16;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
                ans[i][j]=1;
            else
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    if(n>=1)
    {
        if(dfs(n,0,sum,0))
        {
            for(i=0;i<n-1;i++)
                cout<<r[i]<<" ";
            cout<<r[i];
        }
    }
    return 0;
}
bool dfs(int n,int step,int sum,int tsum)
{
    if(step==n-1)
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(!use[i])
            {
                tsum+=ans[n-1][step]*i;
                if(tsum==sum)
                {
                    r[step]=i;
                    return true;
                }else
                    return false;
            }
        }
    }else
    {
        int i;
        for(i=1;i<=n;i++)
        {
            if(!use[i])
            {
                tsum+=ans[n-1][step]*i;
                use[i]=true;
                if(dfs(n,step+1,sum,tsum))
                {
                    r[step]=i;
                    return true;
                }
                else
                {
                    use[i]=false;
                    tsum-=ans[n-1][step]*i;
                }
                if(tsum>=sum)
                    return false;
            }
        }
    }
    return false;
}
