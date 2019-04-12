#include <iostream>
#include<algorithm>
using namespace std;
void dfs(int n,int m,int times,int sum);
int cnt;
int ans [10]={1};
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    dfs(n,m,0,0);
    cout<<cnt;
    return 0;
}
void dfs(int n,int m,int times,int sum)
{
    times++;
    int i;
    if(times==m)
    {
        for(i=ans[times-1]; i<=n; i++)
        {
            sum+=i;
            if(sum>n)
                return;
            else if(sum==n)
            {
                cnt++;
                return;
            }
            else
            {
                sum-=i;
                continue;
            }
        }
    }
    else
    {
        for(i=ans[times-1]; i<=n; i++)
        {
            sum+=i;
            if(sum>=n)
                return;
            else
            {
                ans[times]=i;
                dfs(n,m,times,sum);
                sum-=i;
            }
        }
    }
    return ;
}
