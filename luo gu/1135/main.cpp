#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
void bfs(int*att,int a,int b,int n);
int ans[205];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,a,b;
    memset(ans,-1,sizeof(ans));
    cin>>n>>a>>b;
    int att[205];
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>att[i];
    }
    bfs(att,a,b,n);
    cout<<ans[b];
    return 0;
}
void bfs(int*att,int a,int b,int n)
{
    queue<int>qu;
    qu.push(a);
    ans[a]=0;
    while(!qu.empty())
    {
        a=qu.front();
        qu.pop();
        int dx[2]={-1,1};
        int i;
        for(i=0;i<2;i++)
        {
            int a1=a+dx[i]*att[a];
            if(a1>0&&a1<=n&&ans[a1]==-1)
            {
                ans[a1]=ans[a]+1;
                if(a1==b)
                    return ;
                qu.push(a1);
            }
        }
    }
}
